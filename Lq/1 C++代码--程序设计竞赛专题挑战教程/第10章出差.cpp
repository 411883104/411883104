//出差 https://www.lanqiao.cn/problems/2194/learning/

#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int M = 20010;       //双向边的最大数量
int t[M];
int dist[M];                    //dist[i]: 起点到第i点的最短路
struct edge{int a,b,c;}e[M];    //分开操作也行：int a[M],b[M],c[M];
int main(){
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>t[i];
    for(int i=1;i<=m;i++){
        int a,b,c;  cin >>a>>b>>c;
        e[i].a=a;   e[i].b=b;   e[i].c=c;    //双向边，a->b
        e[m+i].a=b; e[m+i].b=a; e[m+i].c=c;  //双向边: b->a
    }
    //下面开始bellman-ford
    memset(dist,INF,sizeof(dist));//初始化为无穷大
    dist[1]=0;               //起点是1，到自己距离为0
    for(int k=1;k<=n;k++){  //一共有n轮操作
        for(int i=1;i<=2*m;i++){  //检查每条边
            int u=e[i].a,v=e[i].b;  //u的一个邻居是v
            int res = t[v];       //隔离时间
            if(v==n) res = 0;     //终点不用隔离
            dist[v]=min(dist[v],dist[u]+e[i].c+res);  //u通过v到起点的距离更短，更新
        }
    }
    cout<<dist[n];
    return 0;
}
