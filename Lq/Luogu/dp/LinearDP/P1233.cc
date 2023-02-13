/*
 * @Author: Outsider
 * @Date: 2023-02-03 20:21:41
 * @LastEditors: Outsider
 * @LastEditTime: 2023-02-04 09:25:58
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\DP\LinearDP\P1233.cc
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;
int dp[5005];
int main()
{
    int n;
    cin >> n;
    int x, y;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) -> bool
         { if (a.first == b.first)
            return a.second>b.second;
        return a.first>b.first; });

    int maxx = 0;
    for (int i = 0; i < v.size(); i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (v[i].second > v[j].second)
                dp[i] = max(dp[i], dp[j] + 1);
        }
        maxx = max(maxx, dp[i]);
    }
    cout << maxx << endl;
}