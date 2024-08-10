/*
 * @Author       : Outsider
 * @Date         : 2023-04-23 19:23:09
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-04-23 19:59:49
 * @Description  : In User Settings Edit
 * @FilePath     : \Luogu\Hw\P1115-dp.cc
 */
#include <iostream>
#include <climits>
using namespace std;

int a[200005];
int dp[200005];

int main()
{
    int n;
    cin >> n;
    int maxx = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    maxx = a[1];
    dp[1] = a[1];
    for (int i = 2; i <= n; i++)
    {
        if (dp[i - 1] > 0)
        {
            dp[i] = dp[i - 1] + a[i];
        }
        else
        {
            dp[i] = a[i];
        }
        maxx = max(dp[i], maxx);
    }
    cout << maxx << endl;
    return 0;
}