#include "Renderer.h"
#include"Window.h"

int Renderer::initRenderer(HWND hWnd)
{
	GLenum result;
	
	PIXELFORMATDESCRIPTOR pfd;
	int iPixelFormatDescriptor;
	int iPixelFormatIndex;


	memset((void*)&pfd, NULL, sizeof(PIXELFORMATDESCRIPTOR));
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;
	pfd.cRedBits = 8;
	pfd.cGreenBits = 8;
	pfd.cBlueBits = 8;
	pfd.cAlphaBits = 8;
	pfd.cDepthBits = 32;
	gHdc = GetDC(hWnd);
	
	iPixelFormatIndex = ChoosePixelFormat(gHdc, &pfd);
	if (iPixelFormatIndex == 0)
	{
		return(-1);
	}

	if (SetPixelFormat(gHdc, iPixelFormatIndex, &pfd) == FALSE)
	{
		return(-2);
	}

	ghglrc = wglCreateContext(gHdc);

	if (ghglrc == NULL)
	{
		return(-3);
	}

	if (wglMakeCurrent(gHdc, ghglrc) == FALSE)
	{
		return(-4);
	}
	result = glewInit();
	if (result != GLEW_OK)
	{
		/*fprintf(gpLogFile, "ERROR : glewInit FAILED!!!\n");
		uninitialize();*/
		//DestroyWindow(Window::gHwnd);
	}
	glClearDepth(1.0f);
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	
	resize(800, 600);
	return 0;
}

void Renderer::resize(int width,int height)
{
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
}

void Renderer::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		
	SwapBuffers(gHdc);		
}