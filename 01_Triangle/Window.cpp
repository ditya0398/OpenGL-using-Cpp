#include"Window.h"
#include"Renderer.h"


//Private consturctor since singleton and no objects should be created
Window::Window()
{

}

HWND Window::getHwnd()
{
	if(hWnd != NULL)
		return hWnd;
}


Window* Window::getInstance()
{
	if (!instance)
	{
		instance = new Window;
		return instance;
	}
}
void Window::initWindowAndRenderer(HINSTANCE hInstance, TCHAR szClassName[])
{
	LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
	this->hInstance = hInstance;
	this->wndProc = WndProc;

	//initialize the WndClass
	initWndClass(szClassName);
	
	//Register the WndClass to OS
	RegisterClassExToOS();

	//Initialize the Window
	createWindow(szClassName);

	//Initialize OpenGL 
	renderer.initRenderer(getHwnd());
	
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

void Window::createWindow(TCHAR szClassName[])
{
	//CreateWindow
	hWnd = CreateWindowEx(WS_EX_APPWINDOW,
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
	//Renderer render;
	
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
			renderer.render();
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

