#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
const int c=110;
int arr[c][c];
int sum[c][c];

int main()
{
	int maxx=INT_MIN;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>arr[i][j];
			arr[i][j]+=arr[i][j-1]; 
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int sum=0;
			for(int k=1;k<=n;k++)
			{
				if(sum<0)
				{
					sum=(arr[k][j]-arr[k][i-1]);
				}
				else
				{
					sum+=(arr[k][j]-arr[k][i-1]);
				}
				maxx=max(sum,maxx);
			}
		}
	}
	cout<<maxx<<endl;
 } 
