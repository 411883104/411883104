/*
 * @Author       : Outsider
 * @Date         : 2023-03-31 16:50:39
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-04-01 09:33:03
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\Graph\P1330.cc
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
queue<int> q;
vector<int> G[10005];
vector<int> color(10005);
vector<int> cnt(5);

bool bfs(int k)
{
    cnt[1] = 0, cnt[2] = 0;
    q.push(k);
    color[k] = 1;
    cnt[color[k]]++;
    while (!q.empty())
    {
        auto x = q.front();
        for (auto e : G[x])
        {
            if (color[e] == color[x])
            {
                cout << "Impossible" << endl;
                return false;
            }
            else if (color[e] == 0)
            {
                color[e] = color[x] % 2 + 1;
                cnt[color[e]]++;
                q.push(e);
            }
        }
        q.pop();
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int u, v;

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int ans = 0;
    int cc = false;
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == 0)
        {
            if (!bfs(i))
            {
                cc = true;
                break;
            }
            ans += min(cnt[1], cnt[2]);
        }
    }

    if (!cc)
    {
        cout << ans << endl;
    }

    return 0;
}