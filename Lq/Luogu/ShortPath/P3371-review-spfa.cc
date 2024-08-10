/*
 * @Author       : Outsider
 * @Date         : 2023-06-09 09:21:01
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-06-09 15:46:24
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\ShortPath\P3371-review-spfa.cc
 */
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;
const int c = 10005;

vector<pair<int, int>> G[c];

queue<int> q;

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

    q.push(s);
    vis[s] = 1;
    dist[s] = 0;

    while (!q.empty())
    {
        auto x = q.front();
        for (auto e : G[x])
        {
            if (dist[e.first] > dist[x] + e.second)
            {
                dist[e.first] = dist[x] + e.second;
                if (vis[e.first] == 0)
                {
                    q.push(e.first);
                }
            }
        }
        vis[x] = 0;
        q.pop();
    }

    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
    return 0;
}