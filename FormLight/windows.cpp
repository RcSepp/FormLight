#ifdef _WIN32

#include <Windows.h>
#include <string>
#include <set>
#include <list>
#include "platform.h"

#include <windowsx.h>

#include <Dwmapi.h>
#pragma comment (lib, "Dwmapi.lib")

HINSTANCE instance;

LRESULT CALLBACK WndProc(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)
{
	instance = hInstance;

	int argc;
	char **argv;

	// Use the CommandLine functions to get the command line arguments.
	// Unfortunately, Microsoft outputs
	// this information as wide characters for Unicode, and we simply want the
	// Ascii version to be compatible
	// with the non-Windows side.  So, we have to convert the information to
	// Ascii character strings.
	LPWSTR *commandLineArgs = CommandLineToArgvW(GetCommandLineW(), &argc);
	if (nullptr == commandLineArgs) {
		argc = 0;
	}

	if (argc > 0) {
		argv = (char **)malloc(sizeof(char *) * argc);
		if (argv == nullptr) {
			argc = 0;
		}
		else {
			for (int iii = 0; iii < argc; iii++) {
				size_t wideCharLen = wcslen(commandLineArgs[iii]);
				size_t numConverted = 0;

				argv[iii] = (char *)malloc(sizeof(char) * (wideCharLen + 1));
				if (argv[iii] != nullptr) {
					wcstombs_s(&numConverted, argv[iii], wideCharLen + 1,
						commandLineArgs[iii], wideCharLen + 1);
				}
			}
		}
	}
	else {
		argv = nullptr;
	}

	int result = _main(argc, argv);

	// Free up the items we had to allocate for the command line arguments.
	if (argc > 0 && argv != nullptr) {
		for (int iii = 0; iii < argc; iii++) {
			if (argv[iii] != nullptr) {
				free(argv[iii]);
			}
		}
		free(argv);
	}

	return result;
}

bool work()
{
	static MSG uMsg = {0};
	if (PeekMessage(&uMsg, NULL, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&uMsg);
		DispatchMessage(&uMsg);
	}

	if (uMsg.message == WM_QUIT)
	{
		PostQuitMessage(0); // Repost quit message to finish all pending waits
		return false;
	}
	else
		return true;
}

bool wait()
{
	static MSG uMsg = {0};
	if(GetMessage(&uMsg, NULL, 0, 0))
	{
		TranslateMessage(&uMsg);
		DispatchMessage(&uMsg);
	}

	if (uMsg.message == WM_QUIT)
	{
		PostQuitMessage(0); // Repost quit message to finish all pending waits
		return false;
	}
	else
		return true;
}

void wakeup()
{
	PostMessage(0, 0, 0, 0);
}

void error(std::string text)
{
	MessageBox(NULL, text.c_str(), "Error", MB_OK | MB_ICONERROR);
}


#define DEFAULT_WINDOWCLASS "DefaultWinClass"
std::set<std::string> winclasses;
bool winclassregistered(const std::string& classname)
{
	return winclasses.find(classname) != winclasses.end();
}
void unregisterwinclass(const std::string& classname)
{
	UnregisterClass(classname.c_str(), instance);
	winclasses.erase(classname);
}
bool registerwinclass(const std::string& classname, HBRUSH bgbrush = 0, bool ismdichildclass = false, HICON icon = NULL, HICON icon_small = NULL)
{
	if (winclassregistered(classname))
		return true;

	unregisterwinclass(classname);

	WNDCLASSEX winClass;
	winClass.cbSize = sizeof(WNDCLASSEX);
	winClass.lpszClassName = classname.c_str();
	winClass.lpfnWndProc = WndProc;
	winClass.style = bgbrush ? CS_VREDRAW | CS_HREDRAW : NULL;
	winClass.hInstance = instance;
	winClass.hIcon = icon;
	winClass.hIconSm = icon_small;
	winClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	winClass.hbrBackground = bgbrush;
	winClass.lpszMenuName = NULL;
	winClass.cbClsExtra = 0;
	winClass.cbWndExtra = 0;

	if (!RegisterClassEx(&winClass))
		return false;

	winclasses.insert(classname);
	return true;
}

