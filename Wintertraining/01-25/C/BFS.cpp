#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const ll c=1e5+5;
const ll mod=1000000007;
ll vis[c];
ll arr[2];
queue<ll>q;
ll bfs(ll n)
{
	ll now,next;
	ll sum=0;
	q.push(0);
	while(!q.empty())
	{
		now=q.front();
		q.pop();
		if(now==n)
		{
			sum++;
		}
		else
		{
			arr[0]=1;
			arr[1]=2;
			for(int i=0;i<2;i++)
			{
				next=now+arr[i];
				if(next==n)
				{
					sum++;
				}
				else
				{
					if(vis[next]&&next<=n&&next>=0)
						q.push(next);
				}
			}
		}
		sum=sum%mod;
	}
	return sum;
}
int main() 
{
	ll n,m;
	cin>>n>>m;
	fill(vis,vis+c,1);
	for(ll i=1;i<=m;i++)
	{
		int x;
		cin>>x;
		vis[x]=0;
	}
	cout<<bfs(n)<<endl;
}
