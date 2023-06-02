/*
 * @Author       : Outsider
 * @Date         : 2023-06-01 20:52:19
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-06-02 12:53:02
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\Tree\P3379-dfs.cc
 */
#include <iostream>
#include <vector>
using namespace std;

const int c = 505;
vector<int> G[c];

int n, m, s;
int dep[c];
int vis[c];
int parent[c];
void dfs(int x, int d)
{
    if (vis[x] == 1)
    {
        return;
    }
    dep[x] = dep[d] + 1;
    parent[x] = d;
    vis[x] = 1;
    for (auto n : G[x])
    {
        dfs(n, x);
    }
}

int main()
{
    cin >> n >> m >> s;
    int x, y;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(s, s);
    while (m--)
    {
        cin >> x >> y;
        while (dep[x] != dep[y])
        {
            if (dep[x] > dep[y])
            {
                x = parent[x];
            }
            else
            {
                y = parent[y];
            }
        }
        while (x != y) // parent[x]!=parent[y] wa??
        {
            x = parent[x];
            y = parent[y];
        }
        cout << x << endl;
    }
    return 0;
}