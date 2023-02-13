/*
 * @Author: Outsider
 * @Date: 2023-02-07 16:55:23
 * @LastEditors: Outsider
 * @LastEditTime: 2023-02-07 16:55:44
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\Recursion\P1990.cc
 */
#include <iostream>

using namespace std;

int dp[1000005];
int main()
{
    int n;
    cin >> n;
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = (2 * dp[i - 1]) % 10000 + dp[i - 3];
        dp[i] %= 10000;
    }
    cout << dp[n] << endl;
}