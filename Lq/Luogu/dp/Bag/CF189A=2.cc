/*
 * @Author       : Outsider
 * @Date         : 2023-06-08 17:11:53
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-06-08 19:49:00
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\DP\Bag\CF189A=2.cc
 */
#include <iostream>
using namespace std;
const int N = 4005;
int dp[N];

int main()
{
    int n, a, b, c;
    int len[3];
    cin >> n >> len[0] >> len[1] >> len[2];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = -1;
    }
    dp[0] = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = len[i]; j <= n; j++)
        {
            if (dp[j - len[i]] >= 0) dp[j] = max(dp[j], dp[j - len[i]] + 1);
        }
    }
    cout << dp[n] << endl;
    return 0;
}