/*
 * @Author       : Outsider
 * @Date         : 2023-02-25 12:26:46
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-02-25 13:40:03
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\DP\KP\P1049.cc
 */
#include <iostream>

using namespace std;
int dp[20005];

int main()
{
    int V, N;
    cin >> V >> N;
    int v;
    for (int i = 1; i <= N; i++)
    {
        cin >> v;
        for (int j =V; j >=v; j--)
        {
            dp[j] = max(dp[j], dp[j - v] + v);
        }
    }
    cout << V - dp[V] << endl;
}