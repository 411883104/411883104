#include<iostream>
#include<algorithm> 
using namespace std;
const int c=110;
int stu[c];//ѧ����� 
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
	//Ѱ��������������� 
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
	//Ѱ������½������� 
	for(int i=n-1;i>=0;i--)
	{
		dp2[i]=1;//i��j�����ܴ�0��ʼ�����������0��ʼ���ʾiΪ�±��ǰ���������� 
		for(int j=n-1;j>i;j--)//�Ӻ�ʼ������ʾi������������ 
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
		maxx=max(maxx,dp1[i]+dp2[i]-1);//��1����Ϊ���ζ��㵽�����Ӵ�dp[i]������ 
	}
	cout<<n-maxx<<endl;
	return 0;
} 


//������������Ϊ���ֵ�����ж�� 
//#include<iostream>
//#include<algorithm> 
//using namespace std;
//const int c=110;
//int stu[c];//ѧ����� 
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
//	for(int i=0;i<n;i++)//Ѱ�����ֵ 
//	{
//		if(stu[i]>maxx)
//		{
//			maxx=stu[i];
//			vis=i;//��ȡ���ֵ���±� 
//		}
//	}
//	//Ѱ��ǰ���������������� 
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
//	//Ѱ�Һ�������½������� 
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
