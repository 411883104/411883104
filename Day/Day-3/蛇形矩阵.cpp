#include<iostream>
#include<cstring>
using namespace std;
const int c=110;
int arr[c][c];
int x[4]={1,0,-1,0};
int y[4]={0,1,0,-1};
int main()
{
	int n,m;
	cin>>n>>m;
	int d=0,dx=1,dy=1;
	for(int i=1;i<=n*m;i++)
	{
		arr[dy][dx]=i;
		if(dx+x[d]>m||dy+y[d]>n||dy+y[d]<1||dx+x[d]<1||arr[dy+y[d]][dx+x[d]])
		{
			d=(d+1)%4;
		}
		dx+=x[d],dy+=y[d];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<arr[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
 } 
