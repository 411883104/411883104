//小明的衣服  https://www.lanqiao.cn/problems/1228/learning/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n; cin>>n;
    priority_queue< ll,vector<ll>,greater<ll> > q;
    for(ll i=0;i<n;i++){
        ll a; cin>>a;
        q.push(a);
    }
    ll sum=0;
    while(q.size()>1){
        ll x = q.top(); q.pop();
        ll y = q.top(); q.pop();
        ll z = x+y;
        sum += z;
        q.push(z);
        cout <<z<<"  ";
    }
    cout<<sum<<endl;
}
