#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int c=10;
int n,m,t;
char arr[c][c];
int vis[c][c];
int sept[c][c];
int l[4]={0,0,1,-1};
int r[4]={1,-1,0,0};
struct p
{
	int x;
	int y;
};
queue<p>q; 
int bfs(int x,int y)
{
	int sum=0;
	p now,next;
	now.x=x;
	now.y=y;
	q.push(now);
	while(!q.empty())
	{
		now=q.front();
		if(arr[now.x][now.y]=='D')
		{
			sum=sept[now.x][now.y];
			return sum;
		}
		else
		{
			for(int i=0;i<4;i++)
			{
				next.x=now.x+l[i];
				next.y=now.y+r[i];
				if(arr[next.x][next.y]=='D')
				{
					while(!q.empty())
					{
						q.pop();
					}
					sept[next.x][next.y]=sept[now.x][now.y]+1;
					q.push(now);
					q.push(next);
				}
				else
				{
					if(next.x<n&&next.x>=0&&next.y<m&&next.y>=0&&vis[next.x][next.y])
					{
						sept[next.x][next.y]=sept[now.x][now.y]+1;
						vis[next.x][next.y]=0;
						q.push(next);
					}
				}
			}
		}
		q.pop();
	}
}
int main()
{
	while(cin>>n>>m>>t&&n&&m&&t)
	{
		int x,y;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>arr[i][j];
				vis[i][j]=1;
				sept[i][j]=0;
				if(arr[i][j]=='X')
				{
					vis[i][j]=0;
				}
				if(arr[i][j]=='S')
				{
					x=i;
					y=j;
				}
				
			}
		}
		sept[x][y]=0;
		while(!q.empty())
		{
			q.pop();
		}
		if(bfs(x,y)==t)
		{
			cout<<"YES"<<endl; 
		}
		else
		{
			cout<<"NO"<<endl; 
		}
	}
	return 0;
} 
