#ifndef CPTF_UI_CEFPROCEEE_H
#define CPTF_UI_CEFPROCESS_H

#include "MainWindowClient.h"



class CefProcess
{
public:
	CefProcess(void);
	~CefProcess(void);

public:
	static	void	intiCef();
	static	int		run();
	static	void	createBrowser(HWND hWnd, CefClient* client);
private:
	
};

#endif
