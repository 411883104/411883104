#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		double h,c,t;
		cin>>h>>c>>t;
		double s=h/2+c*2;
		for(int i=2;i<=1000;i++)
		{
			double sum1=h/pow(2,i)-c/pow(2,i);
			double sum2=h/pow(2,i+1)-c/pow(2,i+1);
			if(sum1<sum2)
			{
				cout<<i<<endl;
				break;
			}
		}
	}
	return 0;
 } 
