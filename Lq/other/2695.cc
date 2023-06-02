#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int tt[1005];
vector<pair<int, int>> G[1005];
int dist[1005];
bool check[1005];
queue<int> q;
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        dist[i] = 0xfffffff;
        cin >> tt[i];
    }
    int x, y, z;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y >> z;
        G[x].push_back(make_pair(y, z));
        G[y].push_back(make_pair(x, z));
    }
    q.push(1);
    dist[1] = 0;
    check[1] = true;
    while (!q.empty())
    {
        auto t = q.front();
        for (auto e : G[t])
        {
            if (e.first != n)
            {
                if (dist[e.first] > dist[t] + e.second + tt[e.first])
                {
                    dist[e.first] = dist[t] + e.second + tt[e.first];
                    if (!check[e.first])
                    {
                        q.push(e.first);
                        check[e.first] = true;
                    }
                }
            }
            else
            {
                if (dist[e.first] > dist[t] + e.second)
                {
                    dist[e.first] = dist[t] + e.second;
                    if (!check[e.first])
                    {
                        q.push(e.first);
                        check[e.first] = true;
                    }
                }
            }
        }
        q.pop();
        check[t] = false;
    }
    cout << dist[n] << endl;
    return 0;
}