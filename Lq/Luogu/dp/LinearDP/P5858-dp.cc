/*
 * @Author: Outsider
 * @Date: 2023-02-04 17:18:06
 * @LastEditors: Outsider
 * @LastEditTime: 2023-02-05 11:00:12
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\DP\LinearDP\P5858-dp.cc
 */
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int a[5005];
long long n, w, s;

long long maxx = LONG_LONG_MIN;

long long dp[5005][5005];
int main()
{
    cin >> n >> w >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            dp[i][j] = -1e15;
        }
    }
    dp[0][0] = 0;
    for (long long i = 1; i <= n; i++)
    {
        for (long long j = 1; j <= min(i, w); j++)
        {
            for (long long k = j - 1; k <= min(w, j - 1 + s); k++)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][k] + j * a[i]);
            }
        }
    }
    for (int i = 0; i <= w; i++)
    {
        maxx = max(dp[n][i], maxx);
    }
    cout << maxx << endl;
}