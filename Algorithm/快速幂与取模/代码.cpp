//计算n^n 结果最后一位数字 
#include<iostream>
#include<iomanip>
using namespace std;
const double pi=3.1415927;
typedef long long ll;
int main()
{
	int t;
	cin>>t;  //t组测试数据 
	while(t--)
	{
		ll n,base,result=1;
		cin>>n;
		base=n;
		//(a * b) % p = (a % p * b % p) % p 
		while(n)
		{
			if(n&1)  // 位运算，奇数为1偶数为0 
				result=(result*base)%10;
			base=(base*base)%10;
			n>>=1;  //移位运算（注意>>=） 
			}
		cout<<result<<endl;	
	} 
	return 0; 
} 
