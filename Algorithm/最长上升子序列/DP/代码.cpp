//(动态规划) 时间复杂度O(n^2)
#include<iostream>
#include<algorithm>
using namespace std;
const int c=1010;
int dp[c];//状态表示：dp[i]表示从第一个数字开始算，以num[i]结尾的最大的上升序列.
int num[c];//数列 
int main() 
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>num[i];//读入数列 
	}
	int maxx=1;//初始化最大值 
	//相当于两个划分，走在前面的为i，后面的为j 
	for(int i=0;i<n;i++)
	{
		dp[i]=1;//num[i]默认为1，找不到前面数字小于自己的时候就为1
		for(int j=0;j<i;j++)
		{
			if(num[j]<num[i])//当前数小于num[i]时记录 
			{
				dp[i]=max(dp[i],dp[j]+1);//前一个小于自己的数结尾的最大上升子序列加上自己，即+1
			}
		}
		maxx=max(maxx,dp[i]);//取最大值 
	} 
	cout<<maxx<<endl;
	return 0; 
}
