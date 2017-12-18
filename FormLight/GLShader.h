#pragma once
#ifndef __GLSHADER_H
#define __GLSHADER_H

#include <cstdarg>
#include <string>
#include <fstream>
#include <string.h>
#include "VectorMatrix.h"
#include "File.h"
#ifdef _WIN32
#include <GL/glut.h>
#include "glext.h"
#else
#include <GL/gl.h>
#include <GL/glx.h>
#endif
#include "GLX.h"

#ifdef _WIN32
typedef ULARGE_INTEGER _TIME;
#define _TIME_EQUALS(t0, t1) ((t0).QuadPart == (t1).QuadPart)
#else
typedef time_t _TIME;
#define _TIME_EQUALS(t0, t1) ((t0) == (t1))
#endif

class GLShader
{
private:
	int shaderprogram, vertexshader, fragmentshader, geometryshader;
public:
	int GetShaderProgram() { return shaderprogram; };
	struct DefaultParameters
	{
		int world, worldarray, view, proj, viewproj, worldviewproj, worldviewprojarray, worldinvtrans, worldinvtransarray, textransform; // Matrices
		int viewpos, ambient, diffuse, specular; // Vectors
		int numlights, lightparams, power; // Light parameters
		int tex[4]; // Textures
		int hastex, time; // Misc
	};
	DefaultParameters defparams;
	struct DefaultAttributes
	{
		int pos, nml, texcoord, blendidx;
	};
	DefaultAttributes defattrs;

