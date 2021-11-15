//顺序获取：要处理边界 
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#include<climits> 
//using namespace std;
//const int c=510;
//int arr[c][c];
//int maxx[c][c];
//int main()
//{
//	int n;
//	cin>>n;
//	//要先将边界值置为最小 
//	for(int i=0;i<=n+1;i++)
//	{
//		for(int j=0;j<=n+1;j++)
//		{
//			arr[i][j]=INT_MIN;
//			maxx[i][j]=INT_MIN;
//		}
//	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=i;j++)
//		{
//			cin>>arr[i][j]; 
//		}
//	}
//	maxx[1][1]=arr[1][1];//将开始值等于第一个数 
//	for(int i=2;i<=n;i++)//注意i从2开始 
//	{
//		for(int j=1;j<=i;j++)
//		{
//			//最大值由其上方或左上方最大值获得 
//			maxx[i][j]=max(maxx[i-1][j],maxx[i-1][j-1])+arr[i][j];
//		}
//	}
//	int res=-1e9;
//	for(int i=1;i<=n;i++)
//	{
//		//最大数据存放在最后一行中，从最后一行获得 
//		res=max(res,maxx[n][i]);
//	}
//	cout<<res<<endl;
//	return 0; 
//} 


//逆序获取：不用处理边界 
#include<iostream>
#include<algorithm>
#include<cstring>
#include<climits> 
using namespace std;
const int c=510;
int arr[c][c];
int maxx[c][c];
int main()
{
	int n;
	cin>>n;
//	//要先将边界值置为最小 
//	for(int i=0;i<=n+1;i++)
//	{
//		for(int j=0;j<=n+1;j++)
//		{
//			arr[i][j]=INT_MIN;
//			maxx[i][j]=INT_MIN;
//		}
//	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			cin>>arr[i][j]; 
		}
	}
//	maxx[1][1]=arr[1][1];//将开始值等于第一个数 
	for(int i=n;i>0;i--)//注意i从2开始 
	{
		for(int j=1;j<=i;j++)
		{
			//最大值由其上方或左上方最大值获得 
			maxx[i][j]=max(maxx[i+1][j],maxx[i+1][j+1])+arr[i][j];
		}
	}
//	int res=-1e9;
//	for(int i=1;i<=n;i++)
//	{
//		//最大数据存放在最后一行中，从最后一行获得 
//		res=max(res,maxx[n][i]);
//	}
//	cout<<res<<endl;
	cout<<maxx[1][1]<<endl;
	return 0; 
} 
