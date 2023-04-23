//排列数  2019年第十届国赛 https://www.lanqiao.cn/problems/240/learning/


#include<bits/stdc++.h>
using namespace std;
const int N = 520;
const int mod = 123456;
int dp[N][N];
int main() {
    int n, k;  cin >> n >> k;
    dp[1][1] = 1;
    dp[2][1] = 2;
    for (int i = 3; i <= n; i++)
        for (int j = 1; j <= k && j <= i; j++){
            dp[i][j] += dp[i-1][j]*j+ dp[i-1][j-1]*2;
            if (j > 1)  dp[i][j] += dp[i-1][j-2]*(i-j);
            dp[i][j] %= mod;
        }
    cout << dp[n][k];
    return 0;
}
