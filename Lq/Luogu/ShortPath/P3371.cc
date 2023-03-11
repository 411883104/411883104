/*
 * @Author       : Outsider
 * @Date         : 2023-03-07 09:27:38
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-03-07 10:56:56
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\ShortPath\P3371.cc
 */
#include <iostream>
#include <vector>

using namespace std;
const int c = 1000;
vector<pair<int, int>> G[c];
int dist[c];
bool vis[c];
int main()
{
    int n, m, s;
    cin >> n >> m >> s;
    int u, v, w;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        G[u].push_back(make_pair(v, w));
    }
    for (int i = 1; i <= n; i++)
    {
        dist[i] = 0x7fffffff;
    }
    for (auto e : G[s])
    {
        dist[e.first] = min(e.second, dist[e.first]); // 重边
    }
    vis[s] = true;
    dist[s] = 0;

    for (;;)
    {
        int tt = 0x7fffffff, nn = s;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && dist[j] < tt)
            {
                tt = dist[j];
                nn = j;
            }
        }
        if (nn == s)
        {
            break;
        }
        vis[nn] = true;
        for (auto e : G[nn])
        {
            if (!vis[e.first])
            {
                if (dist[nn] + e.second < dist[e.first])
                {
                    dist[e.first] = dist[nn] + e.second;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
}