//高精度加法  https://www.lanqiao.cn/problems/1516/learning/

#include <bits/stdc++.h>
using namespace std;
string add(string a,string b){
    string s;   //存结果
    int c = 0;  //进位
    for(int i=a.size()-1,j=b.size()-1;i>=0||j>=0||c>0;i--,j--){
        if(i>=0)   c += a[i]-'0';
        if(j>=0)   c += b[j]-'0';
        s += (c%10)+'0';  //注意s这里，低位在前，高位在后
        c /= 10;
    }
    reverse(s.begin(),s.end()); //反过来，高位在前，低位在后
    return s;
}
int main(){
    string a,b;  cin>>a>>b;   //用字符串方式读入整数a，b
    cout<<add(a,b);
    return 0;
}
