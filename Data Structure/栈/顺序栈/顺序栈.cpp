#include<iostream>
#include<algorithm>
using namespace std;
const int c=100;//最大分配空间 
struct SqStack
{
	//根据要使用的数据类型选择指针的类型 
	int *base;//栈底指针 
	int *top;//栈顶指针 
	//以上为动态分配形式，也可使用静态分配的形式:
//	int data[c];
//	int top; 
}; 
//构造一个空栈
bool create(SqStack&s)
{
	s.base=new int[c];//分配内存 
	if(s.base==NULL)
	{
		return false;
	}
	s.top=s.base;//top初始为基地址，当前为空栈 
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
