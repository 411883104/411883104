//发现环  2017年第八届决赛   https://www.lanqiao.cn/problems/108/learning/


#include <bits/stdc++.h>
using namespace std;
const int N=1e5+100;
vector<int> edge[N]; //邻接表
int s[N],vis[N],ring[N];
int start,flag;
int tot;      //环上点的数量
void init_set(){
    for(int i=1;i<=N;i++)   s[i]=i;
}
int find_set(int x){
    if(x!=s[x])  s[x]=find_set(s[x]);
    return s[x];
}
void merge_set(int x,int y){
    int tmp = x;
    x = find_set(x);
    y = find_set(y);
    if(x!=y) s[y]=s[x];
    else     start = tmp; //此x和y处于环中,记录一个点
}
void dfs(int x,int step){ //从起点start出发找一条回到start的环路
    if(flag)    return;
    if(x==start) //绕了一圈回来了，环路结束
        if(vis[x]==1){
            tot = step-1;
            flag = 1;
            return ;
        }
    ring[step] = x;
    for(int i=0;i<edge[x].size();i++)   {
        int y=edge[x][i];
        if(!vis[y]){
            vis[y]=1;
            dfs(y,step+1);
            vis[y]=0;
        }
    }
}
int main(){
   int n;   scanf("%d",&n);
    init_set();
    for(int i=1;i<=n;i++) {
        int u,v;  scanf("%d %d",&u,&v);
        edge[u].push_back(v);   edge[v].push_back(u);
        merge_set(u,v);  //找到环上一个点start
    }
    flag = 0;
    //以start为起点再次搜回来，这就是环
    dfs(start,1);
    sort(ring+1,ring+1+tot);
    for(int i=1;i<=tot;i++)  printf("%d ",ring[i]);
    return 0;
}
