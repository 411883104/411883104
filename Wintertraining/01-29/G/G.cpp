#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int c=1e7;
int arr[c];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		sort(arr,arr+n,cmp);
		int res=arr[0];
		for(int i=1;i<n;i++)
		{
			res=abs(res-arr[i]);
		} 
		if(res==1||res==0)
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}
	}
 } 
