//(��̬�滮) ʱ�临�Ӷ�O(n^2)
#include<iostream>
#include<algorithm>
using namespace std;
const int c=1010;
int dp[c];//״̬��ʾ��dp[i]��ʾ�ӵ�һ�����ֿ�ʼ�㣬��num[i]��β��������������.
int num[c];//���� 
int main() 
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>num[i];//�������� 
	}
	int maxx=1;//��ʼ�����ֵ 
	//�൱���������֣�����ǰ���Ϊi�������Ϊj 
	for(int i=0;i<n;i++)
	{
		dp[i]=1;//num[i]Ĭ��Ϊ1���Ҳ���ǰ������С���Լ���ʱ���Ϊ1
		for(int j=0;j<i;j++)
		{
			if(num[j]<num[i])//��ǰ��С��num[i]ʱ��¼ 
			{
				dp[i]=max(dp[i],dp[j]+1);//ǰһ��С���Լ�������β��������������м����Լ�����+1
			}
		}
		maxx=max(maxx,dp[i]);//ȡ���ֵ 
	} 
	cout<<maxx<<endl;
	return 0; 
}
