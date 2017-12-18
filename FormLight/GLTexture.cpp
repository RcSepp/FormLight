#include "GLTexture.h"
#include "Image.h"

GLTexture2D* GLTexture2D::FromFile(std::string filename, std::string err, bool genmipmaps)
{
	Image* img = LoadImage(filename, err);
	if (!img)
		return NULL;
	GLTexture2D* tex = GLTexture2D::FromImage(img, err, genmipmaps);
	delete img;
	return tex;
}
GLTexture2D* GLTexture2D::FromImage(const Image* img, std::string err, bool genmipmaps)
{
	GLTexture2D* tex = new GLTexture2D(img->data, img->width, img->height, false, img->bpp == 4 ? PixelFormat::Rgba : PixelFormat::Rgb);
	return tex;
}

void GLTexture2D::Save()
{
	const size_t bytesPerPixel = 4;	// RGB
	const size_t imageSizeInBytes = bytesPerPixel * size_t(width) * size_t(height);

	// Allocate with malloc, because the data will be managed by wxImage
	uint8_t* pixels = new uint8_t[imageSizeInBytes];

	Bind();
	// glReadPixels can align the first pixel in each row at 1-, 2-, 4- and 8-byte boundaries. We
	// have allocated the exact size needed for the image so we have to use 1-byte alignment
	// (otherwise glReadPixels would write out of bounds)
	glPixelStorei(GL_PACK_ALIGNMENT, 1);
	glReadPixels(0, 0, width, height, bytesPerPixel == 3 ? GL_RGB : GL_RGBA, GL_UNSIGNED_BYTE, pixels);
	//ErrorCode glerr = GL.GetError();

	// glReadPixels reads the given rectangle from bottom-left to top-right, so we must reverse it
	/*for (int y = 0; y < height / 2; y++)
	{
		const int swapY = height - y - 1;
		for (int x = 0; x < width; x++)
		{
			const int offset = int(bytesPerPixel) * (x + y * width);
			const int swapOffset = int(bytesPerPixel) * (x + swapY * width);

			// Swap R, G and B of the 2 pixels
			std::swap(pixels[offset + 0], pixels[swapOffset + 0]);
			std::swap(pixels[offset + 1], pixels[swapOffset + 1]);
			std::swap(pixels[offset + 2], pixels[swapOffset + 2]);
		}
	}*/

	Image img;
	img.data = pixels;
	img.width = width;
	img.height = height;
	img.bpp = bytesPerPixel;
	std::string err;
	SaveImage("out.png", &img, err);

	delete[] pixels;
}

void GLRenderTargetTexture2D::Save()
{
	const size_t bytesPerPixel = 4;	// RGB
	const size_t imageSizeInBytes = bytesPerPixel * size_t(width) * size_t(height);

	// Allocate with malloc, because the data will be managed by wxImage
	uint8_t* pixels = new uint8_t[imageSizeInBytes];

	Bind();
	// glReadPixels can align the first pixel in each row at 1-, 2-, 4- and 8-byte boundaries. We
	// have allocated the exact size needed for the image so we have to use 1-byte alignment
	// (otherwise glReadPixels would write out of bounds)
	glPixelStorei(GL_PACK_ALIGNMENT, 1);
	glReadPixels(0, 0, width, height, bytesPerPixel == 3 ? GL_BGR : GL_BGRA, GL_UNSIGNED_BYTE, pixels);
	//ErrorCode glerr = GL.GetError();

	// glReadPixels reads the given rectangle from bottom-left to top-right, so we must reverse it
	/*for (int y = 0; y < height / 2; y++)
	{
		const int swapY = height - y - 1;
		for (int x = 0; x < width; x++)
		{
			const int offset = int(bytesPerPixel) * (x + y * width);
			const int swapOffset = int(bytesPerPixel) * (x + swapY * width);

			// Swap R, G and B of the 2 pixels
			std::swap(pixels[offset + 0], pixels[swapOffset + 0]);
			std::swap(pixels[offset + 1], pixels[swapOffset + 1]);
			std::swap(pixels[offset + 2], pixels[swapOffset + 2]);
		}
	}*/

	Image img;
	img.data = pixels;
	img.width = width;
	img.height = height;
	img.bpp = bytesPerPixel;
	std::string err;
	SaveImage("out.png", &img, err);
	
	delete[] pixels;
}
