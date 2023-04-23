//找素数 https://www.lanqiao.cn/problems/1558/learning/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1000005;
bool seg_prime[N];
bool vis[N];
ll prime[N]; //存[a,b]内的素数
ll seg_sieve(ll a,ll b) {
    for(ll i=0;i<=sqrt(b);++i) vis[i]=true;
    for(ll i=0;i<=b-a;++i) seg_prime[i]=true;
    for(ll i=2;i<=sqrt(b);++i)
        if(vis[i]) {                  //i是素数
            for(ll j=i*i;j<=sqrt(b);j+=i)//筛选[2,sqrt(b)]内的素数
                vis[j] = false;
             for(ll j=max(2LL,(a+i-1)/i)*i;j<=b;j+=i)//筛选[a,b]内的素数
                seg_prime[j-a] = false;
        }
    ll num=0;
    for(ll i=0;i<=b-a;++i)  //统计[a,b]内素数个数
        if(seg_prime[i])  prime[num++]=i+a; //存[a,b]内的素数
    return num;
}
int main(){
    ll a,b; cin >>a>>b;
    cout <<seg_sieve(a,b);
    return 0;
}
