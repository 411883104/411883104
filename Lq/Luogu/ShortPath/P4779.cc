/*
 * @Author       : Outsider
 * @Date         : 2023-03-07 09:27:38
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-03-07 17:39:23
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\ShortPath\P4779.cc
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int c = 1000;
vector<pair<int, int>> G[c];
int dist[c];
bool vis[c];
struct Greater
{
    bool operator()(pair<int, int>& a, pair<int, int>& b) const
    {
        return a.first > b.first;
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, Greater> q;
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
        q.push(make_pair(e.second, e.first));
    }
    vis[s] = true;
    dist[s] = 0;

    while (!q.empty())
    {
        auto minn = q.top();
        if (!vis[minn.second])
        {
            vis[minn.second] = true;
            for (auto e : G[minn.second])
            {
                if (!vis[e.first])
                {
                    if (dist[minn.second] + e.second < dist[e.first])
                    {
                        dist[e.first] = dist[minn.second] + e.second;
                        q.push(make_pair(dist[e.first], e.first));
                    }
                }
            }
        }
        q.pop();
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
}