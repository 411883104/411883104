#include<iostream>
#include<algorithm>
using namespace std;
const int c=1e5+10;
int arr[c];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+n);
	int min=0,max=0;
	for(int i=0;i<n/2;i++)
	{
		min+=arr[i];
	}
	for(int i=n/2;i<n;i++)
	{
		max+=arr[i];
	}
	printf("%d %d",n%2,max-min);
	return 0;
} 
