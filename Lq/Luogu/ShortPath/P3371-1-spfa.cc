/*
 * @Author       : Outsider
 * @Date         : 2023-03-07 09:27:38
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-04-05 15:18:39
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\ShortPath\P3371-1-spfa.cc
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
    dist[s] = 0;
    q.push(s);
    vis[s] = true;

    while (!q.empty())
    {
        auto x = q.front();
        for (auto e : G[x])
        {
            if (dist[e.first] > dist[x] + e.second)
            {
                dist[e.first] = dist[x] + e.second;
                if (vis[e.first] == false)
                {
                    q.push(e.first);
                }
            }
        }
        vis[x] = false;
        q.pop();
    }

    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
}