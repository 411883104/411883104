//����n^n ������һλ���� 
#include<iostream>
#include<iomanip>
using namespace std;
const double pi=3.1415927;
typedef long long ll;
int main()
{
	int t;
	cin>>t;  //t��������� 
	while(t--)
	{
		ll n,base,result=1;
		cin>>n;
		base=n;
		//(a * b) % p = (a % p * b % p) % p 
		while(n)
		{
			if(n&1)  // λ���㣬����Ϊ1ż��Ϊ0 
				result=(result*base)%10;
			base=(base*base)%10;
			n>>=1;  //��λ���㣨ע��>>=�� 
			}
		cout<<result<<endl;	
	} 
	return 0; 
} 
