#include<iostream>
using namespace std;
template<typename T>
T fun(int a,T b)
{
	return b;
}
template<class T>
class stu
{
	public:
		T a;
		stu(T a):a(a)
		{
			
		}
};
int main()
{
	int a=2;
	cout<<fun(a,a)<<endl;
	char b='a';
	cout<<fun(b,b)<<endl;
	stu<char>s('g');
	cout<<s.a<<endl;
}
