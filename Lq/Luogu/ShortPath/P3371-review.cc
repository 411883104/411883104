/*
 * @Author       : Outsider
 * @Date         : 2023-06-09 09:21:01
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-06-09 10:09:13
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\ShortPath\P3371-review.cc
 */
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
const int c = 10005;

vector<pair<int, int>> G[c];

struct Edge
{
    int u, v, w;
};

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
    }
    vis[s] = 1;
    dist[s] = 0;

    for (;;)
    {
        int v = s, minn = INT_MAX;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 0 && minn > dist[i])
            {
                minn = dist[i];
                v = i;
            }
        }
        if (v == s)
        {
            break;
        }
        vis[v] = 1;

        for (auto x : G[v])
        {
            if (vis[x.first] == 0 && dist[x.first] > dist[v] + x.second)
            {
                dist[x.first] = dist[v] + x.second;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
    return 0;
}