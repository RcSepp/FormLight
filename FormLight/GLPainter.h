#pragma once
#ifndef __GLPAINTER_H
#define __GLPAINTER_H

#include "controls.h"
#include "GLTexture.h"
#include "GLMesh.h"

struct sqlite3;
struct Image;

class GLFont : public IFont
{
private:
	static sqlite3* db;
	static GLShader* sdrDrawText;
	Image* img;
	int baseline;
	GLTexture* tex;
	
	static bool loadFontDatabase(std::string& err);
	static bool loadFontShader(std::string& err);
	static bool loadCharacter(int code, int* rectX, int* rectY, int* rectWidth, int* rectHeight, float* advanceX);
	GLFont(std::string family, float size, Image* img, int baseline);
	
public:
	
	~GLFont();
	static GLFont* loadFont(std::string family, float size, std::string& err);
	void drawString(std::wstring string, Color4 color, int x, int y, const Matrix3& transform, const int positionBuffer, const int texcoordBuffer, const int idxbuffer);
	Vector2 measureString(std::wstring string);
};

class GLPainter : public Painter
{
private:
	std::string err;
	GLTexture* tex;
	GLShader sdr, sdrTextured;
	const int positionBuffer, texcoordBuffer, idxbuffer;
	Matrix3 transform;
	Matrix4 transform4;
	
	static const char *VS_SIMPLE, *FS_DEFAULT, *VS_TEXTURED, *FS_TEXTURED;

public:
	GLPainter();
	~GLPainter();

	void startDrawing(const Spatial& bounds);
	void endDrawing();

	void clear(Color4 color);
	void drawLine(Color4 color, int x1, int y1, int x2, int y2);
	void drawRectangle(Color4 color, int x, int y, int width, int height);
	void drawEllipse(Color4 color, int cx, int cy, int rx, int ry);
	void drawImage(const Image* img, int x, int y, int width, int height);
	void drawString(std::wstring string, IFont* font, Color4 color, int x, int y);
	Vector2 measureString(std::wstring string, IFont* font);
	void fillTriangle(Color4 color, int x1, int y1, int x2, int y2, int x3, int y3);
	void fillRectangle(Color4 color, int x, int y, int width, int height);
	void fillArc(Color4 color, int cx, int cy, int rx, int ry, float startAngle = 0.0f, float sweepAngle = 360.0f);
};


#endif