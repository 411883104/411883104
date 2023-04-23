//快速幂
//https://www.lanqiao.cn/problems/1514/learning/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;                      //变量改用较大的long long
ll fastPow(ll a, ll n, ll mod){
    ll ans = 1;
    a %= mod;                             //重要，防止下面的ans*a越界
    while(n) {
        if(n & 1)   ans = (ans*a) % mod;   //取模
        a = a*a % mod;                     //取模
        n >>= 1;
    }
    return ans;
}
int main(){
    ll b,p,k;    cin>>b>>p>>k;
    cout << fastPow(b,p,k);
    return 0;
}
