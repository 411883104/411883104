#include<iostream>
using namespace std;
typedef long long ll;
const int c=100001;
const ll mod=1000000007;
int vis[c];
int sum[c];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<=n;i++)
	{
		vis[i]=0;
		sum[i]=0;
	}
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		vis[x]=1;
	}
	sum[0]=1;
	if(!vis[1])
	{
		sum[1]=1;
	}
	for(int i=2;i<=n;i++)
	{
		if(!vis[i])
		{
			//�ܵ����į�׵����������ܵ����i-1̨�׵����������ܵ����i-2̨�׵�����
			//��Ϊ�ڵ�i-2̨����2�׺��ڵ�i-1̨����1�׿ɵ����i�� 
			sum[i]=sum[i-1]+sum[i-2]; 
		}
		sum[i]=sum[i]%mod;
	}
	cout<<sum[n]<<endl;
}
