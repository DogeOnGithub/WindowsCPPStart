#include <Windows.h>

//���ڹ��̻ص�����
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//Main�������
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
	HWND hwnd;//���ھ��
	MSG msg;//��Ϣ
	WNDCLASS wc;//������

	//��ƴ���
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

	//ע�ᴰ��
	RegisterClass(&wc);

	//��������
	hwnd = CreateWindow(TEXT("MyWND"), TEXT("����"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	//��ʾ����
	ShowWindow(hwnd, nCmdShow);
	//���´���
	UpdateWindow(hwnd);

	//��Ϣѭ��
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

//�����յ���Ϣ�������Ĵ�����Ϊ
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