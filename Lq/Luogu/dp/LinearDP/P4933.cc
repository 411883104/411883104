/*
 * @Author: Outsider
 * @Date: 2023-02-05 11:22:09
 * @LastEditors: Outsider
 * @LastEditTime: 2023-02-05 12:14:31
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\DP\LinearDP\P4933.cc
 */
#include <iostream>
using namespace std;
int a[1005];
int dp[1005][50005];
int p = 998244353;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int off = 20005;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans++;
        for (int j = 0; j < i; j++)
        {
            dp[i][a[i] - a[j] + off] += dp[j][a[i] - a[j] + off] + 1;
            dp[i][a[i] - a[j] + off] %= p;
            ans += dp[j][a[i] - a[j] + off] + 1;
            ans %= p;
        }
    }
    cout << ans << endl;
}