class WinWindow : public OSWindow
{
private:
	bool visible;
	HWND handle;
	std::string caption;
	WinWindow* parent;
	std::list<WinWindow*> children;
	WindowState oldwndstate;
	struct MouseTracker
	{
		TRACKMOUSEEVENT tracker;
		bool enabled;

		MouseTracker() : enabled(false)
		{
			tracker.cbSize = sizeof(TRACKMOUSEEVENT);
			tracker.dwFlags = TME_LEAVE;
			tracker.hwndTrack = NULL;
		}
		void Init(HWND parentwnd) { tracker.hwndTrack = parentwnd; }
	} tracker;

public:
	~WinWindow()
	{
		for (std::list<Timer*>::iterator timer = timers.begin(); timer != timers.end(); timer++)
			delete *timer;
		timers.clear();
	}
	const HWND gethandle() { return handle; }
	std::string init(const OSWindow::Settings& settings)
	{
		this->caption = settings.caption;
		this->visible = true;
		this->parent = (WinWindow*)settings.parent;
		this->oldwndstate = settings.wndstate;

		int captionheight = settings.fbstyle & WS_THICKFRAME && !(settings.options & FS_MDICHILD) ? GetSystemMetrics(SM_CYCAPTION) : GetSystemMetrics(SM_CYSMCAPTION);
		int totalwidth = settings.clientsize_width + 2 * GetSystemMetrics(SM_CXSIZEFRAME);
		int totalheight = settings.clientsize_height + 2 * GetSystemMetrics(SM_CYSIZEFRAME) + captionheight;

		int windowpos_x = settings.windowpos_x, windowpos_y = settings.windowpos_y;
		if (settings.options & FS_CENTERTOSCREEN)
		{
			windowpos_x = (GetSystemMetrics(SM_CXSCREEN) - totalwidth) / 2;
			windowpos_y = (GetSystemMetrics(SM_CYSCREEN) - totalheight) / 2;
		}
		else if (settings.fbstyle == FBS_NOBORDER)
		{
			// Adjust for clipped border
			windowpos_x -= GetSystemMetrics(SM_CXFIXEDFRAME);
			windowpos_y -= GetSystemMetrics(SM_CYFIXEDFRAME) + GetSystemMetrics(SM_CYCAPTION);
		}

		if (!registerwinclass(DEFAULT_WINDOWCLASS/*, (HBRUSH)COLOR_WINDOW*/))
			return "Error registering window class";

		DWORD styles = settings.fbstyle | WS_MINIMIZEBOX | WS_MAXIMIZEBOX |
			(settings.wndstate == WS_MINIMIZED) * WS_MINIMIZE | (settings.wndstate == WS_MAXIMIZED) * WS_MAXIMIZE |
			(settings.hasvscroll == true) * WS_VSCROLL | (settings.hashscroll == true) * WS_HSCROLL;
		if (settings.options & FS_MDICHILD)
		{
			if (!settings.parent)
				return "Parameter 'parent' not specified";

			if (windowpos_x == -1) windowpos_x = CW_USEDEFAULT;
			if (windowpos_y == -1) windowpos_y = CW_USEDEFAULT;
			if (settings.clientsize_width == -1) totalwidth = CW_USEDEFAULT;
			if (settings.clientsize_height == -1) totalheight = CW_USEDEFAULT;

			handle = CreateWindowEx(WS_EX_MDICHILD | (WS_EX_TOOLWINDOW * settings.istoolwindow), DEFAULT_WINDOWCLASS, settings.caption.c_str(), WS_VISIBLE | WS_CHILD | styles, windowpos_x,
				windowpos_y, totalwidth, totalheight, NULL/*((WinWindow*)settings.parent)->mdiclienthandle*/, NULL, instance, NULL);
		}
		else
			handle = CreateWindowEx(WS_EX_TOOLWINDOW * settings.istoolwindow, DEFAULT_WINDOWCLASS, settings.caption.c_str(), WS_CLIPCHILDREN | styles, windowpos_x,
				windowpos_y, totalwidth, totalheight, settings.parent ? ((WinWindow*)settings.parent)->handle : NULL, NULL, instance, NULL);

		if (!handle)
		{
			char buf[256];
			_itoa_s((int)GetLastError(), buf, 10);
			return std::string("Error creating form: error code = ") + std::string(buf);
		}

		// Fix bug in CreateWindowEx size calculation on DWM-based desktops
		RECT rc;
		DwmGetWindowAttribute(handle, DWMWA_EXTENDED_FRAME_BOUNDS, &rc, sizeof(RECT));
		if (rc.right - rc.left != settings.clientsize_width || rc.bottom - rc.top - captionheight != settings.clientsize_height)
			SetWindowPos(handle, 0, 0, 0, 2 * (rc.right - rc.left) - settings.clientsize_width, 2 * (rc.bottom - rc.top) - captionheight - settings.clientsize_height, SWP_NOZORDER | SWP_NOMOVE);

		tracker.Init(handle);

		if (settings.fbstyle == FBS_NOBORDER)
		{
			// Clip window frame
			HRGN hrgn = CreateRectRgn(GetSystemMetrics(SM_CXFIXEDFRAME), GetSystemMetrics(SM_CYFIXEDFRAME) + GetSystemMetrics(SM_CYCAPTION),
				GetSystemMetrics(SM_CXFIXEDFRAME) + settings.clientsize_width,
				GetSystemMetrics(SM_CYFIXEDFRAME) + GetSystemMetrics(SM_CYCAPTION) + settings.clientsize_height);
			SetWindowRgn(handle, hrgn, TRUE);
		}

		/*// Create MDI client area
		if (settings.options & FS_MDICLIENT)
		{
			CLIENTCREATESTRUCT clientcreatestruct;
			clientcreatestruct.idFirstChild = 100;
			if (settings.mdiwindowmenu)
			{
				MenuItem* newmenuitem;
				CHKALLOC(newmenuitem = new MenuItem(NULL, NULL, IMenuItem::MI_DROPDOWN_STATIC));
				newmenuitem->clickcbk = NULL;
				newmenuitem->clickcbkuser = NULL;
				*settings.mdiwindowmenu = newmenuitem;
				clientcreatestruct.hWindowMenu = newmenuitem->GetSubMenuHandle();
			}
			else
				clientcreatestruct.hWindowMenu = NULL;
			mdiclienthandle = CreateWindowEx(0, "MDICLIENT", NULL, WS_CHILD | WS_CLIPCHILDREN, 0, 0, 0, 0, handle, NULL, instance, &clientcreatestruct);

			if (!mdiclienthandle)
				return ERR("Error creating mdi client area");

			ShowWindow(mdiclienthandle, SW_SHOW);

			SetWindowPos(mdiclienthandle, NULL, 0, 0, settings.clientsize_width, settings.clientsize_height, SWP_NOMOVE | SWP_NOZORDER);
		}*/

		if (settings.wndstate == WS_MINIMIZED || settings.wndstate == WS_MAXIMIZED)
		{
			WINDOWPLACEMENT wp = { 0 };
			wp.length = sizeof(WINDOWPLACEMENT);
			GetWindowPlacement(handle, &wp);
			wp.showCmd = SW_HIDE;
			wp.rcNormalPosition.left = windowpos_x;
			wp.rcNormalPosition.top = windowpos_y;
			wp.rcNormalPosition.right = wp.rcNormalPosition.left + totalwidth;
			wp.rcNormalPosition.bottom = wp.rcNormalPosition.top + totalheight;
			SetWindowPlacement(handle, &wp);
		}

		if (parent)
		{
			// Report this window as child of settings.parent
			parent->children.push_back(this);

			if (!(settings.options & FS_MDICHILD))
			{
				// Directly display dialog windows, disabling the parent window beneath
				show();
				EnableWindow(parent->handle, false);
			}
		}

		return "";
	}
	void show()
	{
		visible = true;

		if (!handle)
			return;

		WINDOWPLACEMENT wp;
		GetWindowPlacement(handle, &wp);

		int cmdshow;
		if (wp.showCmd == SW_SHOWMAXIMIZED)
			cmdshow = SW_MAXIMIZE;
		else if (wp.showCmd == SW_SHOWMINIMIZED)
			cmdshow = SW_MINIMIZE;
		else
			cmdshow = SW_RESTORE;
		ShowWindow(handle, cmdshow);
	}
	void hide()
	{
		visible = false;

		if (handle)
			ShowWindow(handle, SW_HIDE);
	}
	void enabletouch(bool palmrejection, bool finetouch)
	{
		RegisterTouchWindow(handle, ((!palmrejection) * TWF_WANTPALM) | (finetouch * TWF_FINETOUCH));
	}
	void disabletouch()
	{
		UnregisterTouchWindow(handle);
	}
	int getClientWidth()
	{
		RECT rect;
		WINDOWPLACEMENT wp;
		GetWindowPlacement(handle, &wp);
		if (wp.showCmd == SW_SHOWMINIMIZED)
		{
			rect = wp.rcNormalPosition;
			return rect.bottom - rect.top - 2 * GetSystemMetrics(SM_CYSIZEFRAME) - getCaptionHeight();
		}
		else
		{
			GetWindowRect(handle, &rect);
			RECT outerRect(rect);
			AdjustWindowRectEx(&outerRect, GetWindowLong(handle, GWL_STYLE), false, GetWindowLong(handle, GWL_EXSTYLE));
			return 2 * (rect.right - rect.left) - outerRect.right + outerRect.left;
		}
	}
	int getClientHeight()
	{
		RECT rect;
		WINDOWPLACEMENT wp;
		GetWindowPlacement(handle, &wp);
		if (wp.showCmd == SW_SHOWMINIMIZED)
		{
			rect = wp.rcNormalPosition;
			return rect.bottom - rect.top - 2 * GetSystemMetrics(SM_CYSIZEFRAME) - getCaptionHeight();
		}
		else
		{
			GetWindowRect(handle, &rect);
			RECT outerRect(rect);
			AdjustWindowRectEx(&outerRect, GetWindowLong(handle, GWL_STYLE), false, GetWindowLong(handle, GWL_EXSTYLE));
			return 2 * (rect.bottom - rect.top) - outerRect.bottom + outerRect.top;
		}
	}
	std::list<Timer*> timers;
	Timer* createTimer(int interval, bool autoreset)
	{
		Timer* tmr;
		tmr = new Timer(interval, autoreset);
		SetTimer(handle, (UINT_PTR)tmr, interval, NULL);
		timers.push_back(tmr);
		return tmr;
	}
	void resetTimer(Timer* tmr, int newinterval)
	{
		SetTimer(handle, (UINT_PTR)tmr, tmr->interval = newinterval, NULL);
	}
	void removeTimer(Timer* tmr)
	{
		KillTimer(handle, (UINT_PTR)tmr);
		timers.remove(tmr);
		delete tmr;
	}

private:
	int getCaptionHeight() const
	{
		return GetWindowLongPtr(handle, GWL_STYLE) & WS_THICKFRAME && !(GetWindowLongPtr(handle, GWL_EXSTYLE) & WS_EX_TOOLWINDOW) ?
			GetSystemMetrics(SM_CYCAPTION) : GetSystemMetrics(SM_CYSMCAPTION);
	}
}* _window; //TODO: Replace global variable
LRESULT CALLBACK WndProc(HWND wnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	BYTE keyboardState[256];
	WCHAR wcharbuf[32];
	switch (msg)
	{
	case WM_CLOSE:
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		{
			GetKeyboardState(keyboardState);
			const int len = ToUnicode(wparam, (lparam >> 16) & 0x00ff, keyboardState, wcharbuf, ARRAYSIZE(wcharbuf), 0);
			_window->onKeyDown((uint32_t)wparam, len > 0 ? std::wstring(wcharbuf, len) : L"");
		}
		break;

	case WM_KEYUP:
	{
		GetKeyboardState(keyboardState);
		const int len = ToUnicode(wparam, (lparam >> 16) & 0x00ff, keyboardState, wcharbuf, ARRAYSIZE(wcharbuf), 0);
		_window->onKeyUp((uint32_t)wparam, len > 0 ? std::wstring(wcharbuf, len) : L"");
	}
		break;

	case WM_LBUTTONDOWN: case WM_MBUTTONDOWN: case WM_RBUTTONDOWN:
		SetCapture(wnd);
		_window->onMouseDown(GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam), (wparam & MK_LBUTTON) != 0, (wparam & MK_MBUTTON) != 0, (wparam & MK_RBUTTON) != 0);
		break;

	case WM_LBUTTONUP: case WM_MBUTTONUP: case WM_RBUTTONUP:
		if ((wparam & (MK_LBUTTON | MK_MBUTTON | MK_RBUTTON)) == 0)
			ReleaseCapture();
		_window->onMouseUp(GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam), (wparam & MK_LBUTTON) != 0, (wparam & MK_MBUTTON) != 0, (wparam & MK_RBUTTON) != 0);
		break;

	case WM_TIMER:
		{
			Timer* tmr = (Timer*)wparam;
			tmr->cbk(tmr, tmr->tag);
			if (!tmr->autoreset)
				_window->removeTimer(tmr);
		}
		break;
	}
	return DefWindowProc(wnd, msg, wparam, lparam);
}
OSWindow* createwindow(const OSWindow::Settings& settings, std::string& err)
{
	WinWindow* wnd = new WinWindow();
	if ((err = wnd->init(settings)).size())
	{
		delete wnd;
		return NULL;
	}
	return (OSWindow*)(_window = wnd);
}


