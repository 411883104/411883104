//#include<iostream>
//#include<algorithm>
//#include<cmath>
//using namespace std;
//typedef long long ll;
//int main()
//{
//	ll x;
//	cin>>x;
//	ll a=0,b=0;
//	ll minn=1e12;
//	for(ll i=1;i<=sqrt(x)+1;i++)
//	{
//		if(x%i==0)
//		{
//			if((max(i,x/i))<minn)
//			{
//				minn=min(max(i,x/i),minn);
//				a=i;
//				b=x/i;
//			}
//		}
//	}
//	cout<<a<<" "<<b<<endl;
//	return 0;
//} 


#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
int main()
{
	ll x;
	cin>>x;
	ll a=0,b=0;
	ll minn=1e12;
	for(ll i=sqrt(x);i>=1;i--)
	{
		if(x%i==0)
		{
			a=i;
			b=x/i;
			if(__gcd(a,b)==1)
			{
				cout<<a<<" "<<b<<endl;
				break;
			}
		}
	}
	return 0;
} 
