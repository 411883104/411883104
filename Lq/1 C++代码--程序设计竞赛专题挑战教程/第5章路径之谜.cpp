//路径之谜  2016年第七届决赛   https://www.lanqiao.cn/problems/89/learning

#include<bits/stdc++.h>
using namespace std;
int n;
int a[25],b[25],vis[25][25];
vector<int> path;       //记录路径
int d[4][2]={1,0,-1,0,0,1,0,-1};   //上下左右
void dfs(int x,int y){
    //if(a[x]<0 || b[y]<0) return;   //剪枝
    if(x==n-1 && y==n-1){          //走到出口
        int ok=1;
        for(int i = 0;i < n;i++)
            if(a[i]!=0 || b[i]!=0){ ok=0; break;}
        if(ok)
            for(int i = 0;i < path.size();i++)   cout << path[i] <<" ";
    }
    for(int i = 0;i < 4;i++){
        int tx = x + d[i][0],ty = y + d[i][1];
        if(vis[tx][ty]==0 && tx>=0 && tx<n && ty>=0 && ty<n){
            vis[tx][ty]=1;
            path.push_back(tx*n + ty); //进栈，记录路径
            a[tx]--;    b[ty]--;
            dfs(tx,ty);
            path.pop_back();          //出栈，DFS回溯
            a[tx]++;    b[ty]++;
            vis[tx][ty]=0;
        }
    }
}
int main(){
    cin >> n;
    for(int i = 0;i < n;i++) cin >> b[i];
    for(int i = 0;i < n;i++) cin >> a[i];
    path.push_back(0);
    vis[0][0]=1;
    a[0]--;  b[0]--;
    dfs(0,0);
    return 0;
}

