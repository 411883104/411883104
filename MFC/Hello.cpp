#include<afxwin.h>//����afxwin.hͷ�ļ�������MFC���

//��CWinApp����������һ���Լ��������
class CMyApp :public CWinApp
{
public:
	//����CWinApp::InitInstance��������Ϊ��Ӧ�ó������������InitInstance�������ý��磬�ڳ���ʼ�����Ժ�����ڴ���֮ǰ��
	//��������InitInstance����������Ӧ�ó��򲻻��д���
	
	virtual BOOL InitInstance();

};

class CMainWindow :public CFrameWnd
{
public:
	CMainWindow();
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP();
};
CMyApp myApp;


BOOL CMyApp::InitInstance()
{
	//����һ��CMainWindow���󣬲���ֵ��Ӧ�ó������m_pMainWnd���ݳ�Ա��
	//ԭ�� CWnd* m_pMainWnd;    // main window (usually same AfxGetApp()->m_pMainWnd)
	m_pMainWnd = new CMainWindow;

	//���������ShowWindow��UpdateWindow����
	m_pMainWnd->ShowWindow(m_nCmdShow);//m_nCmdShowΪһ����������ʾ���ڵ�״̬
	m_pMainWnd->UpdateWindow();
	//���Ҫ��MFC�����е���Window��API,Ҫ�ں���ǰ����ȫ�������::
	//��::UpdateWindow(hWnd);
	return TRUE;
}

//��Ϣӳ��
BEGIN_MESSAGE_MAP(CMainWindow, CFrameWnd)//��ʾ��Ϣӳ����������͸���Ļ���
	ON_WM_PAINT()
END_MESSAGE_MAP()

CMainWindow::CMainWindow()
{
	/*
	virtual BOOL Create(LPCTSTR lpszClassName,   //ָ�����ڻ���WNDCLASS�������
				         //��ΪNULL������һ�����������ṹע���WNDCLASS���Ĭ�Ͽ�ܴ���

				LPCTSTR lpszWindowName,          //���������ֵ�����
				DWORD dwStyle = WS_OVERLAPPEDWINDOW, //ָ��������ʽ
				const RECT& rect = rectDefault,   //C��Rect�ṹ�����ã�ָ����������Ļ�ĳ�ʼλ�úͳߴ�
				CWnd* pParentWnd = NULL,        // != NULL for popups //ָ�����ര��
				LPCTSTR lpszMenuName = NULL,    //���ڲ˵�
				DWORD dwExStyle = 0,            
				CCreateContext* pContext = NULL
				);
	*/
	Create(NULL, _T("Hello!"));
	/*
	"Hello"����������ANSI�ַ���ɸ��ַ���
	L"Hello"��������ʹ��Unicode�ַ�
	_T("Hello")���Ԥ����������_UNICODE����������ʹ��Unicode�ַ������û��Ԥ���������ţ���ʹ��ANSI
	*/
}

void CMainWindow::OnPaint()
{
	/*
	* ר����;���豸�������ࣺ����ֱ��ʵ������
	CPaintDC  //�����ڴ��ڿͻ�����ͼ��������OnPaint�������
	CClientDC //�����ڴ��ڿͻ�����ͼ����OnPaint����κδ������
	CWindowDC //�����ڴ���������ط���ͼ�������ǿͻ���
	CMetaFileDC  //������GDIԪ�ļ��л�ͼ
	*/
	//BeginPaint��EndPaint�ֱ���CPaintDC�ȶ���Ĺ��캯��������������

	//ջ�й���ʱ���Զ����գ��ڶ���new����ʱҪ����delete�ͷ�
	CPaintDC dc(this);//ֻ����OnPaint���������ʹ��

	//��������CRect����
	CRect rect;
	//CWnd::GetClientRect()
	GetClientRect(&rect);
	/*
	int DrawText(
		LPCTSTR lpchText,  //�ַ���ָ��
		int cchText,       //�ַ����ַ�����-1ʱҪ�ַ�����NULL��β
		LPRECT lprc,       //ָ����ʽ�����һ��RECT������ַ
		UINT format        //��ʾ��ʽ
    )*/
	dc.DrawText(_T("Hello World!"), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	/*
	ʹ��_T�������ַ�������ʱҪע�⣺
	1�����ַ�����ΪTCHAR���Ͷ�����char���ͣ����������_UNICODE���ţ�TCHAR����ֵΪwchar_t������һ��
		16Ϊ��Unicode�ַ������û�ж���_UNICODE��TCHAR����Ϊ��ͨ��char��
	2����Ҫʹ��char*����wchar_t*������TCHAR�ַ�����ָ�룬��Ӧ��ʹ��TCHAR*���߸��ѵ�LPTSTR(ָ��TCHAR�ַ�����ָ��)
		��LPCTSTR(ָ��const TCHAR�ַ�����ָ��)��������
	3��һ���ַ���һ��ֻ��8λ�����Ҫ�����ֽڱ�ʾ�Ļ���������ת��Ϊ���ַ���ʾ�Ļ�������С�����Խ���sizeof(TCHAR)���ֻ��������ȡ�
	*/
}