	GLShader(std::string filename, std::string& err)
	{
		if (filename.empty())
		{
			err = "Parameter filename is empty";
			return;
		}
		if (!File::Exists(filename))
		{
			err = "File not found: " + filename;
			return;
		}

		// Get modification time of effect file
		_TIME writetime;
		if (!File::GetLastWriteTime(filename, &writetime))
		{
			err = "Error trying to open file " + filename;
			return;
		}

		// >>> Create effect

		// If a precompiled effect file is found, use the precompiled effect
		bool compileshader = true;
#ifdef _DEBUG
		std::string compiledfilename = filename + "c_d";
#else
		std::string compiledfilename = filename + "c";
#endif
		if (File::Exists(compiledfilename))
		{
			_TIME compiledwritetime;
			std::ifstream compiledfile(compiledfilename, std::ios::in | std::ios::binary);
			compiledfile.read((char*)&compiledwritetime, sizeof(_TIME));
			if (_TIME_EQUALS(compiledwritetime, writetime))
			{
				// bufsize = end_pos - current_pos
				std::streamsize bufpos = compiledfile.tellg();
				compiledfile.seekg(0, std::ios::end);
				std::streamsize bufsize = (std::streampos)compiledfile.tellg() - (std::streampos)bufpos;
				compiledfile.seekg(bufpos, std::ios::beg);
				//EDIT: Check that bufsize is at least sizeof(GLenum)

				GLenum compiledshaderformat;
				compiledfile.read((char*)&compiledshaderformat, sizeof(GLenum));
				char* compiledshaderbytes = new char[bufsize - sizeof(GLenum)];
				compiledfile.read(compiledshaderbytes, bufsize - sizeof(GLenum));
				compiledfile.close();
				shaderprogram = GLX.glCreateProgram();
				GLX.glProgramBinary(shaderprogram, compiledshaderformat, compiledshaderbytes, (GLsizei)(bufsize - sizeof(GLenum)));
				delete[] compiledshaderbytes;
				int isLinked;
				GLX.glGetProgramiv(shaderprogram, GL_LINK_STATUS, (int*)&isLinked);
				if (isLinked)
					compileshader = false;
			}
			else
				compiledfile.close();
		}

		// If a precompiled effect file wasn't found, compile the effect
		if (compileshader)
		{
			std::ifstream shaderfile(filename, std::ios::in | std::ios_base::binary);
			shaderfile.seekg(0, std::ios::end);
			std::streamsize bufsize = shaderfile.tellg();
			shaderfile.seekg(0, std::ios::beg);
			char* shaderstr = new char[bufsize + 1];
			shaderfile.read(shaderstr, bufsize);
			shaderstr[bufsize] = '\0';
			shaderfile.close();

			// Get #vs and #fs sections from shaderstr
			// output = {vsstart, fsstart}
			const char *vsstart = NULL, *fsstart = NULL;
			const int BUF_LENGTH = 4;
			char buf[BUF_LENGTH], *c = shaderstr;
			int buflen = 0;
			while (*c != '\0')
			{
				for (int i = BUF_LENGTH - buflen; i < BUF_LENGTH; ++i)
					buf[i - 1] = buf[i];
				buf[BUF_LENGTH - 1] = *c++;
				if (buflen < BUF_LENGTH - 1)
					++buflen;
				else if (memcmp(buf, "#vs\n", 4) == 0 || memcmp(buf, "#vs\r", 4) == 0)
				{
					if (vsstart)
						printf("Warning: More than one #vs section defined. Using only first section\n");
					else
						vsstart = c;
					c[-BUF_LENGTH] = '\0';
				}
				else if (memcmp(buf, "#fs\n", 4) == 0 || memcmp(buf, "#fs\r", 4) == 0)
				{
					if (fsstart)
						printf("Warning: More than one #fs section defined. Using only first section\n");
					else
						fsstart = c;
					c[-BUF_LENGTH] = '\0';
				}
			}

			if (!vsstart)
			{
				delete[] shaderstr;
				err = "No vertex shader section (#vs) defined in shader file " + filename;
				return;
			}
			if (!fsstart)
			{
				delete[] shaderstr;
				err = "No fragment shader section (#fs) defined in shader file " + filename;
				return;
			}

			int isCompiled_VS, isCompiled_FS, isLinked;
			vertexshader = GLX.glCreateShader(GL_VERTEX_SHADER);
			GLX.glShaderSource(vertexshader, 1, (const char**)&vsstart, NULL);
			GLX.glCompileShader(vertexshader);
			GLX.glGetShaderiv(vertexshader, GL_COMPILE_STATUS, &isCompiled_VS);
			if (!isCompiled_VS)
			{
				int maxLength;
				GLX.glGetShaderiv(vertexshader, GL_INFO_LOG_LENGTH, &maxLength);
				char* vertexInfoLog = new char[maxLength];
				GLX.glGetShaderInfoLog(vertexshader, maxLength, &maxLength, vertexInfoLog);

				//EDIT: Manually offset error line numbers in vertexInfoLog

				err = "Error compiling vertex shader:\n" + std::string(vertexInfoLog);
				delete[] vertexInfoLog;
				delete[] shaderstr;
				return;
			}

			fragmentshader = GLX.glCreateShader(GL_FRAGMENT_SHADER);
			GLX.glShaderSource(fragmentshader, 1, (const char**)&fsstart, NULL);
			GLX.glCompileShader(fragmentshader);
			GLX.glGetShaderiv(fragmentshader, GL_COMPILE_STATUS, &isCompiled_FS);
			if (!isCompiled_FS)
			{
				int maxLength;
				GLX.glGetShaderiv(fragmentshader, GL_INFO_LOG_LENGTH, &maxLength);
				char* fragmentInfoLog = new char[maxLength];
				GLX.glGetShaderInfoLog(fragmentshader, maxLength, &maxLength, fragmentInfoLog);

				//EDIT: Manually offset error line numbers in fragmentInfoLog

				err = "Error compiling fragment shader:\n" + std::string(fragmentInfoLog);
				delete[] fragmentInfoLog;
				delete[] shaderstr;
				return;
			}

			delete[] shaderstr;

			shaderprogram = GLX.glCreateProgram();
			GLX.glAttachShader(shaderprogram, vertexshader);
			GLX.glAttachShader(shaderprogram, fragmentshader);
			GLX.glProgramParameteri(shaderprogram, GL_PROGRAM_BINARY_RETRIEVABLE_HINT, GL_TRUE);
			GLX.glLinkProgram(shaderprogram);
			GLX.glGetProgramiv(shaderprogram, GL_LINK_STATUS, (int*)&isLinked);
			if (!isLinked)
			{
				int maxLength;
				GLX.glGetProgramiv(shaderprogram, GL_INFO_LOG_LENGTH, &maxLength);
				char* shaderProgramInfoLog = new char[maxLength];
				GLX.glGetProgramInfoLog(shaderprogram, maxLength, &maxLength, shaderProgramInfoLog);

				err = "Error clinking shader program:\n" + std::string(shaderProgramInfoLog);
				delete[] shaderProgramInfoLog;
				return;
			}

			// Get compiled effect binary
			GLint binarylength;
			GLenum binaryformat;
			char* binary;
			bool storecompiledeffect = false;
			GLX.glGetProgramiv(shaderprogram, GL_PROGRAM_BINARY_LENGTH, &binarylength);
			if (binarylength == 0)
			{
				// If GL_PROGRAM_BINARY_LENGTH does not succeed, allocate 1MB
				binary = new char[binarylength = 1024 * 1024];
				GLX.glGetProgramBinary(shaderprogram, binarylength, &binarylength, &binaryformat, binary);
				storecompiledeffect = (binarylength != 0 && binaryformat != 0);
			}
			else
			{
				binary = new char[binarylength];
				GLX.glGetProgramBinary(shaderprogram, binarylength, NULL, &binaryformat, binary);
				storecompiledeffect = true;
			}

			if (storecompiledeffect)
			{
				// Store compiled effect in a compiled effect file
				std::ofstream compiledfile(compiledfilename, std::ios::out | std::ios::binary);
				compiledfile.write((char*)&writetime, sizeof(_TIME));
				compiledfile.write((char*)&binaryformat, sizeof(GLenum));
				compiledfile.write(binary, binarylength);
				compiledfile.close();
				delete[] binary;
			}
		}

		GetDefaults();
	}

