/*
 * @Author: Outsider
 * @Date: 2023-02-01 09:59:34
 * @LastEditors: Outsider
 * @LastEditTime: 2023-02-01 12:07:25
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\DP\LinearDP\P2758.cc
 */
#include <iostream>
#include <algorithm>
using namespace std;

int dp[2005][2005];

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i <= s1.size(); i++)
    {
        dp[i][0] = i;
    }
    for (int i = 0; i <= s2.size(); i++)
    {
        dp[0][i] = i;
    }
    for (int i = 0; i < s1.size(); i++)
    {
        for (int j = 0; j < s2.size(); j++)
        {
            if (s1[i] == s2[j])
            {
                dp[i + 1][j + 1] = dp[i][j];
            }
            else
            {
                dp[i + 1][j + 1] = min(min(dp[i][j + 1], dp[i + 1][j]), dp[i][j]) + 1;
            }
        }
    }
    cout << dp[s1.size()][s2.size()] << endl;
}