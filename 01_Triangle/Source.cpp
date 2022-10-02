/*By - Aditya Boob
 Starting Date - 2nd October - 2022
 */

#include<iostream>
#include<Windows.h>
#include"window.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

HDC gHdc = NULL;

/*The user-provided entry point for a graphical Windows-based application.*/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR szCmdLine, int iCmdShow)
{
	TCHAR szAppName[] = TEXT("OpenGL Window");

	Window window(hInstance, szAppName);
	MSG msg = window.startGameLoop();

	return((int)msg.wParam);
}	







