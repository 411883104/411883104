/*
 * @Author       : Outsider
 * @Date         : 2023-03-05 09:04:58
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-03-06 15:20:38
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\Graph\P3916-vector.cc
 */
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
vector<int> G[10005];

bool check[1005];
int vis[1005];
int dfs(int n)
{
    int maxx = n;
    check[n] = true;
    if (vis[n] != 0)
    {
        return vis[n];
    }
    for (auto e : G[n])
    {
        if (!check[e])
        {
            maxx = max(maxx, dfs(e));
        }
    }
    return vis[n] = maxx;
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    int x, y;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &x, &y);
        G[x].push_back(y);
    }

    for (int i = 1; i <= n; i++)
    {
        memset(check, 0, sizeof(bool) * (n + 1));
        printf("%d ", dfs(i));
    }
    printf("\n");
    return 0;
}