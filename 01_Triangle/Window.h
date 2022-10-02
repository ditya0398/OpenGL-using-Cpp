#pragma once
#include<Windows.h>
#include<iostream>

class Window
{
	private:
		WNDCLASSEX wndclass;
		WNDPROC wndProc;
		HINSTANCE hInstance;
		HWND gHwnd = NULL;
		bool bIsDone = false;
		MSG msg;

	public:
		void initWndClass(TCHAR szClassName[]);
		void RegisterClassExToOS();
		void initWindow(TCHAR szClassName[]);
		MSG startGameLoop();
		Window(HINSTANCE hInstance, TCHAR szAppName[]);
		~Window();
	
};
