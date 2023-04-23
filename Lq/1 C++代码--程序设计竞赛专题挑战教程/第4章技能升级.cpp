//技能升级 2022年第十三届省赛C/C++大学C组，Java研究生组，Python大学B组、研究生组

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+4;
ll n, m;
ll a[N] = {0}, b[N] = {0};
// 最后一次加攻击能不能到x
ll check(ll x) {
    ll cnt = 0;
    for(int i=0; i<n; i++) {
        if (a[i] >= x) {
            cnt += (a[i] - x) / b[i] + 1;
            if (cnt >= m) {
                return 1;
            }
        }
    }
    return 0;
}
// 二分枚举最后一次攻击力最高能加多少
int getHighestLast() {
    int low = 0, high = 1e6;
    while(low < high) {
        int mid =  (low + high + 1) >> 1;
        if (check(mid)) { // 如果mid可以
            low = mid;
        } else {
            high = mid-1;
        }
    }
    return low;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    ll totalCnt = 0;
    for(int i=0; i<n; i++) {
        cin >> a[i] >> b[i];
        if (a[i] % b[i] == 0) {
            totalCnt += a[i] / b[i];
        } else {
            totalCnt += a[i] / b[i] + 1;
        }
    }
    m = min(m, totalCnt);
    int highestLast = getHighestLast();
    ll ans = 0;
    for (int i=0 ; i<n; i++) {
        if (a[i] >= highestLast) {
            int cnt = (a[i] - highestLast) / b[i] + 1;
            int last = a[i] - (cnt-1) * b[i];
            if (last == highestLast) {
                cnt--;
                last += b[i];
            }
            ans += (a[i] + last) * cnt >> 1;
            m -= cnt;
        }
    }
    cout << ans + m * highestLast;
    return 0;
}
