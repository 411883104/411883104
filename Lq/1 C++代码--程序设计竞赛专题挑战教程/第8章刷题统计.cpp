//刷题统计  2022年第十三届蓝桥杯省赛 C/C++大学B组
//httpoj.ecustacm.cnproblem.phpid=2033


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll a,b,n; cin>>a>>b>>n;
    ll week = a*5+b*2;     //每周做题
    ll days = (n/week)*7;  //天数
    n %= week;             //余数
    if(n<=a*5) days += n/a+(n%a?1:0);  //在周一到周五内
    else{                  //周六和周日
        days += 5, n -= a*5;
        days += n/b+(n%b?1:0);
    }
    cout<<days;
    return 0;
}
