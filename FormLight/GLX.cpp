#ifdef _WIN32
#include <GL/glut.h>
#include "glext.h"
#else
#include<GL/gl.h>
#include<GL/glx.h>
#endif
#include "GLX.h"

OpenGLExtensions GLX;

#ifdef _WIN32
#define glGetProcAddress(str) wglGetProcAddress(str)
#else
#define glGetProcAddress(str) glXGetProcAddress((const GLubyte*)str)
#endif

bool OpenGLExtensions::Query(DisplayHandle display, DeviceContext devicectx)
{
	if (queried)
		return true;

#ifdef _WIN32
	// Create temporary window class
	WNDCLASS wndcls;
	/*wndcls.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wndcls.lpfnWndProc = DefWindowProc;
	wndcls.hInstance = GetModuleHandle(0);
	wndcls.lpszClassName = "WGL_dummy_window_class";
	if (!RegisterClass(&wndcls))
		return false;*/
	GetClassInfo(GetModuleHandle(nullptr), "DefaultWinClass", &wndcls);

	// Create temporary window
	HWND wnd = CreateWindowExA(0, wndcls.lpszClassName, "Dummy OpenGL Window", 0, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, wndcls.hInstance, 0);
	if (!wnd)
		return false;
	HDC hdc = GetDC(wnd);

	// Set temporary pixel format
	PIXELFORMATDESCRIPTOR pfd;
	pfd.nSize = sizeof(pfd);
	pfd.nVersion = 1;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.cColorBits = 32;
	pfd.cAlphaBits = 8;
	pfd.iLayerType = PFD_MAIN_PLANE;
	pfd.cDepthBits = 24;
	pfd.cStencilBits = 8;
	int pixelformat = ChoosePixelFormat(hdc, &pfd);
	if (!pixelformat)
		return false;
	if (!SetPixelFormat(hdc, pixelformat, &pfd))
		return false;

	// Create temporary rendering context
	RenderContext renderctx = wglCreateContext(hdc);

	// Set the temporary rendering context as the current rendering context for this window
	int error = wglMakeCurrent(hdc, renderctx);
	if (error != 1)
		return false;
#else
	// Create temporary rendering context
	GLint att[] = { GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None };
	XVisualInfo* vi = glXChooseVisual(display, 0, att);
	RenderContext renderctx = glXCreateContext(display, vi, NULL, GL_TRUE);

	// Set the temporary rendering context as the current rendering context for this window
	glXMakeCurrent(display, devicectx, renderctx);
#endif

	glGenBuffers = (PFNGLGENBUFFERSPROC)glGetProcAddress("glGenBuffers");
	glBindBuffer = (PFNGLBINDBUFFERPROC)glGetProcAddress("glBindBuffer");
	glBufferData = (PFNGLBUFFERDATAPROC)glGetProcAddress("glBufferData");
	glDeleteBuffers = (PFNGLDELETEBUFFERSPROC)glGetProcAddress("glDeleteBuffers");

	glCreateProgram = (PFNGLCREATEPROGRAMPROC)glGetProcAddress("glCreateProgram");
	glDeleteProgram = (PFNGLDELETEPROGRAMPROC)glGetProcAddress("glDeleteProgram");
	glUseProgram = (PFNGLUSEPROGRAMPROC)glGetProcAddress("glUseProgram");
	glAttachShader = (PFNGLATTACHSHADERPROC)glGetProcAddress("glAttachShader");
	glDetachShader = (PFNGLDETACHSHADERPROC)glGetProcAddress("glDetachShader");
	glLinkProgram = (PFNGLLINKPROGRAMPROC)glGetProcAddress("glLinkProgram");
	glProgramParameteri = (PFNGLPROGRAMPARAMETERIPROC)glGetProcAddress("glProgramParameteri");
	glGetProgramiv = (PFNGLGETPROGRAMIVPROC)glGetProcAddress("glGetProgramiv");
	glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC)glGetProcAddress("glGetProgramInfoLog");
	glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)glGetProcAddress("glGetShaderInfoLog");
	glGetProgramBinary = (PFNGLGETPROGRAMBINARYPROC)glGetProcAddress("glGetProgramBinary");
	glProgramBinary = (PFNGLPROGRAMBINARYPROC)glGetProcAddress("glProgramBinary");
	glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)glGetProcAddress("glGetUniformLocation");
	glUniform1i = (PFNGLUNIFORM1IPROC)glGetProcAddress("glUniform1i");
	glUniform2i = (PFNGLUNIFORM2IPROC)glGetProcAddress("glUniform2i");
	glUniform3i = (PFNGLUNIFORM3IPROC)glGetProcAddress("glUniform3i");
	glUniform4i = (PFNGLUNIFORM4IPROC)glGetProcAddress("glUniform4i");
	glUniform1iv = (PFNGLUNIFORM1IVPROC)glGetProcAddress("glUniform1iv");
	glUniform2iv = (PFNGLUNIFORM2IVPROC)glGetProcAddress("glUniform2iv");
	glUniform3iv = (PFNGLUNIFORM3IVPROC)glGetProcAddress("glUniform3iv");
	glUniform4iv = (PFNGLUNIFORM4IVPROC)glGetProcAddress("glUniform4iv");
	glUniform1f = (PFNGLUNIFORM1FPROC)glGetProcAddress("glUniform1f");
	glUniform2f = (PFNGLUNIFORM2FPROC)glGetProcAddress("glUniform2f");
	glUniform3f = (PFNGLUNIFORM3FPROC)glGetProcAddress("glUniform3f");
	glUniform4f = (PFNGLUNIFORM4FPROC)glGetProcAddress("glUniform4f");
	glUniform1fv = (PFNGLUNIFORM1FVPROC)glGetProcAddress("glUniform1fv");
	glUniform2fv = (PFNGLUNIFORM2FVPROC)glGetProcAddress("glUniform2fv");
	glUniform3fv = (PFNGLUNIFORM3FVPROC)glGetProcAddress("glUniform3fv");
	glUniform4fv = (PFNGLUNIFORM4FVPROC)glGetProcAddress("glUniform4fv");
	glUniformMatrix3fv = (PFNGLUNIFORMMATRIX3FVPROC)glGetProcAddress("glUniformMatrix3fv");
	glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC)glGetProcAddress("glUniformMatrix4fv");
	glGetAttribLocation = (PFNGLGETATTRIBLOCATIONPROC)glGetProcAddress("glGetAttribLocation");
	glVertexAttrib1f = (PFNGLVERTEXATTRIB1FPROC)glGetProcAddress("glVertexAttrib1f");
	glVertexAttrib1fv = (PFNGLVERTEXATTRIB1FVPROC)glGetProcAddress("glVertexAttrib1fv");
	glVertexAttrib2fv = (PFNGLVERTEXATTRIB2FVPROC)glGetProcAddress("glVertexAttrib2fv");
	glVertexAttrib3fv = (PFNGLVERTEXATTRIB3FVPROC)glGetProcAddress("glVertexAttrib3fv");
	glVertexAttrib4fv = (PFNGLVERTEXATTRIB4FVPROC)glGetProcAddress("glVertexAttrib4fv");
	glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)glGetProcAddress("glVertexAttribPointer");
	glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)glGetProcAddress("glEnableVertexAttribArray");
	glBindAttribLocation = (PFNGLBINDATTRIBLOCATIONPROC)glGetProcAddress("glBindAttribLocation");
	glActiveTexture = (PFNGLACTIVETEXTUREPROC)glGetProcAddress("glActiveTexture");
	glGenerateMipmap = (PFNGLGENERATEMIPMAPPROC)glGetProcAddress("glGenerateMipmap");
	glTexImage2DMultisample = (PFNGLTEXIMAGE2DMULTISAMPLEPROC)glGetProcAddress("glTexImage2DMultisample");

	glCreateShader = (PFNGLCREATESHADERPROC)glGetProcAddress("glCreateShader");
	glDeleteShader = (PFNGLDELETESHADERPROC)glGetProcAddress("glDeleteShader");
	glShaderSource = (PFNGLSHADERSOURCEPROC)glGetProcAddress("glShaderSource");
	glCompileShader = (PFNGLCOMPILESHADERPROC)glGetProcAddress("glCompileShader");
	glGetShaderiv = (PFNGLGETSHADERIVPROC)glGetProcAddress("glGetShaderiv");

	glBindBufferBase = (PFNGLBINDBUFFERBASEPROC)glGetProcAddress("glBindBufferBase");

#ifdef _WIN32
	wglChoosePixelFormatARB = (PFNWGLCHOOSEPIXELFORMATARBPROC)glGetProcAddress("wglChoosePixelFormatARB");
	wglCreateContextAttribsARB = (PFNGLCREATECONTEXTATTRIBSARBPROC)glGetProcAddress("wglCreateContextAttribsARB");
#else
	glXCreateContextAttribsARB = (PFNGLCREATECONTEXTATTRIBSARBPROC)glGetProcAddress("glXCreateContextAttribsARB");
#endif

#ifdef _WIN32
	// Release temporary rendering context
	if (renderctx)
	{
		wglMakeCurrent(hdc, NULL);
		wglDeleteContext(renderctx);
		renderctx = NULL;
		ReleaseDC(wnd, hdc);
		DestroyWindow(wnd);
	}
#else
	// Release temporary rendering context
	if (renderctx)
	{
		glXMakeCurrent(display, None, NULL);
		glXDestroyContext(display, renderctx);
		renderctx = NULL;
	}
#endif

	queried = true;
	return true;
}