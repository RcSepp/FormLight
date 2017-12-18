#include <cstdint>
#include <string>
#include <vector>
#include "platform.h"
#include "controls.h"

#include "Image.h"
#include "GLTexture.h"
#include "GLShader.h"
#include "GLMesh.h"

#ifdef _WIN32
#undef LoadImage
#endif

int _main(int argc, char** argv)
{
	std::string err;

	OSWindow::Settings wndsettings;
	wndsettings.caption = "view";
	wndsettings.clientsize_width = 800;
	wndsettings.clientsize_height = 800;
	OSWindow* wnd = createwindow(wndsettings, err);
	if (!wnd)
	{
		error(err);
		return 0;
	}
	wnd->show();
	//wnd->enabletouch(false);

	Graphics::OpenGLSettings gfxsettings;
	gfxsettings.oglversion_major = 3;
	gfxsettings.oglversion_minor = 0;
	//gfxsettings.enable_multisampling = false;
	Graphics* gfx = creategraphics(wnd, gfxsettings, err);
	if (!gfx)
	{
		delete wnd;
		error(err);
		return 0;
	}

	Image* img = LoadImage("test128.bmp", err);
	if (!img)
	{
		error(err);
		return 0;
	}

	Form frm(wnd, gfx);
	//frm.onMouseDown.connect([](MouseEventArgs eventArgs) { MessageBox(NULL, "frm clicked", "", 0); });
	Button cmd;
	cmd.setBounds(8, 8, 100, 26);
	cmd.onClick.connect([&]() { cmd.text = L"this_is_a_test"; cmd.redraw(); });
	frm.controls.add(&cmd);
	for (int i = 0; i < 5; ++i)
	{
		PictureBox* pic = new PictureBox();
		pic->setBounds(8 + 188 * i, 42, 180, 148);
		pic->setImage(img);
		pic->setSizeMode((PictureBox::SizeMode)i);
		//pic.setSizeMode(PictureBox::SM_NORMAL);
		//pic.setSizeMode(PictureBox::SM_CENTER_IMAGE);
		//pic.setSizeMode(PictureBox::SM_AUTO_SIZE);
		//pic.setSizeMode(PictureBox::SM_STRETCH_IMAGE);
		//pic.setSizeMode(PictureBox::SM_ZOOM);
		//pic->onMouseDown.connect([](MouseEventArgs eventArgs) { MessageBox(NULL, "pic clicked", "", 0); });
		frm.controls.add(pic);
	}
	TextBox txt;
	txt.setBounds(8, 198, 400, 280);
	//txt.onMouseDown.connect([](MouseEventArgs eventArgs) { MessageBox(NULL, "txt clicked", "", 0); });
	frm.controls.add(&txt);

	/*SaveImage("out.png", img, err);
	if (!err.empty())
	{
		error(err);
		return 0;
	}
	return 1;*/

	frm.showDialog();

	delete wnd;
	delete gfx;
	return 1;
}