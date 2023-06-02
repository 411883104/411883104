/*
 * @Author       : Outsider
 * @Date         : 2023-03-29 21:49:09
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-03-30 09:12:09
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\DP\Bag\P166.cc
 */
#include <iostream>
using namespace std;

long long dp[1000];

int main()
{
    int n;
    cin >> n;
    int tol = (1 + n) * n / 2;
    if (tol & 1)
    {
        cout << 0 << endl;
        return 0;
    }
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = tol / 2; j >= i; j--)
        {
            dp[j] += dp[j - i];
        }
    }

    cout << dp[tol / 2] / 2 << endl;
}