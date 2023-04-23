/*
 * @Author       : Outsider
 * @Date         : 2023-03-25 20:10:16
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-03-25 20:12:52
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\DP\Bag\CF189A.cc
 */
#include <iostream>
const int c = 4005;
using namespace std;
int dp[c];
int v[5];
int main()
{
    int n;
    cin >> n >> v[1] >> v[2] >> v[3];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = -1;
    }
    dp[0] = 0;
    for (int i = 1; i <= 3; i++)
    {
        for (int j = v[i]; j <= n; j++)
        {
            if (dp[j - v[i]] >= 0) dp[j] = max(dp[j], dp[j - v[i]] + 1);
        }
    }
    cout << dp[n] << endl;
}