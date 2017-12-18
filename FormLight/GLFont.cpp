#include <vector>
#include <string>
#include <math.h>
#include "GLPainter.h"
#include "Image.h"
#include "sqlite3.h"

#pragma comment(lib, "sqlite3.lib")

const char* VS_TEXTURED_2 = R"(
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
const char* FS_TEXTURED_2 = R"(
	uniform sampler2D Texture;
	uniform float invTextureWidth;
	varying vec2 uv;
	void main()
	{
		// Standard font rendering
		//gl_FragColor = texture2D(Texture, uv);
		
		// Experimental
		float x = uv.x / invTextureWidth;
		float f = fract(x);
		float u = uv.x;//floor(x) * invTextureWidth;
		if (f < 0.333)
			gl_FragColor = vec4(0.0, 0.0, 0.0, 1.0) * texture2D(Texture, vec2(u, uv.y)).r;
		else if (f < 0.666)
			gl_FragColor = vec4(0.0, 0.0, 0.0, 1.0) * texture2D(Texture, vec2(u, uv.y)).g;
		else
			gl_FragColor = vec4(0.0, 0.0, 0.0, 1.0) * texture2D(Texture, vec2(u, uv.y)).b;
		
		/*// Simulated clear-type
		float r = texture2D(Texture, vec2(uv.x - invTextureWidth / 3.0, uv.y)).a;
		float g = texture2D(Texture, uv).a;
		float b = texture2D(Texture, vec2(uv.x + invTextureWidth / 3.0, uv.y)).a;
		//gl_FragColor = vec4(1.0 - g - b, 1.0 - r - b, 1.0 - r - g, max(max(r, g), b)); // Method 1
		//gl_FragColor = vec4(1.0 - g - b, 1.0 - r - b, 1.0 - r - g, (r + g + b) / 3.0); // Method 2
		float scale = 1.0 / max(max(g + b, r + b), r + g);
		gl_FragColor = vec4((1.0 - g - b) * scale, (1.0 - r - b) * scale, (1.0 - r - g) * scale, (r + g + b) / 3.0); // Method 3*/
	}
)";

sqlite3* GLFont::db = NULL;
GLShader* GLFont::sdrDrawText = NULL;

bool GLFont::loadFontDatabase(std::string& err)
{
	if (sqlite3_open_v2("fonts.sqlite", &db, SQLITE_OPEN_READONLY, NULL) != SQLITE_OK)
	{
		sqlite3_close(db);
		err = sqlite3_errmsg(db);
		return false;
	}
	return true;
}

bool GLFont::loadFontShader(std::string& err)
{
	sdrDrawText = new GLShader(err, "vf", VS_TEXTURED_2, FS_TEXTURED_2);
	return err.empty();
}

bool GLFont::loadCharacter(int code, int* rectX, int* rectY, int* rectWidth, int* rectHeight, float* advanceX)
{
	*rectX = *rectY = *rectWidth = *rectHeight = 0;
	*advanceX = 0.0f;
	sqlite3_stmt* stmt;

	// Compile SQL statement string into SQLite prepared statement
	const char* query = "SELECT * FROM character WHERE family = \"Microsoft Sans Serif\" AND size = 10 AND code = ?";
	if (sqlite3_prepare_v2(db, query, (int)strlen(query) + 1, &stmt, NULL) != SQLITE_OK)
	{
		sqlite3_finalize(stmt);
		return false;
	}
	sqlite3_bind_int(stmt, 1, code);

	if (sqlite3_step(stmt) != SQLITE_ROW)
	{
		sqlite3_finalize(stmt);
		return false;
	}

	*rectX = sqlite3_column_int(stmt, 3);
	*rectY = sqlite3_column_int(stmt, 4);
	*rectWidth = sqlite3_column_int(stmt, 5);
	*rectHeight = sqlite3_column_int(stmt, 6);
	*advanceX = (float)sqlite3_column_double(stmt, 7);

	// Release prepared statement
	sqlite3_finalize(stmt);
	return true;
}

GLFont::GLFont(std::string family, float size, Image* img, int baseline)
	: IFont(family, size), img(img), baseline(baseline)
{
	std::string err;
	tex = GLTexture2D::FromImage(img, err);
//	tex->Bind();
//	GL.TexParameter(TextureTarget::Texture2D, TextureParameterName::TextureMinFilter, TextureMagFilter::Linear);
//	GL.TexParameter(TextureTarget::Texture2D, TextureParameterName::TextureMagFilter, TextureMagFilter::Linear);
}
GLFont::~GLFont()
{
	if (img)
	{
		delete img;
		img = NULL;
	}
	if (tex)
	{
		tex->Dispose();
		delete tex;
		tex = NULL;
	}
}

GLFont* GLFont::loadFont(std::string family, float size, std::string& err)
{
	if ((!db && !loadFontDatabase(err)) || (!sdrDrawText && !loadFontShader(err)))
		return NULL;
	
	sqlite3_stmt* stmt;

	// Compile SQL statement string into SQLite prepared statement
	const char* query = "SELECT * FROM font WHERE family = \"Microsoft Sans Serif\" AND size = 10";
	if (sqlite3_prepare_v2(db, query, (int)strlen(query) + 1, &stmt, NULL) != SQLITE_OK)
	{
		err = "Error querying font from font database";
		sqlite3_finalize(stmt);
		return NULL;
	}

	if (sqlite3_step(stmt) != SQLITE_ROW)
	{
		err = "Font not found";
		sqlite3_finalize(stmt);
		return NULL;
	}

	uint8_t* map = (uint8_t*)sqlite3_column_blob(stmt, 2);
	int mapSize = sqlite3_column_bytes(stmt, 2);
	Image* img = LoadImage(map, mapSize, err);
	if (!err.empty())
		return NULL;
	int baseline = sqlite3_column_int(stmt, 3);

	// Release prepared statement
	sqlite3_finalize(stmt);
	
	return new GLFont(family, size, img, baseline);
}

