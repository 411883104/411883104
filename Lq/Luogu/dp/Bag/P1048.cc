/*
 * @Author       : Outsider
 * @Date         : 2023-06-06 17:16:36
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-06-06 17:34:36
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\DP\Bag\P1048.cc
 */
#include <iostream>
using namespace std;
const int c = 1005;
int dp[c];
int main()
{
    int t, m;
    cin >> t >> m;

    int x, y;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        for (int j = t; j >= x; j--)
        {
            dp[j] = max(dp[j], dp[j - x] + y);
        }
    }
    cout << dp[t] << endl;
}