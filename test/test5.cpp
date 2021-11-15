#include<iostream>
#include<queue>
using namespace std;
const int c=110;
int vis[c][c];
int arr1[4]={1,0,-1,0};
int arr2[4]={0,-1,0,1};
char arr[c][c];
int xs,ys,xe,ye;
int n,m;
struct p
{
    int x;
    int y;
    int s;
};
queue<p>q;
bool bfs()
{
	p now,next;
    now.x=xs;
    now.y=ys;
    now.s=0;
	q.push(now);
	vis[now.x][now.y]=1;
	while(!q.empty())
	{
		now=q.front();
        q.pop();
		if(now.x==xe&&now.y==ye)
		{
			cout<<now.s*100<<endl;
			return true;
		}
		else
		{
			for(int i=0;i<4;i++)
			{
				next.x=now.x+arr1[i];
                next.y=now.y+arr2[i];
                next.s=now.s+1;
				if(next.x>0&&next.y>0&&next.x<=n&&next.y<=m&&vis[next.x][next.y]==0)
                {
					vis[next.x][next.y]=1;
					q.push(next);
				}
			}
        }
	}
	return false;
}
int main()
{
	cin>>n>>m;
    cin>>xs>>ys>>xe>>ye;
	for(int i=1;i<=n;i++)
	{
        for(int j=1;j<=m;j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]=='#')
                vis[i][j]=1;
        }
    }
	bool v=bfs();
    if(v==false)
    {
        cout<<"-1"<<endl;
    }
	return 0; 
} 
