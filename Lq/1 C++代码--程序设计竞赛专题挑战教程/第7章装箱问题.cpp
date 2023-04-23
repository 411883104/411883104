//装箱问题  https://www.lanqiao.cn/problems/763/learning/

#include<bits/stdc++.h>
using namespace std;
int dp[20010];
int w[40];
int main(){
    int V,n;   scanf("%d%d",&V,&n);
    for(int i=1;i<=n;i++) scanf("%d",&w[i]);
    for(int i=1; i<=n; i++)
        for(int j=V; j>=w[i]; j--)
              dp[j] =max(dp[j], dp[j-w[i]]+w[i]);
    printf("%d\n",V-dp[V]);
}
