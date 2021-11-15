#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int c=210;
int n,m;
char arr[c][c];
int vis[c][c];
int l[4]={0,0,1,-1};
int r[4]={1,-1,0,0};
struct p
{
	int x;
	int y;
};
queue<p>q1,q2;
int sum1=0,sum2=0;
void bfs(int x,int y,int m,int n)
{
	p now1,next1,now2,next2;
	now1.x=x;
	now1.y=y;
	now2.x=m;
	now2.y=n;
	q1.push(now1);
	q2.push(now2);
	while(!q1.empty())
	{
		now1=q1.front();
		q1.pop();
		if(arr[now1.x][now1.y]=='@')
		{
			sum1++;
			while(!q1.empty())
			{
				q1.pop();
			}
		}
		else
		{
			for(int i=0;i<4;i++)
			{
				next1.x=now1.x+l[i];
				next1.y=now1.y+r[i];
				if(arr[next1.x][next1.y]=='@')
				{
					sum1++;
					while(!q1.empty())
					{
						q1.pop();
					}
				}
				else
				{
					if(next1.x<n&&next1.x>=0&&next1.y<m&&next1.y>=0&&vis[next1.x][next1.y])
					{
						q1.push(next1);
					}
				}
			}
		}
	}
}
int main()
{
	
	while(cin>>n>>m)
	{
		sum1=0,sum2=0;
		int y1,y2,m1,m2; 
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>arr[i][j];
				vis[i][j]=1;
				if(arr[i][j]=='#')
				{
					vis[i][j]=0;
				}
				if(arr[i][j]=='Y')
				{
					y1=i;
					y2=j;
				}
				if(arr[i][j]=='M')
				{
					m1=i;
					m2=j;
				}
			}
		}
		bfs(y1,y2,m1,m2);
		cout<<sum1<<endl;
	}
} 
