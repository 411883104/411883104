#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	long long a,b;
	cin>>a>>b;
	if(a==0||b==0) 
	{
		if(a==0&&b==0)
		{
			cout<<0<<endl;
		}
		else
		{
			if(a==0)
			{
				cout<<b<<endl;
			}
			if(b==0)
			{
				cout<<a<<endl;
			}
		}
	}
	else
	{
		long long min=__gcd(a,b);
		cout<<a*b/min<<endl;
	}
	return 0;
} 
