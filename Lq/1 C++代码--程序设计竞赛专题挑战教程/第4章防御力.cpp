//防御力 2018年第九届蓝桥杯国赛  https://www.lanqiao.cn/problems/226/learning

#include <bits/stdc++.h>
using namespace std;
struct nodea{int id,w;} a[100005];      // A的道具//id是道具，w是这个道具的增加量
struct nodeb{int id,w;} b[100005];      // B的道具
bool cmp1(nodea a,nodea b){
    if(a.w != b.w) return a.w < b.w;    //先对A的增加量排序，从小到大
    else return a.id < b.id;            //再按字典序id排序
}
bool cmp2(nodeb a,nodeb b){             //先对B的增加量排序，从大到小
    if(a.w != b.w) return a.w > b.w;
    else return a.id < b.id;
}
int main(){
    int n1,n2;   cin >> n1 >> n2;
    for(int i = 1; i <= n1; i++)  cin >> a[i].w,  a[i].id = i;
    for(int i = 1; i <= n2; i++)  cin >> b[i].w,  b[i].id = i;
    sort(a+1,a+n1+1,cmp1);
    sort(b+1,b+n2+1,cmp2);
    string s;    cin >> s;
    int idx1 = 1, idx2 = 1;
    for(int i=0;i<s.length();i++){
        if(s[i]=='1'){cout << "B"; cout << b[idx1++].id << "\n";}
        else         {cout << "A"; cout << a[idx2++].id << "\n";}
    }
    cout << "E" << "\n";
    return 0;
}
