/*
 * @Author       : Outsider
 * @Date         : 2023-03-05 09:04:58
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-03-06 16:45:17
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\Graph\P3916-re.cc
 */
#include <iostream>
#include <cstring>
using namespace std;

struct Edge
{
    int idx;
    Edge* next;
    Edge(int idx) : idx(idx), next(nullptr) {}
};

struct Node
{
    Edge* edge;
    Node() : edge(nullptr) {}
};

Node G[1005];
bool check[1005];
int vis[1005];
void dfs(int n, int maxx)
{
    check[n] = true;
    vis[n] = maxx;
    auto e = G[n].edge;
    while (e)
    {
        if (!check[e->idx])
        {
            check[e->idx] = true;
            dfs(e->idx, maxx);
        }
        e = e->next;
    }
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    int x, y;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &x, &y);
        Edge* e = new Edge(x);
        e->next = G[y].edge;
        G[y].edge = e;
    }

    for (int i = n; i > 0; i--)
    {
        if (!check[i]) dfs(i, i);
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", vis[i]);
    }
    printf("\n");
    return 0;
}