/*
 * @Author       : Outsider
 * @Date         : 2023-06-09 09:21:01
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-06-09 10:36:50
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\ShortPath\P3371-review-fl.cc
 */
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;
const int c = 10005;

int dist[c][c];
int vis[c];

int main()
{
    int n, m, s;
    cin >> n >> m >> s;
    int x, y, w;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dist[i][j] = INT_MAX;
            if (i == j)
            {
                dist[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> w;
        dist[x][y] = min(w, dist[x][y]);
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                    dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
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