#include <GL/glut.h>
#include "glext.h"
#include "GLX.h"

class WinGLGraphics : Graphics
{
private:
	int backbuffersize_width, backbuffersize_height;
	HWND wnd;
	HDC devicectx;
	HGLRC renderctx;

public:
	WinGLGraphics(const Settings& settings) : Graphics(settings) {}
	std::string init(WinWindow* wnd, Graphics::OpenGLSettings& settings)
	{
		// Adjust size
		RECT clientrect;
		if (!settings.is_fullscreen && GetClientRect(wnd->gethandle(), &clientrect))
		{
			settings.backbuffersize_width = clientrect.right - clientrect.left;
			settings.backbuffersize_height = clientrect.bottom - clientrect.top;
		}

		this->backbuffersize_width = settings.backbuffersize_width;
		this->backbuffersize_height = settings.backbuffersize_height;
		this->wnd = wnd->gethandle();

		int result;

		// Get the device context for this window.
		devicectx = GetDC(this->wnd);
		if (!devicectx)
			return "Error retrieving device context";

		/*PIXELFORMATDESCRIPTOR pixelFormatDescriptor;
		PIXELFORMATDESCRIPTOR pfd = { 0 };
		pfd.nSize = sizeof(pfd);
		pfd.nVersion = 1;
		pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER | PFD_SUPPORT_COMPOSITION;
		pfd.cColorBits = 24;
		pfd.cAlphaBits = 8;
		pfd.cDepthBits = 0;
		pfd.cStencilBits = 0;
		int pixelformat = ChoosePixelFormat(devicectx, &pfd);
		result = SetPixelFormat(devicectx, pixelformat, &pixelFormatDescriptor);
		if (result != 1)
			return false;*/

		if (!GLX.Query(NULL, devicectx))
			return "Error querying OpenGL extensions";

		PIXELFORMATDESCRIPTOR pixelFormatDescriptor;
		int attributes[] = {
			WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,
			WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
			WGL_DOUBLE_BUFFER_ARB, GL_TRUE,
			WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB,
			WGL_COLOR_BITS_ARB, 32,
			WGL_DEPTH_BITS_ARB, 24,
			WGL_STENCIL_BITS_ARB, 8,
			WGL_SAMPLE_BUFFERS_ARB, settings.enable_multisampling ? 1 : 0,
			WGL_SAMPLES_ARB, settings.enable_multisampling ? 8 : 0,
			0
		};
		int pixelFormat;
		UINT numFormats;
		BOOL b = GLX.wglChoosePixelFormatARB(devicectx, attributes, NULL, 1, &pixelFormat, &numFormats);
		result = SetPixelFormat(devicectx, pixelFormat, &pixelFormatDescriptor);
		if (result != 1)
			return false;

		// Create a OpenGL X.Y rendering context.
#define WGL_CONTEXT_MAJOR_VERSION_ARB  0x2091
#define WGL_CONTEXT_MINOR_VERSION_ARB  0x2092
		const int attrlist[] = {
			WGL_CONTEXT_MAJOR_VERSION_ARB, settings.oglversion_major,
			WGL_CONTEXT_MINOR_VERSION_ARB, settings.oglversion_minor,
			0 // Null terminator
		};
		renderctx = GLX.wglCreateContextAttribsARB(devicectx, NULL, attrlist);
		if (!renderctx)
			return "Error creating OpenGL context";

		// Set the rendering context to active.
		if (wglMakeCurrent(devicectx, renderctx) == 0)
			return "Error switching to OpenGL context";

		// Set the depth buffer to be entirely cleared to 1.0 values.
		glClearDepth(1.0f);

		// Enable depth testing.
		glEnable(GL_DEPTH_TEST);

		// Set the polygon winding to front facing for the left handed system.
		glFrontFace(GL_CW);

		// Enable back face culling.
		//glEnable(GL_CULL_FACE);
		//glCullFace(GL_BACK);
glDisable(GL_CULL_FACE);
		
		if (settings.enable_multisampling)
			glEnable(GL_MULTISAMPLE);


		return "";
	}

