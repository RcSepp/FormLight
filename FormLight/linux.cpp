#ifndef _WIN32

#include<X11/Xlib.h>
#include <cstdint>
#include <string>
#include "platform.h"

Display *display;
int main(int argc, char** argv)
{
	display = XOpenDisplay(NULL);
	if (!display)
	{
		error("Cannot open display");
		return 0;
	}
	int r = _main(argc, argv);
	XCloseDisplay(display);
	return r;
}

XEvent event;
bool processEvent();
int predicate(Display*, XEvent*, XPointer) { return 1; }
bool work()
{
	if (XCheckIfEvent(display, &event, &predicate, NULL))
		return processEvent();
	else
		return true;
}
bool wait()
{
	printf("wait\n");
	XNextEvent(display, &event);
	return processEvent();
}

void wakeup()
{
	//NOT IMPLEMENTED
}

void error(std::string text)
{
	printf("%s\n", text.c_str());
}



class XWindow : public OSWindow
{
private:
	Window wnd;
	
public:
	XIC xic;
	const Window gethandle() { return wnd; }
	std::string init(const OSWindow::Settings& settings)
	{
		int s = DefaultScreen(display);
		
		wnd = XCreateSimpleWindow(display, RootWindow(display, s), settings.windowpos_x, settings.windowpos_y, settings.clientsize_width, settings.clientsize_height, 1, BlackPixel(display, s), WhitePixel(display, s));
		
		Atom delWindow = XInternAtom(display, "WM_DELETE_WINDOW", 0);
		XSetWMProtocols(display, wnd, &delWindow, 1);
		
// X input method setup, only strictly necessary for intl key text

// loads the XMODIFIERS environment variable to see what IME to use
XSetLocaleModifiers("");

XIM xim = XOpenIM(display, 0, 0, 0);
if(!xim){
// fallback to internal input method
XSetLocaleModifiers("@im=none");
xim = XOpenIM(display, 0, 0, 0);
}

// X input context, you can have multiple for text boxes etc, but having a
// single one is the easiest.

xic = XCreateIC(xim,
XNInputStyle,   XIMPreeditNothing | XIMStatusNothing,
XNClientWindow, wnd,
XNFocusWindow,  wnd,
NULL);

XSetICFocus(xic);
		
		XSelectInput(display, wnd, ExposureMask | KeyPressMask | KeyReleaseMask | ButtonPressMask | ButtonReleaseMask);
		
		return "";
	}
	
	void show()
	{
		XMapWindow(display, wnd);
	}
	void hide() {}
	void enabletouch(bool palmrejection = true, bool finetouch = false) {}
	void disabletouch() {}
	int getClientWidth()
	{
		XWindowAttributes wndattrs;
		return XGetWindowAttributes(display, wnd, &wndattrs) ? wndattrs.width : 0;
	}
	int getClientHeight()
	{
		XWindowAttributes wndattrs;
		return XGetWindowAttributes(display, wnd, &wndattrs) ? wndattrs.height : 0;
	}
	Timer* createTimer(int interval, bool autoreset) { return NULL; }
	void resetTimer(Timer* tmr, int newinterval) { }
	void removeTimer(Timer* tmr) { }
}* _window; //TODO: Replace global variable

bool processEvent()
{
	static wchar_t wcharbuf[32];
	switch(event.type)
	{
	case Expose:
		{
			//_window->onResize();
//int s = DefaultScreen(display);
//			XFillRectangle(display, event.xany.window, DefaultGC(display, s), 20, 20, 10, 10);
		}
		break;
	case KeyPress:
		{
			int len = XwcLookupString(_window->xic, &event.xkey, wcharbuf, 16, NULL, NULL);
			_window->onKeyDown(event.xkey.keycode, len > 0 ? std::wstring(wcharbuf, len) : L"");
		}
		break;
	case KeyRelease:
		{
			int len = XwcLookupString(_window->xic, &event.xkey, wcharbuf, 16, NULL, NULL);
			_window->onKeyUp(event.xkey.keycode, len > 0 ? std::wstring(wcharbuf, len) : L"");
		}
	case ButtonPress:
		_window->onMouseDown(event.xbutton.x, event.xbutton.y, event.xbutton.button == 1, event.xbutton.button == 2, event.xbutton.button == 3);
		//TODO: This wouldn't remember other mouse buttons still held down
		break;
	case ButtonRelease:
		_window->onMouseUp(event.xbutton.x, event.xbutton.y, false, false, false);
		//TODO: This wouldn't remember other mouse buttons still held down
		break;
	case ClientMessage:
		return false;
	}
	return true;
}

OSWindow* createwindow(const OSWindow::Settings& settings, std::string& err)
{
	XWindow* wnd = new XWindow();
	if ((err = wnd->init(settings)).size())
	{
		delete wnd;
		return NULL;
	}
	return (OSWindow*)(_window = wnd);
}













#include<GL/gl.h>
#include<GL/glx.h>
#include "GLX.h"

