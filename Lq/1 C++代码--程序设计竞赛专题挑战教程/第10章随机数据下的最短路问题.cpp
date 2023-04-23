//随机数据下的最短路问题  https://www.lanqiao.cn/problems/1366/learning/
#include<bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int N = 5e3+10;
struct edge{
    int to;    long long w;
    edge(int tt,long long ww) {to = tt; w = ww;}
};
long long dist[N];
int inq[N];
vector<edge> e[N];
void spfa(int s){
    memset(dist,0x3f,sizeof(dist));
    dist[s] = 0;    //起点到自己的距离是0
    queue<int> q;
    q.push(s);      //从s开始，s进队列
    inq[s] = 1;  //起点在队列中
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = 0;   //u已经不在队列中
        if(dist[u] == INF)     continue;
        for(int i = 0;i < e[u].size();i++) { //遍历u的邻居
            int v = e[u][i].to;
            long long w = e[u][i].w;
            if(dist[v] > dist[u]+w) { //u的第i个邻居v，它借道u，到s更近
                dist[v] = dist[u]+w;  //更新邻居v到s的距离
                if(!inq[v]) {   //邻居v更新状态了，但v不在队列中，放进队列
                    q.push(v);
                    inq[v] = 1;
                }
            }
        }
    }
}

int main(){
    int n,m,s;cin>>n>>m>>s;
    for(int i = 1;i <= m;i++)    {
        int u,v; long long w;
        cin>>u>>v>>w;
        e[u].push_back(edge(v,w));
    }
    spfa(s);
    for(int i = 1;i <= n;i++) {
        if(dist[i]==INF)  cout << -1;
        else              cout << dist[i];
        if(i != n)        cout << " ";
        else              cout << endl;
    }
    return 0;
}
