//大臣的旅费  2005年第四届省赛   https://www.lanqiao.cn/problems/207/learning/

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct edge{int to,w; };    //to: 边的终点  w:权值
vector<edge> e[N];
int dp[N];
int maxlen = 0;
bool vis[N];
void dfs(int u){
    vis[u] = true;
    for(int i = 0; i < e[u].size(); ++ i){
        int v = e[u][i].to, edge = e[u][i].w;
        if(vis[v])  continue;
        dfs(v);
        maxlen = max(maxlen, dp[u]+ dp[v]+ edge);
        dp[u] = max(dp[u], dp[v] + edge);
    }
    return ;
}
int main(){
    int n;    cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b, c;     cin >> a >> b >> c;
        e[a].push_back({b,c});  //a的邻居是b，路的长度c
        e[b].push_back({a,c});  //b的邻居是a
    }
    dfs(1);
    cout << maxlen*10 + maxlen*(maxlen+1)/2 << endl;
    return 0;
}
