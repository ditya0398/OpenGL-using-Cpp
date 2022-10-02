#pragma once
#include<Windows.h>
#include<gl/glew.h>
#include<GL/gl.h>


class Renderer
{
	public:
		HDC gHdc = NULL;
		HGLRC ghglrc = NULL;

		int initRenderer(HWND hWnd);
		void resize(int width, int height);
		void render();

};
