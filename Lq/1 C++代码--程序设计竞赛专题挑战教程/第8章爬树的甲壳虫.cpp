//爬树的甲壳虫  2022年第十三届省赛 C/C++大学A组、研究生组，Java研究生组，Python研究生组
//http://oj.ecustacm.cn/problem.php?id=2025
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100010, MOD = 998244353;
ll s[N];
ll fastPow(ll a, ll n, ll mod){
    ll ans = 1;
    a %= mod;
    while(n) {
        if(n & 1)  ans = (ans*a) % mod;
        a = (a*a) % mod;
        n >>= 1;
    }
    return ans;
}
ll mod_inverse(ll a,ll mod){   //费马小定理求逆
   return fastPow(a,mod - 2,mod);
}
int main(){
    int n;    cin >> n;
    for(int i = 1; i <= n; i++)    {
        int x, y;   cin >> x >> y;
        s[i] = (s[i - 1] + 1) * y % MOD * mod_inverse(y - x, MOD) % MOD;
    }
    cout << s[n];
    return 0;
}
