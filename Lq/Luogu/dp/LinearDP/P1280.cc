/*
 * @Author: Outsider
 * @Date: 2023-01-27 17:10:06
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-27 18:09:59
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\DP\LinearDP\P1280.cc
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int c = 10005;
vector<pair<int, int>> v[c];
int dp[c];
int main()
{
    int n, k;
    cin >> n >> k;

    int x, y;
    for (int i = 0; i < k; i++)
    {
        cin >> x >> y;
        v[x].push_back(make_pair(x, y));
    }

    for (int i = n; i > 0; i--)
    {
        if (v[i].size() > 0)
        {
            for (int j = 0; j < v[i].size(); j++)
            {
                dp[i] = max(dp[i], dp[i + v[i][j].second]);
            }
        }
        else
        {
            dp[i] = dp[i + 1] + 1;
        }
    }
    cout << dp[1] << endl;
}