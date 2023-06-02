/*
 * @Author       : Outsider
 * @Date         : 2023-04-01 10:40:35
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-04-01 10:41:13
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\Combinatorics\P2181.cc
 */

// todo https://www.luogu.com.cn/problem/P2181

#include <iostream>
using namespace std;

long long dp[100005];

int main()
{
    int n;
    cin >> n;
    dp[3] = 0;
    dp[4] = 0;
    dp[5] = 3;
    for (int i = 6; i <= n; i++)
    {
        dp[i] = dp[i - 1] + (i - 4) * i;
    }
    cout << dp[n] << endl;
    return 0;
}