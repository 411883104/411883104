//最大比例 2016年第七届省赛   https://www.lanqiao.cn/problems/120/learning/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 105;
ll x[N],a[N],b[N];
ll gcd_sub(ll a,ll b){
    if(a<b)   swap(a,b);
    if(b==1)  return a;
    return gcd_sub(b,a/b);
}
int main(){
    int n; cin >>n;
    ll cnt=0;
    for(int i=0;i<n;i++)  cin>>x[i];
    sort(x,x+n);         //排序
    for(int i=1;i<n;i++){
        ll d = __gcd(x[i],x[0]);
        a[cnt] = x[i]/d;
        b[cnt] = x[0]/d;   //约分,得分子a / 分母b
        cnt++;
    }
    ll up = a[0], down = b[0];
    for(int i=1;i<cnt;i++){
        up= gcd_sub(up,a[i]);        //求分子
        down = gcd_sub(down,b[i]);   //求分母
    }
    cout<<up<<'/'<<down<<endl;
    return 0;
}
