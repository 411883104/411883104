/*
 * @Author: Outsider
 * @Date: 2021-11-12 20:46:10
 * @LastEditors: Outsider
 * @LastEditTime: 2021-11-13 14:08:20
 * @Description: In User Settings Edit
 * @FilePath: \C++\Luogu\P1141.cpp
 */
#include<iostream>
#include<queue>
using namespace std;
const int c=1005;
int n,m;
char arr[c][c];
int cnt[c][c];
int res[c][c];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int map[1000005];
struct Node{
    int x;
    int y;
};
int sum=0;
queue<Node> q;
void bfs(int x,int y)
{
    int result=0;
    Node now,next;
    now.x=x;
    now.y=y;
    q.push(now);
    cnt[now.x][now.y]=1;
    sum++;
    res[now.x][now.y]=sum;
    while(!q.empty())
    {
        now=q.front();
        result+=1;
        for(int i=0;i<4;i++)
        {
            int nx=now.x+dx[i];
            int ny=now.y+dy[i];
            if(cnt[nx][ny]==0&&(arr[nx][ny]!=arr[now.x][now.y])&&(nx>=0)&&(ny>=0)&&(ny<n)&&(nx<n))
            {
                next.x=nx;
                next.y=ny;
                cnt[next.x][next.y]=1;
                res[next.x][next.y]=sum;
                q.push(next);
            }
        }
        q.pop();
    }
    map[sum]=result;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(cnt[i][j]==0)
                bfs(i,j);
        }
    }
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        cout<<map[res[x-1][y-1]]<<endl;
    }
    system("pause");
}