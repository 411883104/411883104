//迷宫 2019年第十届省赛  https://www.lanqiao.cn/problems/602/learning/

//注意本题是填空题。下面代码直接提交到oj，“答案错误”。自己运行得到答案后，再把答案提交到OJ。
#include<bits/stdc++.h>
using namespace std;
struct node{ int x, y; };
char mp[31][51];
char k[4]={'D','L','R','U'};
int dir[4][2]={{1,0},{0,-1},{0,1},{-1,0}};
int vis[30][50];
char pre[31][51];   //用于查找前驱点。例如pre[x][y] = ‘D’，表示上一个点往下走一步到了(x,y)，那么上一个点是(x-1,y)
void print_path(int x,int y){      //打印路径：从(0,0)到(29,49)
  if(x==0 && y==0) return;         //回溯到了起点，递归结束，返回
  if(pre[x][y]=='D')  print_path(x-1,y);   //回溯，往上 U
  if(pre[x][y]=='L')  print_path(x,  y+1); //回溯，往右 R
  if(pre[x][y]=='R')  print_path(x,  y-1);
  if(pre[x][y]=='U')  print_path(x+1,y);
  printf("%c",pre[x][y]);                  //最后打印的是终点
}
void bfs(){
    node start;
    start.x=0;  start.y=0;
    vis[0][0]=1;
    queue<node>q;
    q.push(start);             //把第一个点放进队列，开始BFS
    while(!q.empty()){
        node now=q.front();  q.pop();
        if(now.x==29 && now.y==49){
            print_path(29,49); //打印完整路径，从终点回溯到起点，打印出来是从起点到终点的正序
            return;
        }
        for(int i=0;i<4;i++){
            node next;
            next.x = now.x+dir[i][0];
            next.y = now.y+dir[i][1];
            if(next.x<0||next.x>=30||next.y<0||next.y>=50) continue;
            if(vis[next.x][next.y]==1 || mp[next.x][next.y]=='1') continue;
            vis[next.x][next.y]=1;
            pre[next.x][next.y] = k[i];   //记录点(x,y)的前驱
            q.push(next);
        }
    }
}
int main(){
    for(int i=0;i<30;i++)  cin >> mp[i];
    bfs();
}
