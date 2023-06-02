/*
 * @Author       : Outsider
 * @Date         : 2023-04-05 08:38:31
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-04-05 13:31:01
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\ShortPath\P3371-1-floyd.cc
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int c = 1e4 + 5;
int dist[c][c];

int main()
{
    int n, m, s;
    cin >> n >> m >> s;
    int u, v, w;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dist[i][j] = 0x7fffffff;
        }
        dist[i][i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][k] != 0x7fffffff && dist[k][j] != 0x7fffffff)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << dist[s][i] << " ";
    }
    cout << endl;
    return 0;
}