#include<iostream>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;
const int c=1010;
int arr[c][c];
int a[c][c];
int main()
{
	int n,m,c;
	cin>>n>>m>>c;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			arr[i][j]=arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1]+a[i][j];
		}
	}
	int maxx=INT_MIN,x=0,y=0;
	for(int i=c;i<=n;i++)
	{
		for(int j=c;j<=m;j++)
		{
			int sum=arr[i][j]+arr[i-c][j-c]-arr[i-c][j]-arr[i][j-c];
			if(sum>maxx)
			{
				maxx=sum;
				x=i;
				y=j;
			}
		}
	}
	cout<<x-c+1<<' '<<y-c+1<<endl;
	return 0;
 } 
