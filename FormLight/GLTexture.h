#pragma once
#ifndef __GLTEXTURE_H
#define __GLTEXTURE_H

#include <string>
#include <assert.h>
#ifdef _WIN32
#include <GL/glut.h>
#include "glext.h"
#else
#include<GL/gl.h>
#include<GL/glx.h>
#endif
#include "GLX.h"

#include "OpenGL.h"

struct Image;

class GLTexture
{
public:
	GLuint tex;
	const TextureTarget type;
	const int width, height;

	GLTexture(TextureTarget type, int width, int height)
		: tex((GLuint)-1), type(type), width(width), height(height) {}

	void Bind()
	{
		GL.BindTexture(type, tex);
	}

	void Dispose()
	{
		if (tex != (GLuint)-1)
		{
			GL.DeleteTexture(tex);
			tex = -1;
		}
	}
};

class GLTexture1D : public GLTexture
{
private:
	const uint8_t* bytes;
	const PixelFormat sourceformat;

public:
	GLTexture1D(const uint8_t* bytes, int width, PixelFormat sourceformat, bool genmipmaps = false)
		: GLTexture(TextureTarget::Texture1D, width, 1), sourceformat(sourceformat)
	{
		this->bytes = bytes;
		GL.GenTextures(1, &tex);
		GL.BindTexture(TextureTarget::Texture1D, tex);
		GL.TexImage1D(TextureTarget::Texture1D, 0, PixelInternalFormat::Rgba, width, 0, sourceformat, PixelType::UnsignedByte, bytes);

		if (genmipmaps)
		{
			GL.GenerateMipmap(GenerateMipmapTarget::Texture1D);
			GL.TexParameter(TextureTarget::Texture1D, TextureParameterName::TextureMinFilter, TextureMinFilter::NearestMipmapNearest);
			GL.TexParameter(TextureTarget::Texture1D, TextureParameterName::TextureMagFilter, TextureMagFilter::Nearest);
		}
		else
		{
			GL.TexParameter(TextureTarget::Texture1D, TextureParameterName::TextureMinFilter, TextureMagFilter::Nearest);
			GL.TexParameter(TextureTarget::Texture1D, TextureParameterName::TextureMagFilter, TextureMagFilter::Nearest);
		}
		GL.TexParameter(TextureTarget::Texture1D, TextureParameterName::TextureWrapS, TextureWrapMode::Clamp);
	}

	const uint8_t* Lock() const
	{
		return bytes;
	}
	void Unlock()
	{
		GL.BindTexture(TextureTarget::Texture1D, tex);
		GL.TexImage1D(TextureTarget::Texture1D, 0, PixelInternalFormat::Rgba, width, 0, sourceformat, PixelType::UnsignedByte, bytes);
	}

	void Interpolate(float x, uint8_t& r, uint8_t& g, uint8_t& b, uint8_t& a) const
	{
		float f = x * (float)width;
		int i = (int)f;
		if (i < 0)
		{
			r = bytes[0];
			g = bytes[1];
			b = bytes[2];
			a = bytes[3];
			return;
		}
		if (i + 1 >= width)
		{
			r = bytes[4 * width - 4];
			g = bytes[4 * width - 3];
			b = bytes[4 * width - 2];
			a = bytes[4 * width - 1];
			return;
		}

		f -= (float)i;
		if (f <= 0.0f)
		{
			r = bytes[i * 4 + 0];
			g = bytes[i * 4 + 1];
			b = bytes[i * 4 + 2];
			a = bytes[i * 4 + 3];
			return;
		}

		float h = 1.0f - f;
		int j = i + 1;
		r = (uint8_t)((float)bytes[i * 4 + 0] * h + (float)bytes[j * 4 + 0] * f);
		g = (uint8_t)((float)bytes[i * 4 + 1] * h + (float)bytes[j * 4 + 1] * f);
		b = (uint8_t)((float)bytes[i * 4 + 2] * h + (float)bytes[j * 4 + 2] * f);
		a = (uint8_t)((float)bytes[i * 4 + 3] * h + (float)bytes[j * 4 + 3] * f);
	}
};

