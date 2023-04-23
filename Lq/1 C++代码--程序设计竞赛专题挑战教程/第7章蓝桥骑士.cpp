//蓝桥骑士  https://www.lanqiao.cn/problems/1188/learning/
#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int dp[N] , a[N];
signed main(){
    int n ;    cin >> n;
    for(int i = 1 ; i <= n ; i ++) cin >> a[i];
    dp[1] = a[1];
    int len = 1;
    for(int i = 2 ; i <= n ; i ++)    {
        if(dp[len] < a[i]) dp[++ len] = a[i];
        else  {
            int pos = upper_bound(dp + 1 , dp + 1 + len , a[i]) - dp;
            dp[pos] = a[i];
        }
    }
    cout << len << '\n';
    return 0;
}
