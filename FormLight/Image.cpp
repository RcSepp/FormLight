#include <string>
#include "Image.h"
#include <FreeImage.h>
#include <stdio.h>

#pragma comment (lib, "FreeImage.lib")

void FreeImageErrorHandler(FREE_IMAGE_FORMAT fif, const char *message)
{
	printf("\n*** ");
	if (fif != FIF_UNKNOWN) {
		printf("%s Format\n", FreeImage_GetFormatFromFIF(fif));
	}
	printf(message);
	printf(" ***\n");
}

unsigned DLL_CALLCONV myReadProc(void *buffer, unsigned size, unsigned count, fi_handle handle)
{
	return (unsigned)fread(buffer, size, count, (FILE *)handle);
}
unsigned DLL_CALLCONV myWriteProc(void *buffer, unsigned size, unsigned count, fi_handle handle)
{
	return (unsigned)fwrite(buffer, size, count, (FILE *)handle);
}
int DLL_CALLCONV mySeekProc(fi_handle handle, long offset, int origin)
{
	return fseek((FILE *)handle, offset, origin);
}
long DLL_CALLCONV myTellProc(fi_handle handle)
{
	return ftell((FILE *)handle);
}

Image* LoadImage(std::string filename, std::string& err)
{
#ifdef FREEIMAGE_LIB
	FreeImage_Initialise();
#endif

	FreeImage_SetOutputMessage(FreeImageErrorHandler);

	FreeImageIO io;

	io.read_proc = myReadProc;
	io.write_proc = myWriteProc;
	io.seek_proc = mySeekProc;
	io.tell_proc = myTellProc;

	FILE *file;
#ifdef _WIN32
	fopen_s(&file, filename.c_str(), "rb");
#else
	file = fopen(filename.c_str(), "rb");
#endif
	if (!file)
	{
#ifdef FREEIMAGE_LIB
		FreeImage_DeInitialise();
#endif
		err = "File not found: " + filename;
		return NULL;
	}

	FREE_IMAGE_FORMAT fif = FreeImage_GetFileTypeFromHandle(&io, (fi_handle)file, 0);

	if (fif == FIF_UNKNOWN)
	{
		fclose(file);
#ifdef FREEIMAGE_LIB
		FreeImage_DeInitialise();
#endif
		err = "Unknown image file format: " + filename;
		return NULL;
	}

	FIBITMAP *dib = FreeImage_LoadFromHandle(fif, &io, (fi_handle)file, 0);

	Image* img = Image::New((int)FreeImage_GetWidth(dib), (int)FreeImage_GetHeight(dib), (int)FreeImage_GetBPP(dib) / 8);

	unsigned char* src = (unsigned char*)FreeImage_GetBits(dib);
	int pitch = img->width * img->bpp;
	int srcpitch = FreeImage_GetPitch(dib);

	switch (img->bpp)
	{
	case 1:
		for (int y = 0; y < img->height; ++y)
			for (int x = 0; x < img->width; ++x)
			{
				int invy = img->height - y - 1;
				img->data[y * img->width + x] = src[invy * srcpitch + x];
			}
		break;

	case 3:
		for (int y = 0; y < img->height; ++y)
			for (int x = 0; x < img->width; ++x)
			{
				int invy = img->height - y - 1;
				img->data[y * pitch + x * 3 + 0] = src[invy * srcpitch + x * 3 + 2];
				img->data[y * pitch + x * 3 + 1] = src[invy * srcpitch + x * 3 + 1];
				img->data[y * pitch + x * 3 + 2] = src[invy * srcpitch + x * 3 + 0];
			}
		break;

	case 4:
		for (int y = 0; y < img->height; ++y)
			for (int x = 0; x < img->width; ++x)
			{
				int invy = img->height - y - 1;
				img->data[y * pitch + x * 4 + 0] = src[invy * srcpitch + x * 4 + 2];
				img->data[y * pitch + x * 4 + 1] = src[invy * srcpitch + x * 4 + 1];
				img->data[y * pitch + x * 4 + 2] = src[invy * srcpitch + x * 4 + 0];
				img->data[y * pitch + x * 4 + 3] = src[invy * srcpitch + x * 4 + 3];
			}
		break;

	default:
		memcpy(img->data, FreeImage_GetBits(dib), img->width * img->height * img->bpp);
	}

	FreeImage_Unload(dib);

#ifdef FREEIMAGE_LIB
	FreeImage_DeInitialise();
#endif

	return img;
}
Image* LoadImage(const uint8_t* filestream, int filestreamsize, std::string& err)
{
#ifdef FREEIMAGE_LIB
	FreeImage_Initialise();
#endif

	FreeImage_SetOutputMessage(FreeImageErrorHandler);

	FIMEMORY* memory = FreeImage_OpenMemory(const_cast<uint8_t*>(filestream), filestreamsize);
	FREE_IMAGE_FORMAT fif = FreeImage_GetFileTypeFromMemory(memory, filestreamsize);

	if (fif == FIF_UNKNOWN)
	{
#ifdef FREEIMAGE_LIB
		FreeImage_DeInitialise();
#endif
		err = "Unknown image file format";
		return NULL;
	}

	FIBITMAP *dib = FreeImage_LoadFromMemory(fif, memory, 0);
	FreeImage_CloseMemory(memory);

	Image* img = Image::New((int)FreeImage_GetWidth(dib), (int)FreeImage_GetHeight(dib), (int)FreeImage_GetBPP(dib) / 8);

	unsigned char* src = (unsigned char*)FreeImage_GetBits(dib);
	int pitch = img->width * img->bpp;
	int srcpitch = FreeImage_GetPitch(dib);

	switch (img->bpp)
	{
	case 1:
		for (int y = 0; y < img->height; ++y)
			for (int x = 0; x < img->width; ++x)
			{
				int invy = img->height - y - 1;
				img->data[y * img->width + x] = src[invy * srcpitch + x];
			}
		break;

	case 3:
		for (int y = 0; y < img->height; ++y)
			for (int x = 0; x < img->width; ++x)
			{
				int invy = img->height - y - 1;
				img->data[y * pitch + x * 3 + 0] = src[invy * srcpitch + x * 3 + 2];
				img->data[y * pitch + x * 3 + 1] = src[invy * srcpitch + x * 3 + 1];
				img->data[y * pitch + x * 3 + 2] = src[invy * srcpitch + x * 3 + 0];
			}
		break;

	case 4:
		for (int y = 0; y < img->height; ++y)
			for (int x = 0; x < img->width; ++x)
			{
				int invy = img->height - y - 1;
				img->data[y * pitch + x * 4 + 0] = src[invy * srcpitch + x * 4 + 2];
				img->data[y * pitch + x * 4 + 1] = src[invy * srcpitch + x * 4 + 1];
				img->data[y * pitch + x * 4 + 2] = src[invy * srcpitch + x * 4 + 0];
				img->data[y * pitch + x * 4 + 3] = src[invy * srcpitch + x * 4 + 3];
			}
		break;

	default:
		memcpy(img->data, FreeImage_GetBits(dib), img->width * img->height * img->bpp);
	}

	FreeImage_Unload(dib);

#ifdef FREEIMAGE_LIB
	FreeImage_DeInitialise();
#endif

	return img;
}

bool SaveImage(std::string filename, Image* img, std::string& err)
{
	FIBITMAP* Image = FreeImage_ConvertFromRawBits(img->data, img->width, img->height, img->width * img->bpp, 8 * img->bpp, 0xFF0000, 0x00FF00, 0x0000FF, false);
	return FreeImage_Save(FIF_PNG, Image, filename.c_str(), 0); //TODO: Extract file type from filename. Can we use FIF_UNKNOWN?
}

bool SaveImage(void** data, uint32_t* datasize, std::string ext, Image* img, std::string& err)
{
	err = "Not implemented";
	return NULL;
}