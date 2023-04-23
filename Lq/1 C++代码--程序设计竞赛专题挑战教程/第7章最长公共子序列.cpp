//最长公共子序列   https://www.lanqiao.cn/problems/1189/learning/


#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001],a[1001],b[1001];
int main(){
    int n,m;    cin>>n>>m;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++) scanf("%d",&b[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) {
            if(a[i]==b[j]) dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
            else           dp[i][j] = max(dp[i-1][j],dp[i][j-1]);

        }
   cout << dp[n][m];
}
