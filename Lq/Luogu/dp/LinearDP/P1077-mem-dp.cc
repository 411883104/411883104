/*
 * @Author: Outsider
 * @Date: 2023-02-01 17:26:28
 * @LastEditors: Outsider
 * @LastEditTime: 2023-02-03 12:15:56
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\DP\LinearDP\P1077-mem-dp.cc
 */
// #include <iostream>
// #include <vector>
// using namespace std;
// int ans = 0;
// int n, m;
// int arr[105];
// int dp[105][105];
// const int p = 1e6 + 7;

// int main()
// {
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> arr[i];
//     }
//     dp[0][0] = 1;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 0; j <= m; j++)
//         {
//             for (int k = 0; k <= arr[i] && j >= k; k++)
//             {
//                 dp[i][j] += dp[i - 1][j - k];
//                 dp[i][j] %= p;
//             }
//         }
//     }
//     cout << dp[n][m] << endl;
// }
#include <iostream>
#include <vector>
using namespace std;
int ans = 0;
int n, m;
int arr[105];
int dp[2][105];
const int p = 1e6 + 7;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            dp[i & 1][j] = 0;
            for (int k = 0; k <= arr[i] && j >= k; k++)
            {
                dp[i & 1][j] += dp[(i - 1) & 1][j - k];
                dp[i & 1][j] %= p;
            }
        }
    }
    cout << dp[n & 1][m] << endl;
}