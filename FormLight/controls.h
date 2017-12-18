#pragma once
#ifndef __CONTROLS_H
#define __CONTROLS_H

#include <boost/signals2/signal.hpp>
using namespace boost::signals2;

#include "VectorMatrix.h"

struct Timer;
class OSWindow;
class Graphics;
class Control;
class Form;

/**
 * Datatype for rectangular shapes
**/
struct Rect
{
	int x, y, width, height;

	Rect() {}
	Rect(int x, int y, int width, int height) : x(x), y(y), width(width), height(height) {}
	/**
	 * Intersection test with another rectangle
	 * @param other Rectangle to test
	 * @return true this and other rectangles intersect
	 * @return false this and other rectangles don't intersect
	**/
	bool intersects(const Rect& other) const
	{
		return this->x < other.x + other.width &&
			   other.x < this->x + this->width &&
			   this->y < other.y + other.height &&
			   other.y < this->y + this->height;
	}
};

/**
 * Interface to an object that can be drawn
**/
class IDrawable
{
public:
	virtual void draw(const Rect& region) = 0;
};

/**
 * Interface to an object with a physical location and size
**/
class Spatial
{
protected:
	int x, y, width, height;

public:
	inline int getX() const { return x; };
	inline int getY() const { return y; };
	inline int getWidth() const { return width; };
	inline int getHeight() const { return height; };
	virtual Rect getBounds() { return Rect(x, y, width, height); };
	virtual int setX(int x) { return this->x = x; };
	virtual int setY(int y) { return this->y = y; };
	virtual int setWidth(int width) { return this->width = width; };
	virtual int setHeight(int height) { return this->height = height; };
	virtual void setBounds(int x, int y, int width, int height)
	{
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
	};
	virtual const Rect& setBounds(const Rect& bounds)
	{
		this->x = bounds.x;
		this->y = bounds.y;
		this->width = bounds.width;
		this->height = bounds.height;
		return bounds;
	};
};

/**
 * Datatype for mouse events
**/
struct MouseEventArgs
{
	int x, y;
	enum MouseButton {
		MB_LEFT = 0x1, ///< The left mouse button
		MB_MIDDLE = 0x2, ///< The middle mouse button
		MB_RIGHT = 0x4 ///< The right mouse button
	} buttons; ///< Bit field of pressed mouse buttons
};

/*class Brush
{
public:
	virtual void sample(float u, float v, Color4* sample) const = 0;
};
class SolidBrush : public Brush
{
public:
	Color4 color;
	SolidBrush() : color((unsigned int)0x00000000) {}
	SolidBrush(const Color4& color) : color(color) {}
	void sample(float u, float v, Color4* sample) const { ClrSet(sample, color); }
};
class GradientBrush : public Brush
{
public:
	void(* fct)(float u, float v, Color4* sample);
	GradientBrush() : fct(NULL) {}
	GradientBrush(void(* fct)(float u, float v, Color4* sample)) : fct(fct) {}
	void sample(float u, float v, Color4* sample) const { fct(u, v, sample); }
};*/

/**
 * Interface to a font object used to draw text
 *
 * A font is loaded using the Drawing::createFont() function
**/
class IFont
{
private:
	virtual void PLACEHOLDER() {};

public:
	const std::string family;
	const float size;
	IFont(std::string family, float size) : family(family), size(size) {}
};

struct Image;

/**
* Interface to a drawing context
*
* A painter is created using the Drawing::createPainter() function
**/
class Painter
{
public:
	virtual void startDrawing(const Spatial& bounds) = 0;
	virtual void endDrawing() = 0;

	virtual void clear(Color4 color) = 0;
	virtual void drawLine(Color4 color, int x1, int y1, int x2, int y2) = 0;
	virtual void drawRectangle(Color4 color, int x, int y, int width, int height) = 0;
	virtual void drawEllipse(Color4 color, int cx, int cy, int rx, int ry) = 0;
	virtual void drawImage(const Image* img, int x, int y, int width, int height) = 0;
	virtual void drawString(std::wstring string, IFont* font, Color4 color, int x, int y) = 0;
	virtual Vector2 measureString(std::wstring string, IFont* font) = 0;
	virtual void fillTriangle(Color4 color, int x1, int y1, int x2, int y2, int x3, int y3) = 0;
	virtual void fillRectangle(Color4 color, int x, int y, int width, int height) = 0;
	virtual void fillArc(Color4 color, int cx, int cy, int rx, int ry, float startAngle = 0.0f, float sweepAngle = 360.0f) = 0;
	virtual void fillEllipse(Color4 color, int cx, int cy, int rx, int ry) { fillArc(color, cx, cy, rx, ry); }
	virtual void fillCircle(Color4 color, int cx, int cy, int r) { fillEllipse(color, cx, cy, r, r); }
};

