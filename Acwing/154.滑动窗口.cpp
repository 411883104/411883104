//Time Limit Exceeded （时间复度O（nk）） 
/*
#include<iostream>
#include<algorithm>
using namespace std;
const int c=2e6;
int arr[c];
int big[c],small[c];
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	for(int i=1;i+k<=n+1;i++)
	{
		int maxx=-1e5,minn=1e5;
		for(int j=i;j<=i+k-1;j++)
		{
			if(arr[j]>maxx)
				maxx=arr[j];
			if(arr[j]<minn)
				minn=arr[j];
		}
		big[i]=maxx;
		small[i]=minn;
	}
	for(int i=1;i<=n-k+1;i++)
	{
		cout<<small[i]<<" ";
	}
	cout<<endl;
	for(int i=1;i<=n-k+1;i++)
	{
		cout<<big[i]<<" ";
	}
	cout<<endl;
	return 0;
} 
*/


//单调队列优化 
#include<iostream>
using namespace std;
const int c=2e6;
int arr[c];//存放数字 
int queue[c];// 

int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	//找最大值 
	for(int i=1;i<=n;i++)
	{
		int head=1,tail=0;
		while(head<tail&&a[i]<a[queue[tail]])
		{
			
		}
	}
	
}
