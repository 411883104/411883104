/*
 * @Author: Outsider
 * @Date: 2023-01-31 18:50:37
 * @LastEditors: Outsider
 * @LastEditTime: 2023-02-01 09:44:38
 * @Description: In User Settings Edit
 * @FilePath: \Lq\other\P1776.cc
 */
#include <iostream>

using namespace std;

int dp[40005];
int item[2000][2];

int main()
{
    int n, m;
    cin >> n >> m;
    int x, y, z;
    int tol = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y >> z;

        for (int j = 1; j <= z; j <<= 1)
        {
            item[tol][0] = j * x;
            item[tol++][1] = j * y;
            z -= j;
        }
        if (z > 0)
        {
            item[tol][0] = z * x;
            item[tol++][1] = z * y;
        }
    }

    for (int i = 0; i < tol; i++)
    {
        for (int j = m; j >= item[i][1]; j--)
        {
            dp[j] = max(dp[j], dp[j - item[i][1]] + item[i][0]);
        }
    }
    cout << dp[m] << endl;
}