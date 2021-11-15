#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int c=210;
int arr[c];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n*2-1;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+(n*2-1));
	int vis=0;
	for(int i=0;i<n*2-1;i++)
	{
		vis+=arr[i];
	}
	for(int i=0;i<n;i++)
	{
		arr[i]=arr[i]*(-1);
	}
	int ans=0;
	for(int i=0;i<n*2-1;i++)
	{
		ans+=arr[i];
	}
	cout<<max(ans,vis)<<endl;
	return 0;
} 
