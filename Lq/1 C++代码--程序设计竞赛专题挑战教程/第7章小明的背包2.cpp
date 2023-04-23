//小明的背包2  https://www.lanqiao.cn/problems/1175/learning/


#include<bits/stdc++.h>
using namespace std;
const int N = 3011;
int w[N], c[N];    // 物品的价值和体积
int dp[N][N];
int solve(int n, int C){
    for (int i = 1; i <= n; i++) {
        for (int j = C; j >= 0; j--) {
            if(i==1)   dp[i][j] = 0;
            else       dp[i][j] = dp[i - 1][j];
            for (int k = 0; k * c[i] <= j; k++)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k * c[i]] + k * w[i]);
        }
	}
    return dp[n][C];
}
int main(){
    int n,C; cin >> n >> C;
    for(int i=1;i<=n;i++)    cin >> c[i] >> w[i];
    memset(dp,0,sizeof(dp));
    cout << solve(n, C) << endl;
return 0;
}
