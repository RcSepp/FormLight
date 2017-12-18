#pragma once
#ifndef __PLATFORM_H
#define __PLATFORM_H

#include <boost/signals2/signal.hpp>
using namespace boost::signals2;

//-----------------------------------------------------------------------------
// >>> General
//-----------------------------------------------------------------------------

int _main(int argc, char** argv);

bool work();
bool wait();
void wakeup();
void error(std::string text);


//-----------------------------------------------------------------------------
// >>> GUI
//-----------------------------------------------------------------------------

enum CheckedState
	{CS_UNCHECKED, CS_CHECKED, CS_INDETERMINATE};
enum WindowState
	{WS_NORMAL, WS_MINIMIZED, WS_MAXIMIZED};
enum FormBorderStyle
{
	FBS_DEFAULT = 0x00000000L/*WS_OVERLAPPED*/ | 0x00C00000L/*WS_CAPTION*/ | 0x00080000/*WS_SYSMENU*/ | 0x00040000/*WS_THICKFRAME*/,
	FBS_THINBORDER = 0x00000000L/*WS_OVERLAPPED*/ | 0x00C00000L/*WS_CAPTION*/ | 0x00080000/*WS_SYSMENU*/,
	FBS_NOBORDER = 0x00000000L/*WS_OVERLAPPED*/,
	FBS_ONLYBORDER = 0x00040000/*WS_THICKFRAME*/
};
#define FS_CENTERTOSCREEN		0x1
#define FS_MDICLIENT			0x2
#define FS_MDICHILD				0x4

struct Timer
{
	signal<void(Timer*, void*)> cbk;
	int interval;
	bool autoreset;
	void* tag;
	Timer(int interval, bool autoreset)
		: interval(interval), autoreset(autoreset), tag(NULL) {}
};

class OSWindow
{
public:
	virtual ~OSWindow() {}
	struct Settings
	{
		std::string caption;
		int windowpos_x, windowpos_y;
		int clientsize_width, clientsize_height;
		WindowState wndstate;
		FormBorderStyle fbstyle;
		bool istoolwindow, hasvscroll, hashscroll;
		OSWindow* parent;
		//IMenuItem** mdiwindowmenu;
		uint32_t options;

		Settings() : caption(""), windowpos_x(0), windowpos_y(0), clientsize_width(800), clientsize_height(600), wndstate(WS_NORMAL), fbstyle(FBS_DEFAULT),
		istoolwindow(false), hasvscroll(false), hashscroll(false), parent(NULL)/*, mdiwindowmenu(NULL)*/, options(0) {}
	};
	virtual void show() = 0;
	virtual void hide() = 0;
	virtual void enabletouch(bool palmrejection = true, bool finetouch = false) = 0;
	virtual void disabletouch() = 0;
	virtual int getClientWidth() = 0;
	virtual int getClientHeight() = 0;
	virtual Timer* createTimer(int interval, bool autoreset) = 0;
	virtual void resetTimer(Timer* tmr, int newinterval) = 0;
	virtual void removeTimer(Timer* tmr) = 0;
	signal<void(uint32_t key, std::wstring character)> onKeyDown, onKeyUp;
	signal<void(int x, int y, bool ldown, bool mdown, bool rdown)> onMouseDown, onMouseClick, onDoubleClick, onMouseUp;
	signal<void()> onMouseOver, onMouseEnter, onMouseLeave;
};
OSWindow* createwindow(const OSWindow::Settings& settings, std::string& err);


//-----------------------------------------------------------------------------
// >>> Graphics
//-----------------------------------------------------------------------------

class Graphics
{
public:
	const struct Settings
	{
		enum Type { OPENGL };
		const Type type;
	protected:
		Settings(Type type) : type(type) {}
	} settings;
	struct OpenGLSettings : Settings
	{
		// Global options: These will be ignored for every, but the first, window
		bool is_fullscreen;
		int oglversion_major, oglversion_minor;

		// Window options
		int backbuffersize_width, backbuffersize_height;
		bool enable_multisampling;
		int screen_idx;

		OpenGLSettings() : Settings(OPENGL), is_fullscreen(false), oglversion_major(3), oglversion_minor(0), backbuffersize_width(800), backbuffersize_height(600), enable_multisampling(true), screen_idx(0) {}
	};
	bool backcolor_enabled;
	float backcolor[4];

	Graphics(const Settings& settings) : settings(settings), backcolor_enabled(true), backcolor{ 0.2f, 0.2f, 0.4f, 1.0f } {}
	virtual ~Graphics() {}
	virtual void Render() = 0;
};

Graphics* creategraphics(OSWindow* wnd, Graphics::Settings& settings, std::string& err);

#endif