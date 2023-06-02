/*
 * @Author       : Outsider
 * @Date         : 2023-06-02 15:13:30
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-06-02 15:38:19
 * @Description  : In User Settings Edi
 * @FilePath     : \Lq\Luogu\Tree\P3379-copy.cc
 */
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int c = 5005;

vector<int> G[c];
int dep[c];
int vis[c];
int Log[c];
int cnt[c][20];

void dfs(int s, int d, int pre)
{
    vis[s] = 1;
    dep[s] = d;
    cnt[s][0] = pre;
    for (int i = 1; i <= Log[d]; i++)
    {
        cnt[s][i] = cnt[cnt[s][i - 1]][i - 1];
    }
    for (auto &n : G[s])
    {
        if (vis[n] == 0)
        {
            dfs(n, d + 1, s);
        }
    }
}

int main()
{
    int n, m, s;
    scanf("%d%d%d", &n, &m, &s);
    int x, y;
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
    }

    for (int i = 2; i <= n; i++)
    {
        Log[i] = Log[i >> 1] + 1;
    }

    dfs(s, 1, 0);

    while (m--)
    {
        scanf("%d%d", &x, &y);
        while (dep[x] != dep[y])
        {
            if (dep[y] > dep[x])
            {
                x = x ^ y;
                y = x ^ y;
                x = x ^ y;
            }
            x = cnt[x][Log[dep[x] - dep[y]]];
        }
        if (x != y)
        {
            for (int i = Log[dep[x]]; i >= 0; i--)
            {
                if (cnt[x][i] != cnt[y][i])
                {
                    x = cnt[x][i];
                    y = cnt[y][i];
                }
            }
        }
        if (x != y)
        {
            printf("%d\n", cnt[x][0]);
        }
        else
        {
            printf("%d\n", x);
        }
    }
    return 0;
}