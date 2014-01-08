#include "StdAfx.h"
#include "WinWidgetProcess.h"

WinWidgetProcess::WinWidgetProcess(void)
{
}

WinWidgetProcess::~WinWidgetProcess(void)
{
}

void WinWidgetProcess::autoSize(HWND apphwnd, HWND browserHwnd)
{
	if (!apphwnd || !browserHwnd)return;

	RECT rect;
	GetClientRect(apphwnd, &rect);

	HDWP hdwp = BeginDeferWindowPos(1);
	hdwp = DeferWindowPos(hdwp, browserHwnd, NULL,
		rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top,
		SWP_NOZORDER);
	EndDeferWindowPos(hdwp);
}