/**
 * Factory class for objects used in the composition of graphics
 *
 * To use a different graphics back-end (i.e. OpenGL, Vulkan or software rendering), implement Painter and IFont interfaces and provide factory methods to instantiate these classes.
**/
class Drawing
{
public:
	/**
	 * Initialize graphics library
	 * @param [out] err Error message or empty string if the function succeeded
	 * @return true Initialization of drawing library successfull
	 * @return false Initialization of drawing library failed. See err for details
	 *
	 * This method should be called once on program startup
	**/
	static bool Drawing::init(const Graphics* gfx, std::string& err);
	/**
	 * Create an instance of a Painter
	 * @param [out] err Error message or empty string if the function succeeded
	 * @return The newly created painter or NULL if the function failed
	**/
	static Painter* createPainter(std::string& err);
	/**
	* Create an instance of an IFont
	* @param family Font family
	* @param size Font size in points
	* @param [out] err Error message or empty string if the function succeeded
	* @return The newly created font or NULL if the function failed
	**/
	static IFont* createFont(std::string family, float size, std::string& err);
};


class ControlCollection : public IDrawable
{
private:
	Control* const owner;
	std::vector<Control*> controls;

public:
	ControlCollection(Control* owner) : owner(owner) {}
	void add(Control* control);
	void remove(Control* control);
	void removeAt(size_t index);
	void draw(const Rect& region);
	Control* getControlFromPoint(int x, int y);
};

class Control : public IDrawable, public Spatial
{
	friend ControlCollection;
	friend Form;
private:
	Control* parent;
	Form* parentForm;
	IFont* font;
	bool focused;

protected:
	void forwardMouseDown(MouseEventArgs eventArgs);

public:
	Painter* painter;
	ControlCollection controls;
	bool focusable;
	signal<void(MouseEventArgs eventArgs)> onMouseOver, onMouseEnter, onMouseLeave, onMouseDown, onMouseUp, onMouseClick, onDoubleClick;
	signal<void(uint32_t key, std::wstring character)> onKeyDown, onKeyUp;
	signal<void()> onGainFocus, onLoseFocus;

	Control(bool focusable = true, Form* parentForm = NULL) :
		parent(NULL),
		parentForm(parentForm),
		font(NULL),
		focused(false),
		controls(this),
		focusable(focusable)
	{
		// Default to a location of (0, 0) and a size of 100x100
		x = y = 0;
		width = height = 100;

		// Create a painter for this control
		std::string err;
		painter = Drawing::createPainter(err);
	}
	Control* getParent() const { return parent; }
	Form* getParentForm() const { return parentForm; }
	IFont* getFont() const { return font || !parent ? font : parent->getFont(); }
	IFont* setFont(IFont* font) { return this->font = font; }
	bool isFocused() const { return focused; }
	void focus();
	virtual void draw(const Rect& region);
	void redraw(bool render = true);
};

class Form : public Control
{
private:
	OSWindow* const wnd;
	Graphics* const gfx;
	Control* focusedControl;

public:
	Form(OSWindow* wnd, Graphics* gfx);
	//~Form() { delete wnd; }
	void draw(const Rect& region);
	void showDialog();
	void focusControl(Control* control);
	void render();
	Timer* createTimer(int interval, bool autoreset);
	void removeTimer(Timer* timer);
};

class Button : public Control
{
private:
	void draw(const Rect& region);

public:
	std::wstring text;
	signal<void()> onClick;

	Button();
};

class TextBox : public Control
{
private:
	Timer* cursorBlinkTimer;
	bool cursorVisible;
	void draw(const Rect& region);

public:
	std::wstring text;

	TextBox();
};

class PictureBox : public Control
{
public:
	enum SizeMode {
		SM_NORMAL, SM_AUTO_SIZE, SM_CENTER_IMAGE, SM_STRETCH_IMAGE, SM_ZOOM
	};

private:
	Image* img;
	SizeMode sm;

	void draw(const Rect& region);

public:
	PictureBox() : Control(false), img(NULL) {}
	Image* getImage() { return img; }
	Image* setImage(Image* image) { return img = image; }
	SizeMode getSizeMode() { return sm; }
	SizeMode setSizeMode(SizeMode sizeMode) { return sm = sizeMode; }
};

#endif