#include <Windows.h>

//窗口过程回调函数
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//Main函数入口
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
	HWND hwnd;//窗口句柄
	MSG msg;//消息
	WNDCLASS wc;//窗口类

	//设计窗口
	wc.style = 0;
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = "MyWND";

	//注册窗口
	RegisterClass(&wc);

	//创建窗口
	hwnd = CreateWindow(TEXT("MyWND"), TEXT("标题"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	//显示窗口
	ShowWindow(hwnd, nCmdShow);
	//更新窗口
	UpdateWindow(hwnd);

	//消息循环
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

//窗口收到消息后，做出的处理行为
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	RECT rect;

	switch (message)
	{
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rect);
		Ellipse(hdc, 0, 0, 200, 200);
		DrawText(hdc, TEXT("TjSanshao"), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		EndPaint(hwnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_LBUTTONDOWN:
		MessageBox(hwnd, TEXT("Clicked!"), TEXT("Tip"), MB_OK);
		return 0;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
}