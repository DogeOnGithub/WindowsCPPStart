#pragma once
#include <afxwin.h>

class MyApp : public CWinApp
{
public:
	//��дCWinAPP�еĺ���
	virtual BOOL InitInstance()
	{
		//������ܴ��ڶ���
		CFrameWnd *f = new CFrameWnd();

		//����CFrameWnd��CWinApp
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
