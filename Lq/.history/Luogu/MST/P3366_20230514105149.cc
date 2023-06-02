/*
 * @Author       : Outsider
 * @Date         : 2023-04-05 22:30:44
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-04-05 22:53:42
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\MST\P3366.cc
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int c = 5005;
int s[c];
struct Edge
{
    int u, v, w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

vector<Edge> G;
// 并查集
int find(int x)
{
    if (s[x] == x)
    {
        return x;
    }
    return s[x] = find(s[x]);
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        s[i] = i;
    }
    int u, v, w;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        G.emplace_back(u, v, w);
    }
    sort(G.begin(), G.end(), [](Edge& a, Edge& b) -> bool { return a.w < b.w; });

    int k = 0;
    int cost = 0;
    for (auto e : G)
    {
        int x = find(e.u);
        int y = find(e.v);
        if (x != y)
        {
            s[x] = y;
            cost += e.w;
            k++;
        }
        if (k == n - 1)
        {
            break;
        }
    }

    if (k == n - 1)
    {
        cout << cost << endl;
    }
    else
    {
        cout << "orz" << endl;
    }
}