/*
 * @Author       : Outsider
 * @Date         : 2023-05-24 21:47:59
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-05-25 11:14:40
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Eq\P8655-tp.cc
 */
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int c = 1005;
int s[c];
int vis[c];
int n;

vector<int> G[c];

void dfs(int src, int tol)
{
    if (tol == n)
    {
        return;
    }
    for (auto& n : G[src])
    {
        if (vis[n] == 0)
        {
            vis[n] = 1;
            dfs(n, tol + 1);
            vis[n] = 0;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i <= n + 1; i++)
    {
        s[i] = i;
    }
    int x, y;
    int src, dst;
    for (int i = 0; i < n; i++)
    {
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        vis[src] = 1;
        dfs(i);
        memset(vis, 0, (n + 1) * 4);
    }
    return 0;
}