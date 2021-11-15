#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;
const double pi=3.1415927;
typedef long long ll;
int main()
{
	int a,b,c;
	int d,e;
	cin>>a>>b>>c;
	if(a>b)
	{
		d=b;
		if(a>c)
		{
			e=c;
		}
		else
		{
			e=a;
		}
	}
	else
	{
		d=a;
		if(b>c)
		{
			e=c;
		}
		else
		{
			e=b;
		}
	}
	cout<<d+e<<endl;
	return 0; 
} 
