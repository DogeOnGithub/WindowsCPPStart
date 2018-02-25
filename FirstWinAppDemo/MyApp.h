#pragma once
#include <afxwin.h>

class MyApp : public CWinApp
{
public:
	//重写CWinAPP中的函数
	virtual BOOL InitInstance()
	{
		//创建框架窗口对象
		CFrameWnd *f = new CFrameWnd();

		//链接CFrameWnd和CWinApp
		this->m_pMainWnd = f;

		f->Create(NULL, TEXT("FirstMfc"));
		f->ShowWindow(SW_SHOW);
		return true;
	}
};

class MyApp2 : public CWinApp
{
public:
	virtual BOOL InitInstance();
};

class MyFrameWnd : public CFrameWnd
{
public:
	MyFrameWnd();
};
