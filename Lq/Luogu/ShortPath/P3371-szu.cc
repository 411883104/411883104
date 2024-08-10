/*
 * @Author       : Outsider
 * @Date         : 2023-07-10 16:38:08
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-07-10 16:57:10
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\ShortPath\P3371-szu.cc
 */
#include <iostream>
#include <vector>
using namespace std;

const int c = 10005;
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
        G[u].push_back({v, w});
    }
    for (int i = 1; i <= n; i++)
    {
        dist[i] = 0x7fffffff;
    }
    for (auto &x : G[s])
    {
        dist[x.first] = min(dist[x.first], x.second);
    }
    vis[s] = 1;
    dist[s] = 0;

    for (;;)
    {
        int minn = 0x7fffffff, t = s;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 0 && minn > dist[i])
            {
                minn = dist[i];
                t = i;
            }
        }
        if (t == s)
        {
            break;
        }
        vis[t] = 1;
        for (auto &x : G[t])
        {
            if (vis[x.first] == 0 && dist[x.first] > dist[t] + x.second)
            {
                dist[x.first] = dist[t] + x.second;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
}