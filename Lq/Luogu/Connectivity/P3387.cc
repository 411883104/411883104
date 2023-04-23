#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
const int c = 10004;
vector<int> G[c];
vector<int> Gm[c];

queue<int> q;
int Gn[c];
int val[c];
int dfn[c];
int low[c];
int vis[c];
int in[c];
int res[c];

stack<int> s;

int t = 0;
int k = 0;
void tarjan(int x)
{
    low[x] = dfn[x] = ++t;
    s.push(x);
    vis[x] = 1;
    for (auto e : G[x])
    {
        if (dfn[e] == 0)
        {
            tarjan(e);
            low[x] = min(low[x], low[e]);
        }
        else if (vis[e])
        {
            low[x] = min(low[x], dfn[e]);
        }
    }

    if (dfn[x] == low[x])
    {
        while (!s.empty() && s.top() != x)
        {
            vis[s.top()] = 0;
            Gn[s.top()] = x;
            val[x] += val[s.top()];
            val[s.top()] = 0;
            s.pop();
        }
        if (!s.empty())
        {
            Gn[s.top()] = x;
            vis[s.top()] = 0; // 不写 wa 4 7
            // val[x] += val[s.top()];
            // val[s.top()] = 0;
            s.pop();
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> val[i];
        Gn[i] = i;
    }

    int x, y;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        G[x].push_back(y);
    }
    for (int i = 1; i <= n; i++)
    {
        if (dfn[i] == 0) tarjan(i);
    }

    for (int i = 1; i <= n; i++)
    {
        for (auto e : G[i])
        {
            if (Gn[i] != Gn[e])
            {
                Gm[Gn[i]].push_back(Gn[e]);
                in[Gn[e]]++;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        res[i] = val[i];
        if (in[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        auto n = q.front();
        for (auto e : Gm[n])
        {
            in[e]--;
            if (in[e] == 0)
            {
                res[e] = max(res[e], res[n] + val[e]);
                q.push(e);
            }
        }
        ans = max(res[n], ans);
        q.pop();
    }

    cout << ans << endl;
}