class GLTexture2D : public GLTexture
{
public:
	/*GLTexture2D(IBitmap bmp, bool genmipmaps = false, bool linearfilter = false, GLenum sourceformat = GL_BGRA_EXT, GLenum destformat = PixelInternalFormat::Rgba, GLenum sourcetype = PixelType_UnsignedByte)
		: GLTexture(TextureTarget::Texture2D, bmp.Width, bmp.Height)
	{
		GL.GenTextures(1, &tex);
		GL.BindTexture(TextureTarget::Texture2D, tex);

	reattempt_load:
		try {
			//BitmapData bmpdata = bmp.LockBits(new Rectangle(0, 0, bmp.Width, bmp.Height), ImageLockMode.ReadOnly, System.Drawing.Imaging.PixelFormat.Format32bppArgb);
			//GL.TexImage2D(TextureTarget::Texture2D, 0, destformat, bmpdata.Width, bmpdata.Height, 0, sourceformat, sourcetype, bmpdata.Scan0);
			//bmp.UnlockBits(bmpdata);
			bmp.TexImage2D(destformat);
		}
		catch (OutOfMemoryException) {
			GC.WaitForPendingFinalizers();
			goto reattempt_load;
		}

		if (genmipmaps)
		{
			GL.GenerateMipmap(GenerateMipmapTarget::Texture2D);
			if (linearfilter)
			{
				GL.TexParameter(TextureTarget::Texture2D, TextureParameterName::TextureMinFilter, TextureMinFilter::LinearMipmapLinear);
				GL.TexParameter(TextureTarget::Texture2D, TextureParameterName::TextureMagFilter, TextureMinFilter::Linear);
			}
			else
			{
				GL.TexParameter(TextureTarget::Texture2D, TextureParameterName::TextureMinFilter, TextureMinFilter::NearestMipmapNearest);
				GL.TexParameter(TextureTarget::Texture2D, TextureParameterName::TextureMagFilter, TextureMagFilter::Nearest);
			}
		}
		else
		{
			if (linearfilter)
			{
				GL.TexParameter(TextureTarget::Texture2D, TextureParameterName::TextureMinFilter, TextureMinFilter::Linear);
				GL.TexParameter(TextureTarget::Texture2D, TextureParameterName::TextureMagFilter, (int)TextureMagFilter.Linear);
			}
			else
			{
				GL.TexParameter(TextureTarget::Texture2D, TextureParameterName::TextureMinFilter, TextureMagFilter::Nearest);
				GL.TexParameter(TextureTarget::Texture2D, TextureParameterName::TextureMagFilter, (int)TextureMagFilter.Nearest);
			}
		}
		GL.TexParameter(TextureTarget::Texture2D, TextureParameterName::TextureWrapS, TextureWrapMode::Clamp);
		GL.TexParameter(TextureTarget::Texture2D, TextureParameterName::TextureWrapT, TextureWrapMode::Clamp);
	}
	static GLTexture2D FromFile(std::string filename, bool genmipmaps = false)
	{
		if (!File.Exists(filename))
			throw new FileNotFoundException();

		return new GLTexture2D(filename, new GdiBitmap(filename), genmipmaps);
	}*/
	static GLTexture2D* FromFile(std::string filename, std::string err, bool genmipmaps = false);
	static GLTexture2D* FromImage(const Image* img, std::string err, bool genmipmaps = false);

