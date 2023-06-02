/*
 * @Author       : Outsider
 * @Date         : 2023-04-05 22:30:44
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-04-05 23:37:38
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\MST\P3366-prim.cc
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int c = 5005;
int lower[c];
int vis[c];

vector<pair<int, int>> G[c];// 存图

int main()
{
    int n, m;
    cin >> n >> m;
    int u, v, w;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
    }

    int k = 0;
    int cost = 0;
    for (int i = 1; i <= n; i++)
    {
        lower[i] = 0xfffffff;
    }

    int s = 1; // 从1节点开始
    vis[s] = 1;
    for (auto e : G[1])
    {
        lower[e.first] = min(lower[e.first], e.second);
    }

    for (int i = 1; i <= n - 1; i++)
    {
        int minn = 0xfffffff, t = s;
        for (int j = 1; j <= n; j++)
        {
            if (vis[j] == 0 && minn > lower[j])
            {
                minn = lower[j];
                s = j;
            }
        }
        if (t == s)
        {
            break;
        }
        cost += minn;
        k++;
        vis[s] = 1;
        for (auto e : G[s])
        {
            if (vis[e.first] == 0)
            {
                lower[e.first] = min(lower[e.first], e.second);
            }
        }
    }

    if (k == n - 1)
    {
        cout << cost << endl;
    }
    else
    {
        cout << "orz" << endl;
    }
}