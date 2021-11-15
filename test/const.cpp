#include<iostream>
using namespace std;
class s
{
	public:
		static const int a=8;
//		s(int x):a(x)
//		{
//			
//		} 
		
};
const int s::a;
int main()
{
	s q;
	cout<<q.a<<endl;
	cout<<&(q.a)<<endl; 
	const int *arr=new int[10]; 
 } 
