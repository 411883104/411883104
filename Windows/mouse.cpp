#include<windows.h>
#include<bits/stdc++.h>
long long WINAPI WndProc(HWND hwnd,UINT msg,WPARAM wp,LPARAM lp)
{
	return DefWindowProc(hwnd,msg,wp,lp);
}
int main()
{
	HINSTANCE hInst; 
	WNDCLASS wc;
	memset(&wc,0,sizeof(wc));
	wc.lpszClassName="Name";
	wc.hInstance=hInst;
	wc.lpfnWndProc=WndProc;
	RegisterClassA(&wc);
	HWND hwnd = CreateWindowA("WindowClassName", 
						"XSZY",
						WS_OVERLAPPEDWINDOW,
						100, 100,
						640, 480,
						NULL, NULL, hInst, NULL);
	ShowWindow(hwnd,SW_SHOW);
	return 0;
} 
