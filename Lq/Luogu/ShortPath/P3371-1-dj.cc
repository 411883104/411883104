/*
 * @Author       : Outsider
 * @Date         : 2023-04-05 08:38:31
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-04-05 09:51:59
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\ShortPath\P3371-1-dj.cc
 */
#include <iostream>
#include <vector>
using namespace std;
const int c = 1e5 + 5;
vector<pair<int, int>> G[c];
int dist[c];
int vis[c];

int main()
{
    int n, m, s;
    cin >> n >> m >> s;
    int u, v, w;
    for (int i = 0; i < m; i++)
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
        dist[e.first] = min(dist[e.first], e.second);
    }

    dist[s] = 0;
    vis[s] = 1;

    for (;;)
    {
        int t = 0x7fffffff, r = s;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 0 && dist[i] < t)
            {
                r = i;
                t = dist[i];
            }
        }
        if (r == s)
        {
            break;
        }
        vis[r] = 1;
        for (auto e : G[r])
        {
            if (vis[e.first] == 0) dist[e.first] = min(dist[e.first], dist[r] + e.second);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
    return 0;
}