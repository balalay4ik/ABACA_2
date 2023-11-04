#include <windows.h>
#include <gl/gl.h>
#include "stb_easy_font.h"
#include <string>
#include <time.h>
#include "GameController.h"
#include <mmsystem.h>

using namespace std;

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "winmm.lib")

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
void EnableOpenGL(HWND hwnd, HDC*, HGLRC*);
void DisableOpenGL(HWND, HDC, HGLRC);

#define width 6
#define height 16

GameController game;

const int TARGET_FPS = 90;
const double TARGET_FRAME_TIME = 1.0 / TARGET_FPS;

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	WNDCLASSEX wcex;
	HWND hwnd;
	HDC hDC;
	HGLRC hRC;
	MSG msg;
	BOOL bQuit = FALSE;
	float theta = 0.0f;

	/* register window class */
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_OWNDC;
	wcex.lpfnWndProc = WindowProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = "ABACA";
	wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);;



	if (!RegisterClassEx(&wcex))
		return 0;

	/* create main window */
	hwnd = CreateWindowEx(0,
		"ABACA",
		"ABACA",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		//659,
		//434,
		1500,
		900,
		NULL,
		NULL,
		hInstance,
		NULL);

	ShowWindow(hwnd, nCmdShow);



	/* enable OpenGL for the window */
	EnableOpenGL(hwnd, &hDC, &hRC);

	double prevTime = timeGetTime() * 0.001; // �������� ��������� ����� � ��������
	double elapsedTime = 0.0;

	game.Init();

	/* program main loop */
	while (!bQuit)
	{
		/* check for messages */
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			/* handle or dispatch messages */
			if (msg.message == WM_QUIT)
			{
				bQuit = TRUE;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			/* OpenGL animation code goes here */

			glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			glPushMatrix();

			game.Update();

			glPopMatrix();

			SwapBuffers(hDC);

			if (elapsedTime < TARGET_FRAME_TIME) {
				// ��������� �����, �� ������� ����� �������, ����� ������� TARGET_FRAME_TIME
				int sleepTime = int((TARGET_FRAME_TIME - elapsedTime) * 1000);
				if (sleepTime > 0) {
					Sleep(sleepTime);
				}
			}
			elapsedTime = 0.0;
		}
	}

	/* shutdown OpenGL */
	DisableOpenGL(hwnd, hDC, hRC);

	/* destroy the window explicitly */
	DestroyWindow(hwnd);

	return msg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CLOSE:
		PostQuitMessage(0);
		break;

	case WM_DESTROY:
		return 0;

	case WM_SIZE:
	{
		glViewport(0, 0, LOWORD(lParam), HIWORD(lParam));
		glLoadIdentity();
		float k = LOWORD(lParam) / (float)HIWORD(lParam);
		//glOrtho(-k, k, -1, 1, -1, 1);
		glScalef(1, 1, 1);
		break;
	}

	case WM_KEYDOWN:
	{
		switch (wParam)
		{
		case VK_ESCAPE:
			//PostQuitMessage(0);
			if (game.CheckNewGame() == false)
				game.LoadStep();
			break;

		case VK_UP:
			if (game.CheckNewGame() == false)
				if (!game.CheckRandom())
					game.ToggleSaveDice(true);
			break;

		case VK_DOWN:
			if (game.CheckNewGame() == false)
				if (!game.CheckRandom())
					game.ToggleSaveDice(false);
			break;

		case VK_LEFT:
			if (game.CheckNewGame() == false)
				if (!game.CheckRandom())
					game.NextDice(-1);
			break;

		case VK_RIGHT:
			if (game.CheckNewGame() == false)
				if (!game.CheckRandom())
					game.NextDice(1);
			break;

		case VK_RETURN:
		case VK_SPACE:
		{
			if (game.CheckNewGame() == false)
			{
				if (game.CheckStep())
					if (game.CheckRandom())
					{
						game.ToggleRandom();
						game.Step();
					}
					else
					{
						game.ToggleRandom();
					}
			}
			break;
		}
		}

		if (game.CheckNewGame() == true) game.GetNewGameController()->Button(wParam);
		else
			if (!game.CheckRandom())
				if (game.Buttons()) game.ToggleTeam();

	}
	break;


	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}

	return 0;
}

void EnableOpenGL(HWND hwnd, HDC* hDC, HGLRC* hRC)
{
	PIXELFORMATDESCRIPTOR pfd;

	int iFormat;

	/* get the device context (DC) */
	*hDC = GetDC(hwnd);

	/* set the pixel format for the DC */
	ZeroMemory(&pfd, sizeof(pfd));

	pfd.nSize = sizeof(pfd);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW |
		PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 24;
	pfd.cDepthBits = 16;
	pfd.iLayerType = PFD_MAIN_PLANE;

	iFormat = ChoosePixelFormat(*hDC, &pfd);

	SetPixelFormat(*hDC, iFormat, &pfd);

	/* create and enable the render context (RC) */
	*hRC = wglCreateContext(*hDC);

	wglMakeCurrent(*hDC, *hRC);
}

void DisableOpenGL(HWND hwnd, HDC hDC, HGLRC hRC)
{
	wglMakeCurrent(NULL, NULL);
	wglDeleteContext(hRC);
	ReleaseDC(hwnd, hDC);
}

