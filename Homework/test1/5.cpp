#include<iostream>
#include<algorithm>
using namespace std;
class Complex
{
	private:
		double mX;
		double mY;
	public:
		Complex(double,double);
		friend Complex Add(Complex A,Complex B);
		friend Complex Sub(Complex A,Complex B);
		friend Complex Mul(Complex A,Complex B);
		friend Complex Div(Complex A,Complex B);
		static void show()
		{
			cout<<mX<<"+"<<mY<<"i"<<endl;
		}
};
Complex::Complex(double x=0.0,double y=0.0)
{
	mX=x;
	mY=y;
}
Complex Add(Complex A,Complex B){
	Complex C;
	C.mX=A.mX+B.mX;
	C.mY=A.mY+B.mY;
	return C;
}
Complex Sub(Complex A,Complex B){
	Complex C;
	C.mX=A.mX-B.mX;
	C.mY=A.mY-B.mY;
	return C;
}
Complex Mul(Complex A,Complex B){
	Complex C;
	C.mX=A.mX*A.mY-B.mX*B.mY;
	C.mY=A.mY*B.mY+B.mX*A.mX;
	return C;
}
Complex Div(Complex A,Complex B){
	Complex C;
	C.mX=(A.mX*A.mY+B.mX*B.mY)/(B.mX*B.mX+B.mY*B.mY);
	C.mY=(A.mY*B.mY-B.mX*A.mX)/(B.mX*B.mX+B.mY*B.mY);
	return C;
}
int main()
{
	Complex one(2.3,1),two(2,1);
	char ju;
	cin>>ju; 
	Complex Sum=Add(one,two);
	Sum.show();
	Sum=Sub(one,two);
	Sum.show();
	Sum=Mul(one,two);
	Sum.show();
	Sum=Div(one,two);
	Sum.show();
}