	GLTexture2D(const uint8_t* bytes, int width, int height, bool genmipmaps = false, PixelFormat sourceformat = PixelFormat::Rgb, PixelInternalFormat destformat = PixelInternalFormat::Rgba, PixelType sourcetype = PixelType::UnsignedByte)
		: GLTexture(TextureTarget::Texture2D, width, height)
	{
		GL.GenTextures(1, &tex);
		GL.BindTexture(TextureTarget::Texture2D, tex);
		GL.TexImage2D(TextureTarget::Texture2D, 0, destformat, width, height, 0, sourceformat, sourcetype, bytes);

		if (genmipmaps)
		{
			GL.GenerateMipmap(GenerateMipmapTarget::Texture2D);
			GL.TexParameter(TextureTarget::Texture2D, TextureParameterName::TextureMinFilter, TextureMinFilter::NearestMipmapNearest);
			GL.TexParameter(TextureTarget::Texture2D, TextureParameterName::TextureMagFilter, TextureMagFilter::Nearest);
		}
		else
		{
			GL.TexParameter(TextureTarget::Texture2D, TextureParameterName::TextureMinFilter, TextureMagFilter::Nearest);
			GL.TexParameter(TextureTarget::Texture2D, TextureParameterName::TextureMagFilter, TextureMagFilter::Nearest);
		}
		GL.TexParameter(TextureTarget::Texture2D, TextureParameterName::TextureWrapS, TextureWrapMode::Clamp);
		GL.TexParameter(TextureTarget::Texture2D, TextureParameterName::TextureWrapT, TextureWrapMode::Clamp);
	}
	GLTexture2D(int width, int height, bool genmipmaps = false, PixelFormat sourceformat = PixelFormat::Rgb, PixelInternalFormat destformat = PixelInternalFormat::Rgba, PixelType sourcetype = PixelType::UnsignedByte, bool linearfilter = false)
		: GLTexture(TextureTarget::Texture2D, width, height)
	{
		GL.GenTextures(1, &tex);
		GL.BindTexture(TextureTarget::Texture2D, tex);
		GL.TexImage2D(TextureTarget::Texture2D, 0, destformat, width, height, 0, sourceformat, sourcetype, NULL);

		if (genmipmaps)
		{
			GL.GenerateMipmap(GenerateMipmapTarget::Texture2D);
			if (linearfilter)
			{
				GL.TexParameter(TextureTarget::Texture2D, TextureParameterName::TextureMinFilter, TextureMinFilter::LinearMipmapLinear);
				GL.TexParameter(TextureTarget::Texture2D, TextureParameterName::TextureMagFilter, TextureMinFilter::Linear);
			}
			else
			{
				GL.TexParameter(TextureTarget::Texture2D, TextureParameterName::TextureMinFilter, TextureMinFilter::NearestMipmapNearest);
				GL.TexParameter(TextureTarget::Texture2D, TextureParameterName::TextureMagFilter, TextureMagFilter::Nearest);
			}
		}
		else
		{
			if (linearfilter)
			{
				GL.TexParameter(TextureTarget::Texture2D, TextureParameterName::TextureMinFilter, TextureMinFilter::Linear);
				GL.TexParameter(TextureTarget::Texture2D, TextureParameterName::TextureMagFilter, TextureMinFilter::Linear);
			}
			else
			{
				GL.TexParameter(TextureTarget::Texture2D, TextureParameterName::TextureMinFilter, TextureMagFilter::Nearest);
				GL.TexParameter(TextureTarget::Texture2D, TextureParameterName::TextureMagFilter, TextureMagFilter::Nearest);
			}
		}
		GL.TexParameter(TextureTarget::Texture2D, TextureParameterName::TextureWrapS, TextureWrapMode::Clamp);
		GL.TexParameter(TextureTarget::Texture2D, TextureParameterName::TextureWrapT, TextureWrapMode::Clamp);
	}

	GLTexture2D(int tex, int width, int height)
		: GLTexture(TextureTarget::Texture2D, width, height)
	{
		this->tex = tex;
	}

	void Save();
};

class GLRenderTargetTexture2D : public GLTexture
{
private:
	GLuint fbo;

public:
	GLRenderTargetTexture2D(int width, int height, bool multisample)
		: GLTexture(multisample ? TextureTarget::Texture2DMultisample : TextureTarget::Texture2D, width, height)
	{
		tex = GL.GenTexture();
		GL.BindTexture(type, tex);
		if (multisample)
			GLX.glTexImage2DMultisample(type, 8, PixelInternalFormat::Rgba8, width, height, false);
		else
			GL.TexImage2D(type, 0, PixelInternalFormat::Rgba8, width, height, 0, PixelFormat::Rgba, PixelType::Byte, NULL);
		GL.TexParameter(TextureTarget::Texture2D, TextureParameterName::TextureMinFilter, TextureMagFilter::Nearest);
		GL.TexParameter(TextureTarget::Texture2D, TextureParameterName::TextureMagFilter, TextureMagFilter::Nearest);

		fbo = GL.GenFramebuffer();
		GL.BindFramebuffer(FramebufferTarget::Framebuffer, fbo);
		GL.FramebufferTexture2D(FramebufferTarget::Framebuffer, FramebufferAttachment::ColorAttachment0, type, tex, 0);

		GL.DrawBuffer(DrawBufferMode::ColorAttachment0);

		GLenum status = GL.CheckFramebufferStatus(FramebufferTarget::Framebuffer);
		assert(status == GL_FRAMEBUFFER_COMPLETE);
		
		GL.BindFramebuffer(FramebufferTarget::Framebuffer, 0);
		GL.BindTexture(type, 0);
	}

	void BindFramebuffer()
	{
		GL.BindFramebuffer(FramebufferTarget::Framebuffer, fbo);
assert(GL.GetError() == ErrorCode::NoError);
		GL.Viewport(0, 0, width, height);
	}

	void Save();
};

#endif
