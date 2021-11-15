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
			//能到达第i台阶的总数等于能到达第i-1台阶的总数加上能到达第i-2台阶的总数
			//因为在第i-2台阶走2阶和在第i-1台阶走1阶可到达第i阶 
			sum[i]=sum[i-1]+sum[i-2]; 
		}
		sum[i]=sum[i]%mod;
	}
	cout<<sum[n]<<endl;
}
