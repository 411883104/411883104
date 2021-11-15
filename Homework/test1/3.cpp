#include<iostream>
using namespace std;
class imaginary
{
	private:
		double x;
		double y;
	public:
		imaginary();
		imaginary(double=0.0,double=0.0);
		friend void add(imaginary& A,imaginary B);
		friend void sub(imaginary& A,imaginary B);
		friend void mul(imaginary& A,imaginary B);
		friend void div(imaginary& A,imaginary B);
		static void show(imaginary A);
};
imaginary::imaginary(double a,double b)
{
	x=a;
	y=b;
}
void add(imaginary& A,imaginary B)
{
	A.x=A.x+B.x;
	A.y=A.y+B.y;
}
void sub(imaginary& A,imaginary B)
{
	A.x=A.x-B.x;
	A.y=A.y-B.y;
}
void mul(imaginary& A,imaginary B){
	A.x=A.x*A.y-B.x*B.y;
	A.y=A.y*B.y+B.x*A.x;
}
void div(imaginary& A,imaginary B)
{
	A.x=(A.x*A.y+B.x*B.y)/(B.x*B.x+B.y*B.y);
	A.y=(A.y*B.y-B.x*A.x)/(B.x*B.x+B.y*B.y);
}
void imaginary::show(imaginary A)
{
	cout<<A.x<<"+"<<A.y<<"i"<<endl;
}
int main()
{
	imaginary A(2,4);
	imaginary B(1,3);
	char algori;
	cout<<"input:"; 
	cin>>algori;
	if(algori=='+')
	{
		add(A,B);
	}
	if(algori=='+')
	{
		sub(A,B);
	}
	if(algori=='*')
	{
		mul(A,B);
	}
	if(algori=='/')
	{
		div(A,B);
	}
	cout<<"output:";
	imaginary::show(A);
	return 0;
} 
