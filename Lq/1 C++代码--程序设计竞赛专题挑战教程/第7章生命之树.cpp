//生命之树 2015年第六届省赛  https://www.lanqiao.cn/problems/131/learning/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100010;
ll dp[N];
ll res;
vector<int> tree[N];    //用邻接表存树的边
int w[N];
void dfs(int u, int fa){
    for (int i = 0; i < tree[u].size(); i ++ ){
        int son = tree[u][i];
        if (son != fa){      //重要：不遍历父亲
            dfs(son, u);     // 对子结点进行递归
            if(dp[son]>0) dp[u] += dp[son]; //如果子结点及其子树权值和大于零，则加入到父结点的权值
        }
    }
    res = max(res, dp[u]);  //查找最大权值和
}
int main(){
    int n; cin >> n;
    for (int i = 1; i <= n; i ++ )    cin >> w[i], dp[i] = w[i];
    for (int i = 0; i < n - 1; i ++ ){
        int u, v;    scanf("%d%d", &u, &v);
        tree[u].push_back(v);    tree[v].push_back(u);   //双向边
    }
    dfs(1, -1);   //任选一个点开始DFS，这里选1号点
    cout << res;
    return 0;
}

