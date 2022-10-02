#pragma once
#include<Windows.h>
#include<iostream>
#include "Renderer.h"
class Window
{
	private:
		WNDCLASSEX wndclass;
		WNDPROC wndProc;
		HINSTANCE hInstance;
		Renderer renderer;
		bool temp;
		bool bIsDone = false;
		MSG msg;

	public:
		HWND gHwnd;
		void initWndClass(TCHAR szClassName[]);
		void RegisterClassExToOS();
		void initWindow(TCHAR szClassName[]);
		MSG startGameLoop();
		Window(HINSTANCE hInstance, TCHAR szAppName[]);
		~Window();
	
};
