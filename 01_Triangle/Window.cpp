#include"Window.h"
#include"Renderer.h"

Window::Window(HINSTANCE hInstance, TCHAR szClassName[])
{
	LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
	this->hInstance = hInstance;
	this->wndProc = WndProc;

	initWndClass(szClassName);
	RegisterClassExToOS();
	initWindow(szClassName);
	
}

void Window::initWndClass(TCHAR szClassName[])
{
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = wndProc;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszClassName = szClassName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
}

void Window::RegisterClassExToOS()
{

	if (RegisterClassEx(&this->wndclass) == 0)
	{
		//Failed to register wndclassex
	}
}

void Window::initWindow(TCHAR szClassName[])
{
	//CreateWindow
	gHwnd = CreateWindowEx(WS_EX_APPWINDOW,
		szClassName,
		TEXT("Triangle"),
		WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE,
		100,
		100,
		800, 600,
		NULL,
		NULL,
		hInstance,
		0);


}
MSG Window::startGameLoop()
{
	Renderer render;
	render.initOpenGL(gHwnd);

	while (bIsDone == false)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				bIsDone = true;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			render.render();
		}
	}

	return msg;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return(DefWindowProc(hWnd, iMsg, wParam, lParam));
}

Window::~Window()
{

}