void GLFont::drawString(std::wstring string, Color4 color, int x, int y, const Matrix3& transform, const int positionBuffer, const int texcoordBuffer, const int idxbuffer)
{
	Vector2 *positions = new Vector2[4 * string.size()], *texcoords = new Vector2[4 * string.size()];
	uint32_t* indices = new uint32_t[6 * string.size()];
	const uint32_t quadIndices[6] = { 0,1,2, 2,3,0 };
	float xf = (float)x;
	for (size_t i = 0; i < string.size(); ++i)
	{
		wchar_t chr = string.c_str()[i];
		if (chr == L'\r')
		{
			xf = (float)x;
			y += (int)(size * 1.5f);
		}

		int rectX, rectY, rectWidth, rectHeight;
		float advanceX;
		if(!loadCharacter(chr, &rectX, &rectY, &rectWidth, &rectHeight, &advanceX))
			continue; // Skip unknown character
		++rectX;
		++rectY;
		--rectWidth;
		--rectHeight;

		positions[4 * i + 0] = Vector2(xf, (float)y);
		positions[4 * i + 1] = Vector2(xf + rectWidth, (float)y);
		positions[4 * i + 2] = Vector2(xf + rectWidth, (float)y + rectHeight);
		positions[4 * i + 3] = Vector2(xf, (float)y + rectHeight);

		float u = (float)rectX / tex->width, v = (float)rectY / tex->height, u2 = (float)(rectX + rectWidth) / tex->width, v2 = (float)(rectY + rectHeight) / tex->height;
		texcoords[4 * i + 0] = Vector2(u, v);
		texcoords[4 * i + 1] = Vector2(u2, v);
		texcoords[4 * i + 2] = Vector2(u2, v2);
		texcoords[4 * i + 3] = Vector2(u, v2);

		for (size_t j = 0; j < 6; ++j)
			indices[6 * i + j] = 4 * (uint32_t)i + quadIndices[j];

		//xf += rectWidth;
		xf += advanceX;
	}

	sdrDrawText->Bind();
	GL.UniformMatrix3fv(sdrDrawText->defparams.worldviewproj, 1, false, transform);
	GL.Uniform1f(sdrDrawText->GetUniformLocation("invTextureWidth"), 1.0f / tex->width);
	GL.ActiveTexture(TextureUnit::Texture0);
	tex->Bind();
	sdrDrawText->SetTexture(0);

	GL.BindBuffer(BufferTarget::ArrayBuffer, positionBuffer);
	GL.EnableClientState(ArrayCap::VertexArray);
	GL.VertexPointer(2, VertexPointerType::Float, 0, NULL);
	GL.BufferData(BufferTarget::ArrayBuffer, 4 * string.size() * sizeof(Vector2), positions, BufferUsageHint::DynamicDraw);

	GL.EnableVertexAttribArray(sdrDrawText->defattrs.texcoord);
	GL.BindBuffer(BufferTarget::ArrayBuffer, texcoordBuffer);
	GL.VertexAttribPointer(sdrDrawText->defattrs.texcoord, 2, VertexAttribPointerType::Float, false, 0, 0);
	GL.BufferData(BufferTarget::ArrayBuffer, 4 * string.size() * sizeof(Vector2), texcoords, BufferUsageHint::DynamicDraw);

	GL.BindBuffer(BufferTarget::ElementArrayBuffer, idxbuffer);
	GL.BufferData(BufferTarget::ElementArrayBuffer, 6 * string.size() * sizeof(uint32_t), indices, BufferUsageHint::DynamicDraw);

	//GL.DrawArrays(PrimitiveType::Triangles, 0, 2 * string.size());
	GL.DrawElements(PrimitiveType::Triangles, 6 * (int)string.size(), DrawElementsType::UnsignedInt, (GLvoid*)0);

	delete[] positions;
	delete[] texcoords;
	delete[] indices;
}

Vector2 GLFont::measureString(std::wstring string)
{
	float x = 0.0f;
	int y = (int)(size * 1.5f);
	for (size_t i = 0; i < string.size(); ++i)
	{
		wchar_t chr = string.c_str()[i];
		if (chr == L'\r')
		{
			x = 0.0f;
			y += (int)(size * 1.5f);
		}

		int rectX, rectY, rectWidth, rectHeight;
		float advanceX;
		if (!loadCharacter(chr, &rectX, &rectY, &rectWidth, &rectHeight, &advanceX))
			continue; // Skip unknown character
		++rectX;
		++rectY;
		--rectWidth;
		--rectHeight;

		//x += rectWidth;
		x += advanceX;
	}
	return Vector2(x, (float)y);
}

/*void GLFont::closeFontDatabase()
{
	if (db)
	{
		sqlite3_close(db);
		db = NULL;
	}
}*/

IFont* Drawing::createFont(std::string family, float size, std::string& err)
{
	return GLFont::loadFont(family, size, err);
}
