/*
 * @Author       : Outsider
 * @Date         : 2023-03-07 09:27:38
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-03-08 16:47:12
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\ShortPath\P3371-spfa.cc
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int c = 1000;
vector<pair<int, int>> G[c];
int dist[c];
bool vis[c];
queue<int> q;
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
    q.push(s);
    vis[s] = true;
    dist[s] = 0;

    while (!q.empty())
    {
        auto nn = q.front();
        for (auto e : G[nn])
        {
            if (dist[nn] + e.second < dist[e.first])
            {
                dist[e.first] = dist[nn] + e.second;
                if (!vis[e.first])
                {
                    q.push(e.first);
                }
            }
        }
        q.pop();
        vis[nn] = false;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
}