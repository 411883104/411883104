// 四平方和  2016年第七届省赛  www.lanqiao.cn/problems/122/learning
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    for(int a=0;a<=sqrt(n);a++)                //限制a的范围
        for(int b=a;a*a+b*b<=n;b++)            //限制b的范围
            for(int c=b;a*a+b*b+c*c<=n;c++){   //限制c的范围
                int t = n-a*a-b*b-c*c;
                int d = sqrt(t);               //计算出d
                if(d*d==t && d>=c){
                   cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
                   return 0;
                }
            }
    return 0;
}
