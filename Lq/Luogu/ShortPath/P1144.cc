#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int c = 1e6 + 5;
vector<int> G[c];
queue<int> q;
int cnt[c];
int vis[c];
int dist[c];
int main()
{
    int n, m;
    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        dist[i] = 0xfffffff;
    }
    q.push(1);
    vis[1] = 1;
    cnt[1] = 1;
    dist[1] = 0;

    while (!q.empty())
    {
        auto x = q.front();
        for (auto e : G[x])
        {
            if (dist[e] > dist[x] + 1)
            {
                dist[e] = dist[x] + 1;
                cnt[e] = cnt[x];
                if (vis[e] == 0)
                {
                    vis[e] = 1;
                    q.push(e);
                }
            }
            else if (dist[e] == dist[x] + 1)
            {
                cnt[e] += cnt[x];
                cnt[e] %= 100003;
            }
        }
        vis[x] = 0;
        q.pop();
    }

    for (int i = 1; i <= n; i++)
    {
        cout << cnt[i] << endl;
    }
    return 0;
}