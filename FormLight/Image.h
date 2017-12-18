#pragma once
#ifndef __IMAGE_H
#define __IMAGE_H

#include <cstring>
#ifdef _WIN32
#undef LoadImage
#endif

struct Image
{
	uint8_t* data;
	int width, height, bpp;
	bool isdataowner;

	Image() : data(NULL), isdataowner(false) {}
	~Image() { if (data && isdataowner) delete[] data; }
	static Image* New(int width, int height, int bpp)
	{
		Image* newimage = new Image();
		newimage->width = width;
		newimage->height = height;
		newimage->bpp = bpp;
		newimage->data = new uint8_t[newimage->width * newimage->height * newimage->bpp];
		memset(newimage->data, 0, newimage->width * newimage->height * newimage->bpp);
		newimage->isdataowner = true;
		return newimage;
	}
};

Image* LoadImage(std::string filename, std::string& err);
Image* LoadImage(const uint8_t* filestream, int filestreamsize, std::string& err);
bool SaveImage(std::string filename, Image* img, std::string& err);
bool SaveImage(void** data, uint32_t* datasize, std::string ext, Image* img, std::string& err);

#endif