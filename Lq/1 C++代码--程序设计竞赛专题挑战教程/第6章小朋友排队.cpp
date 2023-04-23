//小朋友排队 https://www.lanqiao.cn/problems/222/learning/

#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
typedef long long LL;
int h[N], tree[N], k[N];        //h是身高，k是交换次数（逆序对数量）
int lowbit(int x) {  return x & -x; }
void update(int x, int d) {
    while(x <= N) {
        tree[x] += d;
        x += lowbit(x);
    }
}
int sum(int x) {
    int ans = 0;
    while(x > 0){
        ans += tree[x];
        x -= lowbit(x);
    }
    return ans;
}
int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i ++ ){
        cin >> h[i];
        h[i]++;          //h从1开始，不是从0开始
    }
    for (int i = 1; i <= n; i ++ ) {   //正序处理 逆序对，右边矮的
        k[i] = sum(N - 1) - sum(h[i]);
        update(h[i], 1);
    }
    memset(tree, 0, sizeof tree);
    for (int i = n; i; i-- ){         //倒序处理  逆序对，左边高的
        k[i] += sum(h[i] - 1);
        update(h[i], 1);
    }
    LL res = 0;
    for (int i = 1; i <= n; i ++ )    //最后把所有人的不愉快加起来
        res += (LL)k[i] * (k[i] + 1 ) / 2;
    cout << res;
    return 0;
}
