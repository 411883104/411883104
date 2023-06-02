/*
 * @Author       : Outsider
 * @Date         : 2023-03-28 15:48:51
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-03-28 16:11:08
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\DP\Basic\P1359.cc
 */
#include <iostream>
#include <vector>
using namespace std;

int dp[1000005];
int main()
{
    int n;
    cin >> n;
    int x;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 0xfffffff;
    }
    int idx = 1;
    dp[1] = 0;
    while (idx < n)
    {
        for (int i = idx + 1; i <= n; i++)
        {
            cin >> x;
            dp[i] = min(dp[idx] + x, dp[i]);
        }
        idx++;
    }
    cout << dp[n] << endl;
    return 0;
}