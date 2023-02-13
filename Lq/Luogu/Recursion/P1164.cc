/*
 * @Author: Outsider
 * @Date: 2023-02-06 13:29:56
 * @LastEditors: Outsider
 * @LastEditTime: 2023-02-07 12:25:50
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\Recursion\P1164.cc
 */
#include <iostream>

using namespace std;
int m, n;
int a[105];
int b[105];
int ans = 0;
void dfs(int s, int tol)
{
    if (tol == m)
    {
        ans++;
        return;
    }
    if (tol > m || s > n || tol + b[s] < m)
    {
        return;
    }
    dfs(s + 1, tol + a[s]);
    dfs(s + 1, tol);
}
int mem[105][10005];
int dfs_m(int s, int tol)
{
    if (mem[s][tol] != 0)
    {
        return mem[s][tol];
    }
    if (tol == m)
    {
        return mem[s][tol] = 1;
    }
    if (tol > m || s > n || tol + b[s] < m)
    {
        return 0;
    }
    mem[s][tol] += dfs_m(s + 1, tol + a[s]);
    mem[s][tol] += dfs_m(s + 1, tol);
    return mem[s][tol];
}
int dp[10005];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= a[i]; j--)
        {
            dp[j] += dp[j - a[i]];
        }
    }
    cout << dp[m] << endl;
    // for (int i = n; i > 0; i--)
    // {
    //     b[i] = a[i] + b[i + 1];
    // }
    // dfs(1, 0);
    // cout << ans << endl;
    // cout << dfs_m(1, 0) << endl;
}