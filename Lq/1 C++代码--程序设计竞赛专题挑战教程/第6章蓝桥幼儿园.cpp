//蓝桥幼儿园  https://www.lanqiao.cn/problems/1135/learning/

#include <bits/stdc++.h>
using namespace std;
const int N = 8e5+5;
int s[N];
void init_set(){                 //初始化
   for(int i=1; i<=N; i++)  s[i] = i;
}
int find_set(int x){
    if(x != s[x])   s[x] = find_set(s[x]);   //路径压缩
    return s[x];
}

void merge_set(int x, int y){    //合并
    x = find_set(x);
    y = find_set(y);
    if(x != y) s[x] = s[y];      //y成为x的父亲，x的集是y
}
int main (){
    init_set();
    int n,m; cin>>n>>m;
    while(m--){
        int op,x,y; cin>>op>>x>>y;
        if(op == 1)   merge_set(x, y);
        if(op == 2){
            if(find_set(x)==find_set(y)) cout << "YES"<<endl;
            else                         cout << "NO"<<endl;
        }
    }
    return 0;
}
