/*
 * @Author       : Outsider
 * @Date         : 2023-06-09 09:21:01
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-06-09 10:25:29
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\ShortPath\P3371-review-di-heap.cc
 */
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;
const int c = 10005;

vector<pair<int, int>> G[c];

struct Edge
{
    int u, v, w;
};

class Greater
{
public:
    bool operator()(pair<int, int> lhs, pair<int, int> rhs)
    {
        return lhs.second > rhs.second;
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, Greater> q;

int dist[c];
int vis[c];

int main()
{
    int n, m, s;
    cin >> n >> m >> s;
    int x, y, w;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> w;
        G[x].emplace_back(y, w);
    }
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INT_MAX;
    }
    for (auto x : G[s])
    {
        dist[x.first] = min(dist[x.first], x.second);
        q.push(x);
    }
    vis[s] = 1;
    dist[s] = 0;

    while (!q.empty())
    {
        auto x = q.top();
        if (vis[x.first] == 0)
        {
            vis[x.first] = 1;
            for (auto n : G[x.first])
            {
                if (vis[n.first] == 0 && dist[n.first] > dist[x.first] + n.second)
                {
                    dist[n.first] = dist[x.first] + n.second;
                    q.emplace(n.first, dist[n.first]);
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