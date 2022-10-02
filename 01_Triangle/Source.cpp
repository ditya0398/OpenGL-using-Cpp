/*By - Aditya Boob
 Starting Date - 2nd October - 2022
 */

#include<iostream>
#include<Windows.h>
#include<gl/glew.h>
#include<GL/gl.h>
#include"window.h"



#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glew32.lib")

Window* Window::instance = 0;

/*The user-provided entry point for a graphical Windows-based application.*/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR szCmdLine, int iCmdShow)
{
	TCHAR szAppName[] = TEXT("OpenGL Window");

	//get the instance since this is a singleton class
	Window* windowInstance = windowInstance->getInstance();
	windowInstance->initWindowAndRenderer(hInstance, szAppName);
	
	MSG msg = windowInstance->startGameLoop();

	return((int)msg.wParam);
}	







