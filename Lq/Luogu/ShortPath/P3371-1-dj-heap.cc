/*
 * @Author       : Outsider
 * @Date         : 2023-04-05 08:38:31
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-04-05 11:38:38
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\ShortPath\P3371-1-dj-heap.cc
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int c = 1e5 + 5;
vector<pair<int, int>> G[c];
int dist[c];
int vis[c];

class Greater
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b) const
    {
        return a.second > b.second;
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, Greater> q;
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
        q.push(make_pair(e.first, dist[e.first]));
    }

    dist[s] = 0;
    vis[s] = 1;
    while (!q.empty())
    {
        auto r = q.top();
        if (vis[r.first] == 0)
        {
            vis[r.first] = 1;
            for (auto e : G[r.first])
            {
                if (vis[e.first] == 0 && dist[e.first] > dist[r.first] + e.second)
                {
                    dist[e.first] = dist[r.first] + e.second;
                    q.push(make_pair(e.first, dist[e.first]));
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
    return 0;
}