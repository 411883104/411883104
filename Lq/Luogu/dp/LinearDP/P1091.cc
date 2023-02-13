/*
 * @Author: Outsider
 * @Date: 2023-02-04 09:50:13
 * @LastEditors: Outsider
 * @LastEditTime: 2023-02-04 11:29:12
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\DP\LinearDP\P1091.cc
 */
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
int arr[105];
int dp[105];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int maxx = 0;
    for (int i = 0; i < n; i++)
    {
        memset(dp, 0, 105 * 4);
        dp[i] = 1;
        int ans = 0;
        for (int j = i; j >= 0; j--)
        {
            for (int k = i; k > j; k--)
            {
                if (arr[k] > arr[j] && dp[k] != 0)
                {
                    dp[j] = max(dp[j], dp[k] + 1);
                }
                ans = max(ans, dp[j]);
            }
        }
        memset(dp, 0, 105 * 4);
        dp[i] = 1;
        int res = 0;
        for (int j = i; j < n; j++)
        {
            for (int k = i; k < j; k++)
            {
                if (arr[k] > arr[j] && dp[k] != 0)
                {
                    dp[j] = max(dp[j], dp[k] + 1);
                }
                res = max(res, dp[j]);
            }
        }
        if (res == 0 || ans == 0)
            maxx = max(res + ans, maxx);
        else
            maxx = max(res + ans - 1, maxx);
    }
    cout << n - maxx << endl;
}