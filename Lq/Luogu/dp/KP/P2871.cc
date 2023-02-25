/*
 * @Author       : Outsider
 * @Date         : 2023-02-25 11:11:31
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-02-25 11:32:55
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\DP\KP\P2871.cc
 */
#include <iostream>

using namespace std;
int dp[13005];
int main()
{
    int n, m;
    cin >> n >> m;
    int w, v;
    for (int i = 1; i <= n; i++)
    {
        cin >> v >> w;
        for (int j = m; j >= v; j--)
        {
            dp[j] = max(dp[j], dp[j - v] + w);
        }
    }
    cout << dp[m] << endl;
}