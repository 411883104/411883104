#include<iostream>
#include<algorithm> 
using namespace std;
const int c=110;
int stu[c];//学生身高 
int dp1[c];
int dp2[c];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>stu[i];
	}
	//寻找最大上升子序列 
	for(int i=0;i<n;i++)
	{
		dp1[i]=1;
		for(int j=0;j<i;j++)
		{
			if(stu[j]<stu[i])
			{
				dp1[i]=max(dp1[j]+1,dp1[i]);
			}
		}
	}
	//寻找最大下降子序列 
	for(int i=n-1;i>=0;i--)
	{
		dp2[i]=1;//i和j都不能从0开始遍历，如果从0开始则表示i为下标的前面的最大序列 
		for(int j=n-1;j>i;j--)//从后开始遍历表示i后面的最大序列 
		{
			if(stu[j]<stu[i])
			{
				dp2[i]=max(dp2[j]+1,dp2[i]);
			}
		}
	}
	int maxx=0;
	for(int i=0;i<n;i++)
	{
		maxx=max(maxx,dp1[i]+dp2[i]-1);//减1是因为两次都算到了连接处dp[i]的数据 
	}
	cout<<n-maxx<<endl;
	return 0;
} 


//错误做法：因为最大值可能有多个 
//#include<iostream>
//#include<algorithm> 
//using namespace std;
//const int c=110;
//int stu[c];//学生身高 
//int dp[c];
//int main()
//{
//	int n;
//	cin>>n;
//	for(int i=0;i<n;i++)
//	{
//		cin>>stu[i];
//	}
//	int maxx=100;
//	int vis=0;
//	for(int i=0;i<n;i++)//寻找最大值 
//	{
//		if(stu[i]>maxx)
//		{
//			maxx=stu[i];
//			vis=i;//获取最大值的下标 
//		}
//	}
//	//寻找前半段最大上升子序列 
//	int left=1;
//	for(int i=0;i<vis;i++)
//	{
//		dp[i]=1;
//		for(int j=0;j<i;j++)
//		{
//			if(stu[j]<stu[i])
//			{
//				dp[i]=max(dp[j]+1,dp[i]);
//			}
//		}
//		left=max(dp[i],left);
//	}
//	//寻找后半段最大下降子序列 
//	int right=1;
//	for(int i=vis;i<n;i++)
//	{
//		dp[i]=1;
//		for(int j=vis;j<i;j++)
//		{
//			if(stu[j]>stu[i])
//			{
//				dp[i]=max(dp[j]+1,dp[i]);
//			}
//		}
//		right=max(dp[i],right);
//	}
//	cout<<n-(left+right)<<endl;
//	return 0;
//} 
