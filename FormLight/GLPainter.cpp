#include <vector>
#include <string>
#include <math.h>
#include "GLPainter.h"
#include "platform.h"

#ifndef ARRAYSIZE
#define ARRAYSIZE(array) (sizeof(array)/sizeof(array[0]))
#endif

const char* GLPainter::VS_SIMPLE = R"(
	attribute vec2 vpos;
	uniform mat3 WorldViewProj;
	mat4 m4(in mat3 m)
	{
		return mat4(
			m[0].xy,  0.0, m[0].z,
			m[1].xy,  0.0, m[1].z,
			0.0, 0.0, 1.0, 0.0,
			m[2].xy,  0.0, m[2].z
		);
	}
	void main()
	{
		gl_Position = m4(WorldViewProj) * vec4(vpos, 0.0, 1.0);
	}
)";
const char* GLPainter::FS_DEFAULT = R"(
	uniform vec4 color;
	void main()
	{
		gl_FragColor = color;
	}
)";
const char* GLPainter::VS_TEXTURED = R"(
	attribute vec2 vpos, vtexcoord;
	uniform mat3 WorldViewProj;
	varying vec2 uv;
	mat4 m4(in mat3 m)
	{
		return mat4(
			m[0].xy,  0.0, m[0].z,
			m[1].xy,  0.0, m[1].z,
			0.0, 0.0, 1.0, 0.0,
			m[2].xy,  0.0, m[2].z
		);
	}
	void main()
	{
		gl_Position = m4(WorldViewProj) * vec4(vpos, 0.0, 1.0);
		uv = vtexcoord;
	}
)";
const char* GLPainter::FS_TEXTURED = R"(
	uniform sampler2D Texture;
	varying vec2 uv;
	void main()
	{
		gl_FragColor = texture2D(Texture, uv);
	}
)";

GLPainter::GLPainter() :
	tex(NULL),
	//sdr("default.c", std::string()),
	sdr(err, "vf", VS_SIMPLE, FS_DEFAULT),
	sdrTextured(err, "vf", VS_TEXTURED, FS_TEXTURED),
	positionBuffer(GL.GenBuffer()),
	texcoordBuffer(GL.GenBuffer()),
	idxbuffer(GL.GenBuffer())
{
	if (!err.empty())
		printf(err.c_str());
}

GLPainter::~GLPainter()
{
}

void GLPainter::startDrawing(const Spatial& bounds)
{
	const int pw = 800, ph = 800, x = bounds.getX(), y = bounds.getY(), w = bounds.getWidth(), h = bounds.getHeight();

	Mat3Identity(&transform);
	Mat3Translate(&transform, &transform, -1.0, -1.0f); // Move coordinate system to bottom-left
	Mat3Scale(&transform, &transform, 2.0f / pw, 2.0f / ph); // Scale [0...2 | 0...2] to [0...pw | 0...ph]
	Mat3Translate(&transform, &transform, (float)x, (float)(ph - y)); // Move to top-left of parent
	Mat3Scale(&transform, &transform, 1.0f, -1.0f); // Draw top-down
	GL.Scissor(x, ph - h - y, w, h);
	GL.Enable(EnableCap::ScissorTest);

Mat4Identity(&transform4);
Mat4Translate(&transform4, &transform4, -1.0, -1.0f, 0); // Move coordinate system to bottom-left
Mat4Scale(&transform4, &transform4, 2.0f / pw, 2.0f / ph, 1); // Scale [0...2 | 0...2] to [0...pw | 0...ph]
Mat4Translate(&transform4, &transform4, (float)x, (float)(ph - y), 0); // Move to top-left of parent
Mat4Scale(&transform4, &transform4, 1.0f, -1.0f, 1); // Draw top-down
}

void GLPainter::endDrawing()
{
	GL.Disable(EnableCap::ScissorTest);
}

void GLPainter::clear(Color4 color)
{
	glClearColor(color.r, color.g, color.b, color.a);
	glClear(GL_COLOR_BUFFER_BIT);
}

