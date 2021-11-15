#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	double sum=1;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		sum*=x;
	}
	double ans=n*pow(sum/pow(2,m),(double)1/n);
	cout<<ans<<endl;
	cout<<setprecision(0)<<fixed<<ans<<endl;
 } 
