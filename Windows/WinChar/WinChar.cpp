#include<windows.h>
#include<stdio.h>

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
int main()
{
	W_char();
	C_char();
	return 0;
 } 
