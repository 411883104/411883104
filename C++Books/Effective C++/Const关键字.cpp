#include<iostream>
using namespace std;
int main()
{
	//const������*��߱�ʾ��ָ���ǳ���
	int a=5;
	const int*p=&a;//�ȼ���int const*p=&a; 
	cout<<*p<<endl;
	a=2;//�����޸�a��ֵ 
	//*p=1;//���� 
	cout<<*p<<endl;
	
	//const������*�ұ߱�ʾָ�������ǳ���
	int b=10;
	int *const q=&b;
	cout<<*q<<endl; 
	//q=&a; //����
} 
