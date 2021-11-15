#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>
using namespace std;

const int c=6e6;
typedef long long ll;
int arr[c];
int find(int x); 

int main()
{
	int n,m;
	int num,a[c];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		arr[i]=i;
	for(int i=1;i<=m;i++)
	{
		cin>>num;
		for(int j=1;j<=num;j++)
		{
			cin>>a[j];
		}
		for(int j=1;j<num;j++)
		{
			for(int k=j+1;k<=num;k++)
			{
			int tx=find(a[j]);
			int ty=find(a[k]);
			if(tx!=ty)
				arr[tx]=ty;
			}
		}
	}
	for(int j=1;j<=num;j++)
	{
		int sum=0;
		for(int k=1;k<=num;k++)
		{				
			if(arr[j]=arr[k])
				sum++;
		}
			cout<<sum<<" ";
	}
	return 0; 
} 
int find(int x)
{
	if(arr[x]==x)
		return x;
	else
		return arr[x]=find(arr[x]);
}
