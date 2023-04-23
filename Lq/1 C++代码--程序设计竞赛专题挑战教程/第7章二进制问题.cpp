//二进制问题 2021年第十二届决赛   https://www.dotcpp.com/oj/problem2619.html
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 60;
ll r, K;
ll dp[N][N];
void init(){         //计算组合数dp[][]
    for (int i = 0; i < N; i++ )
        for (int j = 0; j <= i; j++ )
            if (j==0) dp[i][j] = 1;
            else dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
}
int nums[21];   //把n转成二进制，按位存到nums里。
ll solve(ll n){
    int len = 1;
    while(n){  nums[len]=n%2;  n/=2; len++; }
    len--;      //nums[1]是最低位，nums[len]是最高位
    ll ans = 0;
    int last = 0;                 //已经用了几个1
    for (int i=len; i>=1; i-- ) { //从高位到低位
        if (nums[i]==1){               //如果这一位是1
            ans += dp[i-1][K - last];  //当第i位选0时
            last ++ ;
            if (last > K) break; //如果1的数量大于规定的数量时,结束
        }
        if (i==1 && last == K) ans++;//最后一位,如果1的数量恰好等于规定数量时,即最后一位符合要求*/
    }
    return ans;
}
int main(){
    cin >> r >> K;
    init();
    cout << solve(r);
    return 0;
}