	GLShader(std::string& err, const char* shaderTypes, ...)
	{
		int nvs = 0, nfs = 0, ngs = 0;
		for (const char* c = shaderTypes; *c; ++c)
			switch (*c)
			{
			case 'v': ++nvs; break;
			case 'f': case 'p': ++nfs; break;
			case 'g': ++ngs; break;
			default:
				err = std::string("Invalid character in shaderTypes string: '") + *c + "' Must be one of {'v', 'f', or 'g'}";
				return;
			}
		const char **vs = new const char*[nvs], **fs = new const char*[nfs], **gs = new const char*[ngs];
		va_list args;
		va_start(args, shaderTypes);
		nvs = nfs = ngs = 0;
		for (const char* c = shaderTypes; *c; ++c)
			switch (*c)
			{
			case 'v': vs[nvs++] = va_arg(args, const char*); break;
			case 'f': case 'p': fs[nfs++] = va_arg(args, const char*); break;
			case 'g': gs[ngs++] = va_arg(args, const char*); break;
			}
		va_end(args);

		// Compile vertex shader
		int isCompiled;
		vertexshader = GL.CreateShader(ShaderType::VertexShader);
		GL.ShaderSource(vertexshader, nvs, vs, NULL);
		GL.CompileShader(vertexshader);
		GL.GetShaderiv(vertexshader, ShaderParameter::CompileStatus, &isCompiled);
		if (isCompiled == 0)
		{
			err = std::string("Error compiling vertex shader:\n") + GL.GetShaderInfoLog(vertexshader);
			return;
		}

		// Compile fragment shader
		fragmentshader = GL.CreateShader(ShaderType::FragmentShader);
		GL.ShaderSource(fragmentshader, nfs, fs, NULL);
		GL.CompileShader(fragmentshader);
		GL.GetShaderiv(fragmentshader, ShaderParameter::CompileStatus, &isCompiled);
		if (isCompiled == 0)
		{
			err = std::string("Error compiling fragment shader:\n") + GL.GetShaderInfoLog(fragmentshader);
			return;
		}

		if (ngs)
		{
			// Compile geometry shader
			geometryshader = GL.CreateShader(ShaderType::GeometryShader);
			GL.ShaderSource(geometryshader, ngs, gs, NULL);
			GL.CompileShader(geometryshader);
			GL.GetShaderiv(geometryshader, ShaderParameter::CompileStatus, &isCompiled);
			if (isCompiled == 0)
			{
				err = std::string("Error compiling geometry shader:\n") + GL.GetShaderInfoLog(geometryshader);
				return;
			}
		}

		int isLinked;
		shaderprogram = GL.CreateProgram();
		GL.AttachShader(shaderprogram, vertexshader);
		GL.AttachShader(shaderprogram, fragmentshader);
		if (ngs)
		{
			GL.ProgramParameteri(shaderprogram, 0x8DDA, 4);
			GL.ProgramParameteri(shaderprogram, 0x8DDB, 0);
			GL.ProgramParameteri(shaderprogram, 0x8DDC, 7);
			GL.AttachShader(shaderprogram, geometryshader);
		}
		//if (Global.OPENGL_VERSION >= 4.1m)
		//	GL.ProgramParameteri(shaderprogram, ProgramParameterName::ProgramBinaryRetrievableHint, 1);
		GL.LinkProgram(shaderprogram);
		GL.GetProgramiv(shaderprogram, GetProgramParameterName::LinkStatus, &isLinked);
		if (isLinked == 0)
		{
			err = std::string("Error linking shader program:\n") + GL.GetProgramInfoLog(shaderprogram);
			return;
		}

		GetDefaults();
	}

private:
	void GetDefaults()
	{
		// >>> Obtain default parameters

		defparams.world = GLX.glGetUniformLocation(shaderprogram, "World");
		defparams.worldarray = GLX.glGetUniformLocation(shaderprogram, "WorldArray");
		defparams.view = GLX.glGetUniformLocation(shaderprogram, "View");
		defparams.proj = GLX.glGetUniformLocation(shaderprogram, "Proj");
		defparams.viewproj = GLX.glGetUniformLocation(shaderprogram, "ViewProj");
		defparams.worldviewproj = GLX.glGetUniformLocation(shaderprogram, "WorldViewProj");
		defparams.worldviewprojarray = GLX.glGetUniformLocation(shaderprogram, "WorldViewProjArray");
		defparams.worldinvtrans = GLX.glGetUniformLocation(shaderprogram, "WorldInvTrans");
		defparams.worldinvtransarray = GLX.glGetUniformLocation(shaderprogram, "WorldInvTransArray");
		defparams.textransform = GLX.glGetUniformLocation(shaderprogram, "TextureTransform");

		defparams.viewpos = GLX.glGetUniformLocation(shaderprogram, "ViewPos");
		defparams.ambient = GLX.glGetUniformLocation(shaderprogram, "Ambient");
		defparams.diffuse = GLX.glGetUniformLocation(shaderprogram, "Diffuse");
		defparams.specular = GLX.glGetUniformLocation(shaderprogram, "Specular");

		defparams.numlights = GLX.glGetUniformLocation(shaderprogram, "NumLights");
		defparams.lightparams = GLX.glGetUniformLocation(shaderprogram, "LightParams");
		defparams.power = GLX.glGetUniformLocation(shaderprogram, "Power");

		defparams.tex[0] = GLX.glGetUniformLocation(shaderprogram, "Texture");
		defparams.tex[1] = GLX.glGetUniformLocation(shaderprogram, "Texture2");
		defparams.tex[2] = GLX.glGetUniformLocation(shaderprogram, "Texture3");
		defparams.tex[3] = GLX.glGetUniformLocation(shaderprogram, "Texture4");
		defparams.hastex = GLX.glGetUniformLocation(shaderprogram, "HasTexture");

		defparams.time = GLX.glGetUniformLocation(shaderprogram, "Time");

		// >>> Obtain default vertex attributes

		defattrs.pos = GLX.glGetAttribLocation(shaderprogram, "vpos");
		defattrs.nml = GLX.glGetAttribLocation(shaderprogram, "vnml");
		defattrs.texcoord = GLX.glGetAttribLocation(shaderprogram, "vtexcoord");
		defattrs.blendidx = GLX.glGetAttribLocation(shaderprogram, "vblendidx");
	}

public:
	void Bind()
	{
		GLX.glUseProgram(shaderprogram);
	}
	void Bind(Matrix4 worldmatrix)
	{
		GLX.glUseProgram(shaderprogram);

		if (defparams.world != -1)
			GLX.glUniformMatrix4fv(defparams.world, 16, false, worldmatrix);
		if (defparams.worldinvtrans != -1)
		{
			Matrix4 worldinvtrans = Matrix4::Invert(worldmatrix);
			GLX.glUniformMatrix4fv(defparams.worldinvtrans, 16, true, worldinvtrans);
		}
		//if(defparams.viewpos)
		//	glUniform3(defparams.viewpos, cam.pos);
	}

	void SetTexture(int texidx = 0)
	{
		if (defparams.tex[texidx] != -1)
			GLX.glUniform1i(defparams.tex[texidx], texidx);
	}

	int GetUniformLocation(std::string name) const
	{
		return GLX.glGetUniformLocation(shaderprogram, name.c_str());
	}
};

class GLUniform
{
protected:
	const int location;

public:
	GLUniform(GLShader sdr, std::string name, std::string& err)
		: location(GLX.glGetUniformLocation(sdr.GetShaderProgram(), name.c_str()))
	{
		if (location < 0)
			err = "Uniform location '" + name + "' could not be resolved";
	}
};
class GLUniformVector3 : public GLUniform
{
public:
	GLUniformVector3(GLShader sdr, std::string name, std::string& err)
		: GLUniform(sdr, name, err) {}
	void Set(Vector3 value) { GLX.glUniform3f(location, value.x, value.y, value.z); }
};

#endif