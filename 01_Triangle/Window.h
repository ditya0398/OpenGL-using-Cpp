#pragma once
#include<Windows.h>
#include<iostream>
#include "Renderer.h"
class Window
{
	static Window* instance;


	private:
		HWND hWnd;
		WNDCLASSEX wndclass;
		WNDPROC wndProc;
		HINSTANCE hInstance;
		Renderer renderer;
		bool temp;
		bool bIsDone = false;
		MSG msg;

		//private Constructor
		Window();

	public:
		static Window* getInstance();
		HWND getHwnd();
		void initWindowAndRenderer(HINSTANCE hInstance, TCHAR szAppName[]);
		void initWndClass(TCHAR szClassName[]);
		void RegisterClassExToOS();
		void createWindow(TCHAR szClassName[]);
		MSG startGameLoop();
		~Window();
};
