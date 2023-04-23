//迷宫  2017年第八届蓝桥杯省赛C/C++大学A组，Java大学A组  https://www.lanqiao.cn/problems/641/learning


#include<bits/stdc++.h>
using namespace std;
const int n=10;
char mp[n+2][n+2];
bool vis[n+2][n+2];
int solve[n+2][n+2];   //solve[i][j]=1表示这个点能走出去；=2表示出不去
int ans = 0;
int cnt = 0;
bool dfs(int i, int j){
    if (i<0 || i>n-1 || j<0 || j>n-1) return true;
    if(solve[i][j]==1)   return true;   //点(i,j)已经算过了，能出去
    if(solve[i][j]==2)   return false;  //点(i,j)已经算过了，出不去
    if (vis[i][j])       return false;
    cnt++;                   //统计dfs()了多少次
    vis[i][j] = true;
    if (mp[i][j] == 'L'){
        if(dfs(i, j - 1)){ solve[i][j] = 1;  return true;}
                          //回退，记录整条路径都能走出去
        else             { solve[i][j] = 2;  return false;}
                          //回退，记录整条路径都出不去
    }
    if (mp[i][j] == 'R') {
        if(dfs(i, j + 1)){ solve[i][j] = 1;return true;}
        else             { solve[i][j] = 2;return false;}
    }
    if (mp[i][j] == 'U') {
        if(dfs(i - 1, j)){ solve[i][j] = 1;return true;}
        else             { solve[i][j] = 2;return false;}
    }
    if (mp[i][j] == 'D') {
        if(dfs(i + 1, j)){ solve[i][j] = 1;return true;}
        else             { solve[i][j] = 2;return false;}
    }
}
int main(){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mp[i][j];
    memset(solve, 0, sizeof(solve));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            memset(vis, 0, sizeof(vis));
            if(dfs(i, j))   ans++;
        }
    cout <<"ans="<< ans <<",cnt="<<cnt<< endl;     //cnt=100
    return 0;
}