void GLPainter::drawLine(Color4 color, int x1, int y1, int x2, int y2)
{
	sdr.Bind();
	GL.UniformMatrix3fv(sdr.defparams.worldviewproj, 1, false, transform);
	GL.Uniform4f(sdr.GetUniformLocation("color"), color.r, color.g, color.b, color.a);
	GL.BindBuffer(BufferTarget::ArrayBuffer, positionBuffer);
	GL.EnableClientState(ArrayCap::VertexArray);
	GL.VertexPointer(2, VertexPointerType::Float, 0, NULL);
	Vector2 positions[] = {
		Vector2(0.5f + x1, 0.5f + y1),
		Vector2(0.5f + x2, 0.5f + y2)
	};
	GL.BufferData(BufferTarget::ArrayBuffer, sizeof(positions), positions, BufferUsageHint::DynamicDraw);
	GL.DrawArrays(PrimitiveType::Lines, 0, ARRAYSIZE(positions));
}

void GLPainter::drawRectangle(Color4 color, int x, int y, int width, int height)
{
	sdr.Bind();
	GL.UniformMatrix3fv(sdr.defparams.worldviewproj, 1, false, transform);
	GL.Uniform4f(sdr.GetUniformLocation("color"), color.r, color.g, color.b, color.a);
	GL.BindBuffer(BufferTarget::ArrayBuffer, positionBuffer);
	GL.EnableClientState(ArrayCap::VertexArray);
	GL.VertexPointer(2, VertexPointerType::Float, 0, NULL);
	Vector2 positions[] = {
		Vector2(0.5f + x, 0.5f + y),
		Vector2(0.5f + x + width, 0.5f + y),
		Vector2(0.5f + x + width, 0.5f + y + height),
		Vector2(0.5f + x, 0.5f + y + height)
	};
	GL.BufferData(BufferTarget::ArrayBuffer, sizeof(positions), positions, BufferUsageHint::DynamicDraw);
	GL.DrawArrays(PrimitiveType::LineLoop, 0, ARRAYSIZE(positions));
}

void GLPainter::drawEllipse(Color4 color, int cx, int cy, int rx, int ry)
{
	float h = (rx - ry) * (rx - ry) / (float)((rx + ry) * (rx + ry));
	float p = PI * (rx + ry) * (1.0f + 3.0f * h / (10.0f + sqrtf(4.0f - 3.0f * h))); // Perimeter of ellipse
	int n = (int)ceil(p);

	std::vector<Vector2> pt(n);
	for (int i = 0; i < n; ++i)
	{
		float theta = 2.0f * PI * i / n;
		float r = rx * ry / sqrtf(pow(rx * sinf(theta), 2) + pow(ry * cosf(theta), 2));
		pt[i] = Vector2(cx + r * cosf(theta), cy + r * sinf(theta));
	}

	sdr.Bind();
	GL.UniformMatrix3fv(sdr.defparams.worldviewproj, 1, false, transform);
	GL.Uniform4f(sdr.GetUniformLocation("color"), color.r, color.g, color.b, color.a);
	GL.BindBuffer(BufferTarget::ArrayBuffer, positionBuffer);
	GL.EnableClientState(ArrayCap::VertexArray);
	GL.VertexPointer(2, VertexPointerType::Float, 0, NULL);
	GL.BufferData(BufferTarget::ArrayBuffer, (GLsizei)pt.size() * sizeof(Vector2), pt.data(), BufferUsageHint::DynamicDraw);
	GL.DrawArrays(PrimitiveType::LineLoop, 0, pt.size());
}

