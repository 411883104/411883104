/*
 * @Author: Outsider
 * @Date: 2023-01-20 13:33:22
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-20 14:09:16
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\dp\P1802.cc
 */
#include <iostream>

using namespace std;

long long dp[1055];

int main()
{
    int n, x;
    cin >> n >> x;

    long long lose, win, use;
    for (int i = 1; i <= n; i++)
    {
        cin >> lose >> win >> use;
        for (int j = x; j >= 0; j--)
        {
            if (j >= use)
                dp[j] = max(dp[j] + lose, dp[j - use] + win);
            else
                dp[j] = dp[j] + lose;
        }
    }
    cout << 5 * dp[x] << endl;
}