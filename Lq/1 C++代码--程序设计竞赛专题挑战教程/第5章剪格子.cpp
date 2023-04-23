//剪格子   https://www.lanqiao.cn/problems/211/learning/

#include<bits/stdc++.h>
using namespace std;
const int N=15;
int n, m;
int a[N][N], vis[N][N]; //格子是否被访问过
int sum, ans=100000;
int d[4][2] = { {1,0},{0,-1},{0,1},{-1,0} };  //4个方向
void dfs(int x, int y, int c, int s) {
    if (2*s>sum)  return;    //剪枝
    if (2*s==sum) {
        if (c<ans && vis[0][0]) ans = c; //左上角格子最少数量
        return;
    }
    vis[x][y]=1;
    for (int k=0; k<4; k++) {
        int tx=x+d[k][0], ty=y+d[k][1];
        if (tx>=0 && tx<n && ty>=0 && ty<m && !vis[tx][ty])
            dfs(tx,ty,c+1,s+a[x][y]);
    }
    vis[x][y]=0;
}
int main() {
    cin>>m>>n;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            cin>>a[i][j], sum+=a[i][j]; //求所有格子的和
    dfs(0,0,0,0);
    cout<<(ans==100000 ? 0 : ans);
    return 0;
}
