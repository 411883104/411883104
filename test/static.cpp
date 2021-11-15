#include<iostream>
using namespace std;
class test
{
	public:
		static int num;
};
int num=5;
int test::num=10;
int main()
{
	
	cout<<num<<endl;
	cout<<test::num<<endl;
 } 
