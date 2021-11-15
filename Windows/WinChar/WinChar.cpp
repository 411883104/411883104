#include<windows.h>
#include<stdio.h>

//C类型的字符串 
//每个字符占1个字节 
void C_char(){
	char* pszText="hello char";
	printf("%s\n",pszText);
} 
//宽字节型字符串
//每个字节占2个字节 
void W_char(){
	//在字符串前加L 
	wchar_t* pszText=L"hello char";
	//使用wcslen()函数计算宽字符串的长度 
	int len=wcslen(pszText);
	wprintf(L"%s %d\n",pszText,len);
}
int main()
{
	W_char();
	C_char();
	return 0;
 } 
