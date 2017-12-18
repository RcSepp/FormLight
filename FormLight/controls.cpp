#include <string>
#include <vector>
#include <math.h>

#include "platform.h"
#include "controls.h"
#include "Image.h"

void ControlCollection::add(Control* control)
{
	control->parent = owner;
	control->parentForm = owner->parentForm;
	controls.push_back(control);
}

void ControlCollection::remove(Control* control)
{
	for (std::vector<Control*>::iterator c = controls.begin(); c != controls.end(); ++c)
		if (*c == control)
		{
			controls.erase(c);
			break;
		}
}

void ControlCollection::removeAt(size_t index)
{
	controls.erase(controls.begin() + index);
}

void ControlCollection::draw(const Rect& region)
{
	for (auto& control : controls)
		if (region.intersects(control->getBounds()))
			control->draw(region);
}

Control* ControlCollection::getControlFromPoint(int x, int y)
{
	for (std::vector<Control*>::iterator iter = controls.begin(); iter != controls.end(); ++iter)
	{
		Control* control = *iter;
		if (x >= control->getX() && x < control->getX() + control->getWidth() && y >= control->getY() && y < control->getY() + control->getHeight())
			return control;
	}
	return NULL;
}

Form::Form(OSWindow* wnd, Graphics* gfx)
	: Control(false, this), wnd(wnd), gfx(gfx), focusedControl(NULL)
{
	// Initialize graphics for this window
	std::string err;
	Drawing::init(gfx, err);
	if (!err.empty())
		printf(err.c_str());

	// Set form bounds to wnd bounds
	x = y = 0; //TODO: Set to window location
	width = wnd->getClientWidth();
	height = wnd->getClientHeight();
	
	// Create default font
	setFont(Drawing::createFont("Microsoft Sans Serif", 10, err));
	if (!err.empty())
		printf(err.c_str());

	// Forward window events to controls
	wnd->onMouseDown.connect([&](int x, int y, bool ldown, bool mdown, bool rdown) {
		this->forwardMouseDown({
			x, y,
			(MouseEventArgs::MouseButton)(ldown * MouseEventArgs::MB_LEFT | mdown * MouseEventArgs::MB_MIDDLE | rdown * MouseEventArgs::MB_RIGHT)
		});
	});
	wnd->onKeyDown.connect([&](uint32_t key, std::wstring character) {
		if (focusedControl)
			focusedControl->onKeyDown(key, character);
	});
	wnd->onKeyUp.connect([&](uint32_t key, std::wstring character) {
		if (focusedControl)
			focusedControl->onKeyUp(key, character);
	});
}

void Control::forwardMouseDown(MouseEventArgs eventArgs)
{
	Control* child = controls.getControlFromPoint(eventArgs.x, eventArgs.y);
	if (child)
		child->forwardMouseDown(eventArgs);
	else
	{
		parentForm->focusControl(this);
		onMouseDown(eventArgs);
	}
}

void Control::focus()
{
	parentForm->focusControl(this);
}

void Control::draw(const Rect& region)
{
	controls.draw(region);
}

void Control::redraw(bool render)
{
	draw(getBounds()); // Redraw without transparent window support
	//parentForm->draw(getBounds()); // Redraw with transparent window support
	if (render)
		parentForm->render();
}

void Form::draw(const Rect& region)
{
	painter->startDrawing(*this);
	painter->clear(Color4(0.2f, 0.5f, 0.6f, 1.0f));
	painter->endDrawing();

	Control::draw(region);
}

void Form::showDialog()
{
draw(Rect(0, 0, wnd->getClientWidth(), wnd->getClientHeight()));
render();
	while (wait()) {}
}

void Form::focusControl(Control* control)
{
	if (control->focusable)
	{
		if (focusedControl && focusedControl->focusable)
		{
			focusedControl->focused = false;
			focusedControl->onLoseFocus();
			focusedControl->redraw(false);
		}

		focusedControl = control;
		focusedControl->focused = true;
		focusedControl->onGainFocus();
		focusedControl->redraw(true);
	}
}

void Form::render() { gfx->Render(); }
Timer* Form::createTimer(int interval, bool autoreset) { return wnd->createTimer(interval, autoreset); }
void Form::removeTimer(Timer * timer) { wnd->removeTimer(timer); }

