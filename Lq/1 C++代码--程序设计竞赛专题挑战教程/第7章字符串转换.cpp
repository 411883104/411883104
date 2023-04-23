//编辑距离， 字符串转换 https://www.lanqiao.cn/problems/1507/learning/



#include<bits/stdc++.h>
using namespace std;
int dp[3005][3005],m,n;
char a[3005],b[3005];
void solve(){
    dp[0][0]=0;
    for(int i=1;i<=m;i++)   dp[i][0]=i;
    for(int j=1;j<=n;j++)   dp[0][j]=j;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)  {
            if(a[i] == b[j])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
        }
}
int main(){
    scanf("%s %s",a+1,b+1);  //a[0],b[0]不用
    m = strlen(a+1);
    n = strlen(b+1);
    solve();
    printf("%d\n",dp[m][n]);
}
