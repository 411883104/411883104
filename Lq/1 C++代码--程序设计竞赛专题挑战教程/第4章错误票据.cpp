//错误票据 https://www.lanqiao.cn/problems/205/learning

#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
int a[N];
int main(){
    int n; cin >> n;
    int cnt = 0;
    while(scanf("%d", &a[cnt]) != EOF)   cnt++;  //注意读数据的写法
    sort(a, a+cnt);
    int ans1, ans2;
    for(int i = 1; i < cnt; i++) {
        if(a[i] - a[i-1] > 1)   ans1 = a[i-1]+1;
        if(a[i] == a[i-1])      ans2 = a[i];
    }
    cout << ans1 << ' ' << ans2;
    return 0;
}