void Button::draw(const Rect& region)
{
	painter->startDrawing(*this);
	uint32_t color = isFocused() ? 0xFFAAAAFF : 0xFFEEEEEE;
	painter->fillRectangle(color, 8, 0, width - 2 * 8, height);
	painter->fillRectangle(color, 0, 8, width, height - 2 * 8);
	painter->fillArc(color, 8, 8, 8, 8, 180, 90);
	painter->fillArc(color, width - 8, 8, 8, 8, 270, 90);
	painter->fillArc(color, width - 8, height - 8, 8, 8, 0, 90);
	painter->fillArc(color, 8, height - 8, 8, 8, 90, 90);
	IFont* font = getFont();
	Vector2 textSize = painter->measureString(text, font);
	painter->drawString(text, font, Color4::Black, (width - (int)textSize.x) / 2, (height - (int)textSize.y) / 2);
	painter->endDrawing();

	Control::draw(region);
}

Button::Button()
	: text(L"Button")
{
	// Connect internal events
	onMouseDown.connect([&](MouseEventArgs eventArgs) {
		onClick();
	});
	onKeyDown.connect([&](uint32_t key, std::wstring character) {
		//if (key == 0x20) // 0x20 ... Space key
		if (character == L" ") // 0x20 ... Space key
			onClick();
	});
}

void PictureBox::draw(const Rect& region)
{
	if (img && sm == SM_AUTO_SIZE)
		setBounds(x, y, img->width, img->height); // Resize picture box to size of image

	painter->startDrawing(*this);
	painter->clear(Color4(1.0f, 1.0f, 1.0f, 1.0f));
	if (img)
		switch (sm)
		{
		case SM_CENTER_IMAGE: painter->drawImage(img, (width - img->width) / 2, (height - img->height) / 2, img->width, img->height); break; // Draw image centered
		case SM_STRETCH_IMAGE: painter->drawImage(img, 0, 0, width, height); break; // Draw image with picture box dimensions
		case SM_ZOOM:
			if (img->width * height >= img->height * width)
			{
				// Fit width
				const int h = width * img->height / img->width;
				painter->drawImage(img, 0, (height - h) / 2, width, h);
			}
			else
			{
				// Fit height
				const int w = height * img->width / img->height;
				painter->drawImage(img, (width - w) / 2, 0, w, height);
			}
			break;
		default: painter->drawImage(img, 0, 0, img->width, img->height); break; // Draw image in the upper-left corner
		}
	painter->endDrawing();

	Control::draw(region);
}

void TextBox::draw(const Rect& region)
{
	painter->startDrawing(*this);
	painter->clear(Color4(1.0f, 1.0f, 1.0f, 1.0f));
	painter->drawRectangle(0xFF000000, 0, 0, width - 1, height - 1);
	IFont* font = getFont();
	painter->drawString(text, font, Color4::Black, 8, 10);
	if (cursorVisible)
	{
		Vector2 textSize = painter->measureString(text, font);
		textSize.x = ceil(textSize.x);
		textSize.y = floor(textSize.y);
		painter->drawLine(Color4::Black, 8 + textSize.x, 10 + 2 + textSize.y - font->size * 1.5f, 8 + textSize.x, 10 + 2 + textSize.y);
	}
	painter->endDrawing();

	Control::draw(region);
}

TextBox::TextBox()
	: cursorBlinkTimer(NULL), cursorVisible(false), text(L"this is a test")
{
	// Connect internal events
	onKeyDown.connect([&](uint32_t key, std::wstring character) {
		text += character;
		redraw();
	});
	onGainFocus.connect([&]() {
		if (!cursorBlinkTimer && (cursorBlinkTimer = getParentForm()->createTimer(500, true)) != NULL)
		{
			cursorBlinkTimer->cbk.connect([&](Timer* sender, void* tag) {
				cursorVisible = !cursorVisible;
				redraw();
			});
		}
	});
	onLoseFocus.connect([&]() {
		if (cursorBlinkTimer)
		{
			getParentForm()->removeTimer(cursorBlinkTimer);
			cursorBlinkTimer = NULL;
		}
	});
}
