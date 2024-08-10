/*
 * @Author       : Outsider
 * @Date         : 2023-06-09 19:15:39
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-06-09 19:47:10
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\MST\P3366-review-prim.cc
 */
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int c = 10005;

vector<pair<int, int>> G[c];

int dist[c];
int vis[c];

int main()
{
    int n, m;
    cin >> n >> m;
    int x, y, w;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> w;
        G[x].emplace_back(y, w);
        G[y].emplace_back(x, w);
    }
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INT_MAX;
    }
    for (auto x : G[1])
    {
        dist[x.first] = min(dist[x.first], x.second);
    }
    vis[1] = 1;
    dist[1] = 0;

    int ans = 0;
    int tol = 0;
    for (;;)
    {
        int minn = INT_MAX, s = 1;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 0 && minn > dist[i])
            {
                s = i;
                minn = dist[i];
            }
        }
        if (s == 1)
        {
            break;
        }
        vis[s] = 1;
        ans += minn;

        tol++;
        if (tol == n - 1)
        {
            break;
        }

        for (auto e : G[s])
        {
            if (vis[e.first] == 0)
            {
                dist[e.first] = min(dist[e.first], e.second);
            }
        }
    }
    if (tol == n - 1)
    {
        cout << ans << endl;
    }
    else
    {
        cout << "orz" << endl;
    }
    return 0;
}