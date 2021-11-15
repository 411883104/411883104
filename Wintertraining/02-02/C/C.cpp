#include<iostream>
#include<cstring>
using namespace std;
const int c=1010;
int a[c][c];
int b[c][c];
int d[c][c];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		scanf("%d",&a[i][j]);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		scanf("%d",&b[i][j]);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++) 
			d[i][j]+=a[i][k]*b[k][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ",d[i][j]);
		}
		printf("\n");
	}
	return 0;
 } 
