//回形取数    https://www.lanqiao.cn/problems/1517/learning/

#include<bits/stdc++.h>
using namespace std;
int a[201][201];   //存矩阵
int vis[201][201]; //标记这个坐标的点是否已经取过
int main(){
    int n,m;  cin >> n >> m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin >> a[i][j];
    int x=1, y=1;
    cout << a[1][1];
    vis[1][1] = 1;      //标记这个坐标点已经取过
    int sum = 1;
    while(sum < n*m){   //下面分别处理上、下、左、右四个方向
        while(x+1<=n && vis[x+1][y]==0){
            cout << " " << a[++x][y] ;
            vis[x][y]=1;
            sum++;
        }
        while(y+1<=m && vis[x][y+1]==0){
            cout << " " << a[x][++y] ;
            vis[x][y]=1;
            sum++;
        }
        while(x-1>=1 && vis[x-1][y]==0){
            cout << " " << a[--x][y] ;
            vis[x][y]=1;
            sum++;
        }
        while(y-1>=1 && vis[x][y-1]==0){
            cout << " " << a[x][--y] ;
            vis[x][y] = 1;
            sum++;
        }
    }
    return 0;
}
