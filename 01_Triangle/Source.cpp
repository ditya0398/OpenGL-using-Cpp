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


/*The user-provided entry point for a graphical Windows-based application.*/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR szCmdLine, int iCmdShow)
{
	TCHAR szAppName[] = TEXT("OpenGL Window");

	Window window(hInstance, szAppName);
	MSG msg = window.startGameLoop();

	return((int)msg.wParam);
}	







