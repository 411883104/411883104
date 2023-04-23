#include <iostream>
#include <vector>
#include <stack>
using namespace std;
const int c = 10004;
vector<int> G[c];
int vis[c];
int dfn[c];
int low[c];
int out[c];
int tol[c];
int Gn[c];
stack<int> s;
int t = 0;

int k = 0;
void tarjan(int x)
{
    dfn[x] = low[x] = ++t;
    s.push(x);
    vis[x] = 1;
    for (auto e : G[x])
    {
        if (dfn[e] == 0)
        {
            tarjan(e);
            low[x] = min(low[e], low[x]);
        }
        else if (vis[e])
        {
            low[x] = min(low[x], dfn[e]);
        }
    }

    if (dfn[x] == low[x])
    {
        k++;
        while (!s.empty() && s.top() != x)
        {
            vis[s.top()] = 0;
            Gn[s.top()] = k;
            tol[k]++;
            s.pop();
        }
        if (!s.empty())
        {
            vis[s.top()] = 0;
            Gn[x] = k;
            tol[k]++;
            s.pop();
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int x, y;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        G[x].push_back(y);
    }

    for (int i = 1; i <= n; i++)
    {
        if (dfn[i] == 0)
        {
            tarjan(i);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (auto e : G[i])
        {
            if (Gn[e] != Gn[i])
            {
                out[Gn[i]]++;
            }
        }
    }

    int ans = 0, res = 0;
    for (int i = 1; i <= k; i++)
    {
        if (out[i] == 0)
        {
            ans++;
            res = i;
        }
    }
    if (ans > 1)
    {
        cout << "0" << endl;
    }
    else
    {
        cout << tol[res] << endl;
    }
}