#include<iostream>
#include<algorithm>
using namespace std;
const int c=100;//������ռ� 
struct SqStack
{
	//����Ҫʹ�õ���������ѡ��ָ������� 
	int *base;//ջ��ָ�� 
	int *top;//ջ��ָ�� 
	//����Ϊ��̬������ʽ��Ҳ��ʹ�þ�̬�������ʽ:
//	int data[c];
//	int top; 
}; 
//����һ����ջ
bool create(SqStack&s)
{
	s.base=new int[c];//�����ڴ� 
	if(s.base==NULL)
	{
		return false;
	}
	s.top=s.base;//top��ʼΪ����ַ����ǰΪ��ջ 
	return true;
}
bool push(SqStack&s,int values) 
{
	*(s.top)=values;
	s.top++;
	cout<<s.top<<endl;
	return true;
}
int main()
{
	SqStack My_Stack;
	create(My_Stack);
	for(int i=1;i<=50;i++)
	{
		push(My_Stack,i);
	}
	
	cout<<My_Stack.top-My_Stack.base<<endl;
} 
