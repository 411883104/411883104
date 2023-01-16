/*
 * @Author: Outsider
 * @Date: 2023-01-15 12:49:51
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-15 14:33:10
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\Recursion\P1002-dp.cc
 */
#include <iostream>

using namespace std;
struct point
{
    int x, y;
};
int main()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    int dx[] = {2, 2, 1, 1, -2, -2, -1, -1};
    int dy[] = {1, -1, 2, -2, 1, -1, 2, -2};

    int cnt[25][25] = {0};

    point now = {x, y};
    point next;
    for (int i = 0; i < 8; i++)
    {
        next = {now.x + dx[i], now.y + dy[i]};
        if (next.x >= 0 && next.x <= n && next.y >= 0 && next.y <= m && cnt[next.x][next.y] == 0)
        {
            cnt[next.x][next.y] = 1;
        }
    }
    cnt[x][y] = 1;

    long long dp[25][25] = {1};
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i][0] == 1)
            dp[i][0] = 0;
        else
            dp[i][0] = dp[i - 1][0];
    }
    for (int i = 1; i <= m; i++)
    {
        if (cnt[0][i] == 1)
            dp[0][i] = 0;
        else
            dp[0][i] = dp[0][i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (cnt[i][j] == 1)
                dp[i][j] = 0;
            else
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        }
    }
    cout << dp[n][m] << endl;
}