	void Render()
	{
		/*// Clear the backbuffer
		if (backcolor_enabled)
		{
			glClearColor(backcolor[0], backcolor[1], backcolor[2], backcolor[3]);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}
		else
			glClear(GL_DEPTH_BUFFER_BIT);*/

		SwapBuffers(devicectx);
	}

	~WinGLGraphics()
	{
		// Release the rendering context.
		if (renderctx)
		{
			wglMakeCurrent(NULL, NULL);
			wglDeleteContext(renderctx);
			renderctx = NULL;
		}

		// Release the device context.
		if (devicectx)
		{
			ReleaseDC(wnd, devicectx);
			devicectx = NULL;
		}
	}
};
Graphics* creategraphics(OSWindow* wnd, Graphics::Settings& settings, std::string& err)
{
	WinWindow* wwnd = (WinWindow*)wnd;//dynamic_cast<WinWindow*>(wnd);
	if (!wwnd)
	{
		err = "Can't create Windows graphics on non-Windows window";
		return NULL;
	}

	if (settings.type == Graphics::Settings::OPENGL)
	{
		WinGLGraphics* gfx = new WinGLGraphics(settings);
		if ((err = gfx->init(wwnd, (Graphics::OpenGLSettings&)settings)).size())
		{
			delete gfx;
			return NULL;
		}
		return (Graphics*)gfx;
	}
	else
	{
		err = "Unsupported graphics type";
		return NULL;
	}
}

#endif