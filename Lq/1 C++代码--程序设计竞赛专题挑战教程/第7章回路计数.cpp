//回路计数 2021年第十二届省赛 https://www.lanqiao.cn/problems/1462/learning/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 22, M = 1<<22;
ll dp[M][N];
bool dist[N][N];
int main(){
    memset(dp,0,sizeof(dp));
	for (int i = 1; i <= 21; i ++)
		for (int j = 1; j <= 21; j ++)
			if(__gcd(i, j) == 1)
				dist[i][j] = true;
	dp[2][1] = 1;
	for (int S = 2; S <= M - 2; S ++)
		for (int j = 1; j < N; j ++)
			if((S >> j) & 1)
				for (int k = 1; k < N; k ++)
					if(S ^ (1 << j) >> k & 1 && dist[k][j])
						dp[S][j] += dp[S ^ (1 << j)][k];
	ll ans = 0;
	for (int i = 2; i <N; i ++) ans += dp[M - 2][i];
	cout << ans << endl;
	return 0;
}
