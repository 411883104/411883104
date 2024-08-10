/*
 * @Author       : Outsider
 * @Date         : 2023-06-06 21:38:55
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-06-07 11:22:08
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\DP\Bag\P1832.cc
 */
#include <iostream>

using namespace std;
const int c = 1005;
int prime[c];
int vis[c];

long long dp[c];

int main()
{
    int n;
    cin >> n;
    int tol = 0;
    for (int i = 2; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            prime[tol++] = i;
        }
        for (int j = 0; j < tol && prime[j] * i <= n; j++)
        {
            vis[prime[j] * i] = 1;
            if (i % prime[j] == 0)
            {
                break;
            }
        }
    }
    dp[0] = 1;
    for (int i = 0; i < tol && prime[i] <= n; i++)
    {
        for (int j = prime[i]; j <= n; j++)
        {
            dp[j] += dp[j - prime[i]];
        }
    }
    cout << dp[n] << endl;
    return 0;
}

