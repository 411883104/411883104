/*
 * @Author       : Outsider
 * @Date         : 2023-03-15 19:45:19
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-03-15 19:45:31
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\other\cc.cc
 */
#include<bits/stdc++.h>
using namespace std;
int n,m;
int ne[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int book[1510][1510];
char s[1510][1510];
struct p { int x,y; };
int f(int x,int y) { return (x+n*4)/n*131+(y+m*4)/m*13; }//随便写的hash函数 
bool bfs(int x,int y)
{
	queue<p> q;
	q.push((p){x,y});
	book[x][y]=f(x,y);
	while(!q.empty())
	{
		p u=q.front(),v; q.pop();
		for(int i=0;i<4;i++)
		{
			v.x=u.x+ne[i][0]; v.y=u.y+ne[i][1];
			int tx=(v.x+n*4)%n,ty=(v.y+m*4)%m,t=f(v.x,v.y);//怕负数取模出问题 所以加上了n*4 
			if(s[tx][ty]=='#') continue;
			if(!book[tx][ty]) book[tx][ty]=t,q.push(v);
			else if(book[tx][ty]!=t) return 1; 
		}
	}
	return 0;
}
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(book,0,sizeof(book));
		for(int i=0;i<n;i++) scanf("%s",s[i]);
		int x,y;
		for(int i=0;i<n;i++) 
			for(int j=0;j<m;j++)
				if(s[i][j]=='S')
				{
					x=i; y=j;
					break;
				}
		if(bfs(x,y)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}