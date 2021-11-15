#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int c=1010;
int arr[c];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	int maxx=0;
	for(int i=n;i>=2;i--)
	{
		arr[i]=abs(arr[i]-arr[i-1]);
		maxx=max(maxx,arr[i]);
	}
	cout<<maxx<<endl;
	return 0;
}
