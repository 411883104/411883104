//平方和  2019年第十届蓝桥杯省赛C/C++大学A组
//https://www.lanqiao.cn/problems/599/learning

#include<bits/stdc++.h>
using namespace std;
bool check(int n){
    while(n){
        if(n%10==1||n%10==2||n%10==9||n%10==0)
            return true;
        n/=10;
    }
    return false;
}
int main(){
    long long sum=0;
    for(int i=1;i<=2019;i++)
        if(check(i))
            sum+=i*i;
    cout<<sum;
}
