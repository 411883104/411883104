//砝码称重  2021年第十一届省赛 https://www.lanqiao.cn/problems/1447/learning/

#include <bits/stdc++.h>
using namespace std;
bool dp[110][200001];
int main(){
    int n; cin>>n;
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        int w; cin>>w;
        for(int j=0;j<=100000;j++)
            dp[i][j]=dp[i-1][j] | dp[i-1][abs(j-w)] | dp[i-1][j+w];
    }
    int ans = 0;
    for(int i=1;i<=100000;i++) ans += dp[n][i];
    cout<<ans;
}