void GLPainter::drawImage(const Image* img, int x, int y, int width, int height)
{
	GLTexture2D* tex = GLTexture2D::FromImage(img, std::string());
	if (!tex)
		return;

	sdrTextured.Bind();
	GL.UniformMatrix3fv(sdrTextured.defparams.worldviewproj, 1, false, transform);
	GL.ActiveTexture(TextureUnit::Texture0);
	tex->Bind();
	sdrTextured.SetTexture(0);

	GL.BindBuffer(BufferTarget::ArrayBuffer, positionBuffer);
	GL.EnableClientState(ArrayCap::VertexArray);
	GL.VertexPointer(2, VertexPointerType::Float, 0, NULL);
	Vector2 positions[] = {
		Vector2(x, y),
		Vector2(x + width, y),
		Vector2(x + width, y + height),
		Vector2(x, y + height)
	};
	GL.BufferData(BufferTarget::ArrayBuffer, sizeof(positions), positions, BufferUsageHint::DynamicDraw);

	GL.EnableVertexAttribArray(sdrTextured.defattrs.texcoord);
	GL.BindBuffer(BufferTarget::ArrayBuffer, texcoordBuffer);
	GL.VertexAttribPointer(sdrTextured.defattrs.texcoord, 2, VertexAttribPointerType::Float, false, 0, 0);
	Vector2 texcoords[] = {
		Vector2(0, 0),
		Vector2(0 + 1, 0),
		Vector2(0 + 1, 0 + 1),
		Vector2(0, 0 + 1)
	};
	GL.BufferData(BufferTarget::ArrayBuffer, sizeof(texcoords), texcoords, BufferUsageHint::DynamicDraw);

	GL.DrawArrays(PrimitiveType::TriangleFan, 0, ARRAYSIZE(positions));

	tex->Dispose();
	delete tex;
}

void GLPainter::drawString(std::wstring string, IFont* _font, Color4 color, int x, int y)
{
	GLFont* font = dynamic_cast<GLFont*>(_font);
	if (font)
		font->drawString(string, color, x, y, transform, positionBuffer, texcoordBuffer, idxbuffer);
}

Vector2 GLPainter::measureString(std::wstring string, IFont* _font)
{
	GLFont* font = dynamic_cast<GLFont*>(_font);
	return font ? font->measureString(string) : Vector2(0, 0);
}

void GLPainter::fillTriangle(Color4 color, int x1, int y1, int x2, int y2, int x3, int y3)
{
	/* TODO:
	1) Draw using dynamic buffer (see below)
	2) Draw from within drawLine(), instead of deferred from draw()
	3) Bind offscreen texture target at the beginning of drawLine()
	4) Remove IDrawable interface from Painter
	5) Arbitrate between two posible targets: Control (drawLine(), etc. are called from within Control::draw() or optionally on callback onDraw(Painter ptr, bool& supressDefault) & texture (drawLine(), etc. are called by user)
	*/


	Matrix3 t(transform);
	/*Matrix4 t(
	transform._11, transform._12, 0.0, transform._13,
	transform._21, transform._22, 0.0, transform._23,
	0.0, 0.0, 1.0, 0.0,
	transform._31, transform._32, 0.0, transform._33);*/
	//Mat3Translate(&t, &t, -10, 0, 0);
	//Mat3Scale(&t, &t, 0.5f, 1, 1);

	sdr.Bind();
	GL.UniformMatrix3fv(sdr.defparams.worldviewproj, 1, false, t);
	GL.Uniform4f(sdr.GetUniformLocation("color"), color.r, color.g, color.b, color.a);
	GL.BindBuffer(BufferTarget::ArrayBuffer, positionBuffer);
	GL.EnableClientState(ArrayCap::VertexArray);
	GL.VertexPointer(2, VertexPointerType::Float, 0, NULL);
	Vector2 positions[] = {
		Vector2(50, 50),
		Vector2(0, 0),
		Vector2(100, 0)
	};
	GL.BufferData(BufferTarget::ArrayBuffer, sizeof(positions), positions, BufferUsageHint::DynamicDraw);
	GL.DrawArrays(PrimitiveType::Triangles, 0, ARRAYSIZE(positions));
}

