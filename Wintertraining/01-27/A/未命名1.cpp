#include<iostream>
#include<algorithm>
using namespace std;
int arr[3][3];
int a[12];
int w[5];
int s[10];
int main()
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cin>>arr[i][j];
		}
	}
	int n,sum;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sum=0;
	for(int i=0,j=0;j<3&&i<3;i++,j++)
	{
		for(int k=0;k<n;k++)
		{
			if(arr[i][j]==a[k])
			{
				sum++;
			}
		}
	}
	if(sum==3)
	{
		cout<<"Yes"<<endl;
		return 0;
	}
	sum=0;
	for(int i=0;i<3;i++)
	{
		for(int k=0;k<n;k++)
		{
			if(arr[0][i]==a[k])
			{
				sum++;
			}
		}
	}
	if(sum==3)
	{
		cout<<"Yes"<<endl;
		return 0;
	}
	sum=0;
	for(int i=0;i<3;i++)
	{
		for(int k=0;k<n;k++)
		{
			if(arr[1][i]==a[k])
			{
				sum++;
			}
		}
	}
	if(sum==3)
	{
		cout<<"Yes"<<endl;
		return 0;
	}
	sum=0;
	for(int i=0;i<3;i++)
	{
		for(int k=0;k<n;k++)
		{
			if(arr[2][i]==a[k])
			{
				sum++;
			}
		}
	}
	if(sum==3)
	{
		cout<<"Yes"<<endl;
		return 0;
	}sum=0;
	for(int i=0;i<3;i++)
	{
		for(int k=0;k<n;k++)
		{
			if(arr[i][0]==a[k])
			{
				sum++;
			}
		}
	}
	if(sum==3)
	{
		cout<<"Yes"<<endl;
		return 0;
	}
	sum=0;
	for(int i=0;i<3;i++)
	{
		for(int k=0;k<n;k++)
		{
			if(arr[i][1]==a[k])
			{
				sum++;
			}
		}
	}
	if(sum==3)
	{
		cout<<"Yes"<<endl;
		return 0;
	}
	sum=0;
	for(int i=0;i<3;i++)
	{
		for(int k=0;k<n;k++)
		{
			if(arr[i][2]==a[k])
			{
				sum++;
			}
		}
	}
	if(sum==3)
	{
		cout<<"Yes"<<endl;
		return 0;
	}
	sum=0;
	for(int i=2,j=0;i>=0&&j<3;i--,j++)
	{
		for(int k=0;k<n;k++)
		{
			if(arr[i][j]==a[k])
			{
				sum++;
			}
		}
	}
	if(sum==3)
	{
		cout<<"Yes"<<endl;
		return 0;
	}
	cout<<"No"<<endl;
	return 0;
}
