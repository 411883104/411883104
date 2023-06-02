/*
 * @Author       : Outsider
 * @Date         : 2023-04-01 09:56:31
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-04-01 10:24:43
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\Combinatorics\P1806.cc
 */
#include <iostream>

using namespace std;
long long dp[505];
int n;
int main()
{
    cin >> n;
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = n; j >= i; j--)
        {
            dp[j] += dp[j - i];
        }
    }
    cout << dp[n] << endl;
    return 0;
}