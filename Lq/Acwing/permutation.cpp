#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main()
{
	cout<<R"(agjd
	dkag
	da)";
	int a[5]= {1,5,2,6,9};
	memset(a,0,5*4);
//	do{
//		for(int i=0;i<5;i++){
//			cout<<a[i]<<" ";
//		}
//		cout<<endl;
//	}while(next_permutation(a,a+5));
	string s="abcd";
	s.erase(3);
	cout<<s<<endl;
}
