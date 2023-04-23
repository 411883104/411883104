//合根植物  2017年第八届决赛  https://www.lanqiao.cn/problems/110/learning/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int s[N];
int find_set(int x){
    if(x!=s[x])  s[x]=find_set(s[x]);
    return s[x];
}
int main(){
    int n,m,k;   scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=N;i++)  s[i]=i;   //初始化并查集
    while(k--){
        int a,b;   scanf("%d%d",&a,&b);
        int pa = find_set(a),pb=find_set(b);
        if(pa!=pb)  s[pa] = pb;    //合并并查集
    }
    int ans=0;
    for(int i=1;i<=n*m;i++)
        if(s[i]==i)  ans++;
    printf("%d",ans);
    return 0;
}

