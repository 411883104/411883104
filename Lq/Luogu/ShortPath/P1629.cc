/*
 * @Author       : Outsider
 * @Date         : 2023-03-09 08:49:19
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-03-09 09:31:53
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\ShortPath\P1629.cc
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int c = 1000;
int dist[c][c];
int main()
{
    int n, m;
    cin >> n >> m;
    int u, v, w;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dist[i][j] = 0xfffffff;
            if (i == j)
            {
                dist[i][j] = 0;
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        dist[u][v] = min(w, dist[u][v]);
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += dist[1][i] + dist[i][1];
    }
    cout << ans << endl;
}