/*
 * @Author       : Outsider
 * @Date         : 2023-03-25 16:42:42
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-03-25 16:43:31
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\DP\Bag\P1507.cc
 */
#include <iostream>
using namespace std;
const int c = 505;
int dp[c][c];
int main()
{
    int h, t;
    cin >> h >> t;
    int n;
    cin >> n;
    int x, y, z;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y >> z;
        for (int j = h; j >= x; j--)
        {
            for (int k = t; k >= y; k--)
            {
                dp[j][k] = max(dp[j][k], dp[j - x][k - y] + z);
            }
        }
    }
    cout << dp[h][t] << endl;
}