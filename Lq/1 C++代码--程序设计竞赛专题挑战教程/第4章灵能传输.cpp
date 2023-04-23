//灵能传输  https://www.lanqiao.cn/problems/196/learning/

#include<bits/stdc++.h>
using namespace std;
const int N = 3e5;
long long a[N],s[N];
bool vis[N];
int main(){
    int T;    scanf("%d",&T);
    while(T--){
        memset(vis,0,sizeof(vis));
        int n;   scanf("%d",&n);
        s[0]=0;
        for(int i=1;i<=n;++i){scanf("%lld",&s[i]);  s[i] += s[i-1]; } //计算前缀和
        long long s0=0,sn=s[n];
        if(s0>sn) swap(s0,sn);
        sort(s,s+n+1);
        int L=0,R=n;
        for(int i = lower_bound(s,s+n+1,s0) - s;i>=0;i-=2)
           a[L++]=s[i], vis[i]=1;     //图中的路线1: 从s0到min。隔一个数取一个

        for(int i = lower_bound(s,s+n+1,sn)-s;i<=n;i+=2)
            a[R--]=s[i], vis[i]=1;   //图中的路线3:  从max到sn。隔一个数取一个
        for(int i=0;i<=n;++i)        //图中的路线2：从min到max
            if(!vis[i])  a[L++]=s[i];
        long long res=0;
        for(int i=1;i<=n;++i)  res = max(res,abs(a[i]-a[i-1]));
        printf("%lld\n",res);
    }
    return 0;
}
