#include<windows.h>
#include<stdio.h>
//#define UNICODE
//C���͵��ַ��� 
//ÿ���ַ�ռ1���ֽ� 
void C_char(){
	char* pszText="hello char";
	printf("%s\n",pszText);
} 
//���ֽ����ַ���
//ÿ���ֽ�ռ2���ֽ� 
void W_char(){
	//���ַ���ǰ��L 
	wchar_t* pszText=L"hello char";
	//ʹ��wcslen()����������ַ����ĳ��� 
	int len=wcslen(pszText);
	wprintf(L"%s %d\n",pszText,len);
}
void T_char(){
	//__TEXT()�ں��ж��� 
	TCHAR* pszText=__TEXT("hello txt");
	#ifdef UNICODE
	wprintf(L"%s\n",pszText);
	#else
	printf("%s\n",pszText);
	#endif
} 
int main()
{
	W_char();
	C_char();
	T_char(); 
	return 0;
 } 