class XGLGraphics : Graphics
{
private:
	int backbuffersize_width, backbuffersize_height;
	Window wnd;
	Window devicectx;
	GLXContext renderctx;

public:
	XGLGraphics(const Settings& settings) : Graphics(settings) {}
	std::string init(XWindow* wnd, Graphics::OpenGLSettings& settings)
	{
		// Adjust size
		if(!settings.is_fullscreen)
		{
			XWindowAttributes wndattrs;
			if(XGetWindowAttributes(display, wnd->gethandle(), &wndattrs))
			{
				settings.backbuffersize_width = wndattrs.width;
				settings.backbuffersize_height = wndattrs.height;
			}
		}

		this->backbuffersize_width = settings.backbuffersize_width;
		this->backbuffersize_height = settings.backbuffersize_height;
		this->wnd = wnd->gethandle();

		//int result;

		// Get the device context for this window.
		devicectx = this->wnd;

		if (!GLX.Query(display, devicectx))
			return "Error querying OpenGL extensions";

		// Create a OpenGL X.Y rendering context.
		// Check GLX version support
		int major, minor;
		if(!glXQueryVersion( display, &major, &minor))
			return "Error querying maximum supported OpenGL version";
		if((( major == settings.oglversion_major ) && ( minor < 4 ) ) || ( major < 1 ))
			return "Unsupported GLX version, maximum supported version = " + std::to_string(major) + "." + std::to_string(minor);

		// Check frame buffer configuration support
		static int visual_attribs[] =
		{
			GLX_X_RENDERABLE    , True,
			GLX_DRAWABLE_TYPE   , GLX_WINDOW_BIT,
			GLX_RENDER_TYPE     , GLX_RGBA_BIT,
			GLX_X_VISUAL_TYPE   , GLX_TRUE_COLOR,
			GLX_RED_SIZE        , 8,
			GLX_GREEN_SIZE      , 8,
			GLX_BLUE_SIZE       , 8,
			GLX_ALPHA_SIZE      , 8,
			GLX_DEPTH_SIZE      , 24,
			GLX_STENCIL_SIZE    , 8,
			GLX_DOUBLEBUFFER    , True,
			//GLX_SAMPLE_BUFFERS  , 1,
			//GLX_SAMPLES         , 4,
			None
		};
		int fbcount;
		GLXFBConfig* fbc = glXChooseFBConfig(display, DefaultScreen(display), visual_attribs, &fbcount);
		if(!fbc)
			return "Failed to retrieve a framebuffer config";

// Pick frame buffer configuration with the most samples per pixel
//printf( "Getting XVisualInfos\n" );
int best_fbc = -1, worst_fbc = -1, best_num_samp = -1, worst_num_samp = 999;
for(int i = 0; i < fbcount; ++i)
{
	XVisualInfo *vi = glXGetVisualFromFBConfig(display, fbc[i]);
	if(vi)
	{
		int samp_buf, samples;
		glXGetFBConfigAttrib( display, fbc[i], GLX_SAMPLE_BUFFERS, &samp_buf );
		glXGetFBConfigAttrib( display, fbc[i], GLX_SAMPLES       , &samples  );

		//printf( "  Matching fbconfig %d, visual ID 0x%2x: SAMPLE_BUFFERS = %d, SAMPLES = %d\n", i, vi -> visualid, samp_buf, samples );

		if(best_fbc < 0 || (samp_buf && samples > best_num_samp))
			best_fbc = i, best_num_samp = samples;
		if(worst_fbc < 0 || !samp_buf || samples < worst_num_samp)
			worst_fbc = i, worst_num_samp = samples;
	}
	XFree(vi);
}
GLXFBConfig bestfbc = fbc[best_fbc];
XFree(fbc);

		int XGL_CONTEXT_MAJOR_VERSION_ARB = 0, XGL_CONTEXT_MINOR_VERSION_ARB = 0;
		glGetIntegerv(GL_MAJOR_VERSION,&XGL_CONTEXT_MAJOR_VERSION_ARB);
		glGetIntegerv(GL_MINOR_VERSION,&XGL_CONTEXT_MINOR_VERSION_ARB);

		// Set OpenGL version in the attribute list
		const int attrlist[] = {
			XGL_CONTEXT_MAJOR_VERSION_ARB, settings.oglversion_major,
			XGL_CONTEXT_MINOR_VERSION_ARB, settings.oglversion_minor,
			0 // Null terminator
		};

		renderctx = GLX.glXCreateContextAttribsARB(display, bestfbc, NULL, true, attrlist);
		if(!renderctx)
			return "Error creating OpenGL context";

		// Set the rendering context to active.
		if (!glXMakeCurrent(display, devicectx, renderctx))
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

		glXSwapBuffers(display, devicectx);
	}

	~XGLGraphics()
	{
		// Release the rendering context.
		if (renderctx)
		{
			glXMakeCurrent(display, None, NULL);
			glXDestroyContext(display, renderctx);
			renderctx = NULL;
		}
	}
};

Graphics* creategraphics(OSWindow* wnd, Graphics::Settings& settings, std::string& err)
{
	XWindow* wwnd = (XWindow*)wnd;//dynamic_cast<XWindow*>(wnd);
	if (!wwnd)
	{
		err = "Can't create Linux graphics on non-Linux window";
		return NULL;
	}

	if (settings.type == Graphics::Settings::OPENGL)
	{
		XGLGraphics* gfx = new XGLGraphics(settings);
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