void GLPainter::fillRectangle(Color4 color, int x, int y, int width, int height)
{
	sdr.Bind();
	GL.UniformMatrix3fv(sdr.defparams.worldviewproj, 1, false, transform);
	GL.Uniform4f(sdr.GetUniformLocation("color"), color.r, color.g, color.b, color.a);
	GL.BindBuffer(BufferTarget::ArrayBuffer, positionBuffer);
	GL.EnableClientState(ArrayCap::VertexArray);
	GL.VertexPointer(2, VertexPointerType::Float, 0, NULL);
	Vector2 positions[] = {
		Vector2(x, y),
		Vector2(x + width, y),
		Vector2(x + width, y + height),
		Vector2(x, y + height)
	};
	GL.BufferData(BufferTarget::ArrayBuffer, sizeof(positions), positions, BufferUsageHint::DynamicDraw);
	
	/*GL.EnableVertexAttribArray(sdr.defattrs.texcoord);
	GL.BindBuffer(BufferTarget::ArrayBuffer, texcoordBuffer);
	GL.VertexAttribPointer(sdr.defattrs.texcoord, 2, VertexAttribPointerType::Float, false, 0, 0);
	Vector2 texcoords[] = {
		Vector2(0, 0),
		Vector2(1, 0),
		Vector2(1, 1),
		Vector2(0, 1)
	};
	GL.BufferData(BufferTarget::ArrayBuffer, sizeof(texcoords), texcoords, BufferUsageHint::DynamicDraw);*/
	
	GL.DrawArrays(PrimitiveType::TriangleFan, 0, ARRAYSIZE(positions));
}

void GLPainter::fillArc(Color4 color, int cx, int cy, int rx, int ry, float startAngle, float sweepAngle)
{
	startAngle = fmodf(startAngle, 360.0f) * PI / 180.0f; // Keep startAngle within 0...2PI
	sweepAngle = fmaxf(0.0f, fminf(1.0f, sweepAngle / 360.0f)); // Scale sweepAngle to 0...1

	float h = (rx - ry) * (rx - ry) / (float)((rx + ry) * (rx + ry));
	float p = PI * (rx + ry) * (1.0f + 3.0f * h / (10.0f + sqrtf(4.0f - 3.0f * h))); // Perimeter of ellipse
	int n = (int)ceil(p), n2 = sweepAngle * n;

	std::vector<Vector2> pt(n2 + 2);
	pt[0] = Vector2(cx, cy);
	for (int i = 0; i <= n2;)
	{
		//float theta = startAngle + 2.0f * PI * i / n; // Deprecated version: Less accurate
		float theta = startAngle + 2.0f * PI * sweepAngle * i / n2;
		float r = rx * ry / sqrtf(pow(rx * sinf(theta), 2) + pow(ry * cosf(theta), 2));
		pt[++i] = Vector2(cx + r * cosf(theta), cy + r * sinf(theta));
	}

	sdr.Bind();
	GL.UniformMatrix3fv(sdr.defparams.worldviewproj, 1, false, transform);
	GL.Uniform4f(sdr.GetUniformLocation("color"), color.r, color.g, color.b, color.a);
	GL.BindBuffer(BufferTarget::ArrayBuffer, positionBuffer);
	GL.EnableClientState(ArrayCap::VertexArray);
	GL.VertexPointer(2, VertexPointerType::Float, 0, NULL);
	GL.BufferData(BufferTarget::ArrayBuffer, pt.size() * sizeof(Vector2), pt.data(), BufferUsageHint::DynamicDraw);
	GL.DrawArrays(PrimitiveType::TriangleFan, 0, pt.size());
}

bool Drawing::init(const Graphics* gfx, std::string& err)
{
	if (gfx != NULL && gfx->settings.type != Graphics::Settings::OPENGL)
	{
		err = "OpenGL drawing requires OpenGL graphics";
		return false;
	}
	//GL.CullFace(CullFaceMode::FrontAndBack);
	GL.Enable(EnableCap::DepthTest);
	//glClearColor(0.2f, 0.5f, 0.6f, 1.0f);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	GL.Disable(EnableCap::DepthTest);
	GL.Disable(EnableCap::CullFace);
	GL.Enable(EnableCap::Blend);
	GL.BlendEquationSeparate(BlendEquationMode::FuncAdd, BlendEquationMode::FuncAdd);
	//GL.BlendFuncSeparate(gl.SRC_ALPHA, gl.ONE_MINUS_SRC_ALPHA, gl.ONE, gl.ONE);
	GL.BlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	return true;
}

Painter* Drawing::createPainter(std::string& err)
{
	return new GLPainter();
}
