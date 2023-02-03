/*
 * @Author: Outsider
 * @Date: 2023-01-26 12:09:55
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-26 12:18:28
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\dp\B3637.cc
 */
#include <iostream>
#include <algorithm>

using namespace std;

int arr[50005];
int dp[50005];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int maxx = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
        maxx = max(maxx, dp[i]);
    }
    cout << maxx << endl;
}