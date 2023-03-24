#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int c = 5005;

struct Edge
{
    int u, v;
    Edge* next;
    Edge(int u, int v, Edge* n) : u(u), v(v), next(n) {}
};

struct Node
{
    Edge* head;
    Node() : head(nullptr) {}
};

Node G[c];
int dep[c];
int ch[c];
int Log[c];
int cnt[c][20];

void dfs(int x, int d, int pre)
{
    ch[x] = true;
    dep[x] = d;
    cnt[x][0] = pre;
    for (int i = 1; i <= Log[d]; i++)
    {
        cnt[x][i] = cnt[cnt[x][i - 1]][i - 1];
    }
    for (auto e = G[x].head; e != nullptr; e = e->next)
    {
        if (ch[e->v] == 0)
        {
            dfs(e->v, d + 1, x);
        }
    }
}

int main()
{
    int n, m, s;
    cin >> n >> m >> s;
    int x, y;
    for (int i = 2; i <= n; i++)
    {
        Log[i] = Log[i >> 1] + 1;
    }

    for (int i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        auto e = new Edge(x, y, G[x].head);
        G[x].head = e;
        e = new Edge(y, x, G[y].head);
        G[y].head = e;
    }

    dfs(s, 1, 0);

    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        if (dep[x] < dep[y])
        {
            n = x;
            x = y;
            y = n;
        }
        while (dep[x] != dep[y])
        {
            x = cnt[x][Log[(dep[x] - dep[y])]];
        }
        if (x != y)
        {
            for (int j = Log[(dep[x])]; j >= 0; j--)
            {
                if (cnt[x][j] != cnt[y][j])
                {
                    x = cnt[x][j];
                    y = cnt[y][j];
                }
            }
        }
        if (x != y)
            cout << cnt[x][0] << endl;
        else
            cout << x << endl;
    }
}