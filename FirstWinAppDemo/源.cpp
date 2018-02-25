#include "MyApp.h"

//MyApp myApp;

MyApp2 myApp2;

BOOL MyApp2::InitInstance()
{
	this->m_pMainWnd = new MyFrameWnd();
	this->m_pMainWnd->ShowWindow(SW_SHOW);
	this->m_pMainWnd->UpdateWindow();
	return true;
}

MyFrameWnd::MyFrameWnd()
{
	Create(NULL, TEXT("MyApp2"));
}