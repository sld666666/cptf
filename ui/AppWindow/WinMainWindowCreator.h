#ifndef CPTF_UI_WINMAINWINDOWCREATOR_H
#define CPTF_UI_WINMAINWINDOWCREATOR_H
#include "CefProcess.h"
#include "WinWidgetProcess.h"
CefRefPtr<MainWindowClient> g_client;
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);

class WinMainWindowCreator
{
public:
	WinMainWindowCreator(const wstring& className);
	~WinMainWindowCreator();
public:
	bool	initInstance(const wstring& title);
	void	createBrowser();
private:
	ATOM	registerClass();
private:
	wstring className_;
};


WinMainWindowCreator::WinMainWindowCreator( const wstring& className )
{
	className_ = className;
	registerClass();
}

WinMainWindowCreator::~WinMainWindowCreator()
{

}

ATOM WinMainWindowCreator::registerClass()
{
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= NULL;
	wcex.hIcon			= NULL;
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= NULL;
	wcex.lpszClassName	= className_.c_str();
	wcex.hIconSm		= NULL;

	return RegisterClassEx(&wcex);
}

bool WinMainWindowCreator::initInstance(const wstring& title)
{
	HWND hWnd;
	hWnd = CreateWindow(className_.c_str(), title.c_str(), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, NULL, NULL);

	if (!hWnd)return false;
	ShowWindow(hWnd, 1);
	UpdateWindow(hWnd);

	return TRUE;
}



LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: 在此添加任意绘图代码...
		EndPaint(hWnd, &ps);
		break;
	case WM_CREATE:
		g_client = new MainWindowClient();
		CefProcess::createBrowser(hWnd, g_client.get());
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	 case WM_SIZE:
		 if ( g_client.get() && g_client->getBrowser()) 
		 {
			 CefWindowHandle browserWnd =  g_client->getBrowser()->GetHost()->GetWindowHandle();
			 if (hWnd)WinWidgetProcess::autoSize(hWnd, browserWnd);
		 }
		 break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

#endif