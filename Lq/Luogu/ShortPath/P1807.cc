/*
 * @Author       : Outsider
 * @Date         : 2023-03-08 16:24:42
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-03-08 17:48:01
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\ShortPath\P1807.cc
 */
#include <iostream>

using namespace std;
const int c = 1505;

int dis[c][c];
int main()
{
    int n, m;
    int u, v, s;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dis[i][j] = -0xffffff;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> s;
        dis[u][v] = max(s, dis[u][v]);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                dis[i][j] = 0;
            }
        }
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dis[i][k] != -0xffffff && dis[k][j] != -0xffffff)
                    dis[i][j] = max(dis[i][k] + dis[k][j], dis[i][j]);
            }
        }
    }
    cout << (dis[1][n] == -0xffffff ? -1 : dis[1][n]) << endl;
}