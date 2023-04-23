//火星人 https://www.lanqiao.cn/problems/572/learning

#include <bits/stdc++.h>
using namespace std;
int a[100000];
int main(){
    int n,m;   cin >> n >> m;
    for(int i=1;i<=n;++i)   cin >> a[i];
    for(int i=1;i<=m;++i)   next_permutation(a+1,a+n+1);
    for(int i=1;i<=n;++i)   cout <<a[i]<<" ";
    return 0;
}
