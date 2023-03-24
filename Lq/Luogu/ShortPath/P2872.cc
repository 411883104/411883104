/*
 * @Author       : Outsider
 * @Date         : 2023-03-23 17:01:55
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-03-23 19:06:48
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\ShortPath\P2872.cc
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

int a[1005];

int find(int x)
{
    if (a[x] == x)
    {
        return x;
    }
    return a[x] = find(a[x]);
}

vector<pair<double, double>> v(1005);
struct Edge
{
    int u, v;
    double w;
    Edge(int u, int v, double w) : u(u), v(v), w(w) {}
};

vector<Edge> G;

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> v[i].first >> v[i].second;
        a[i] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            G.push_back(
                Edge(i, j,
                     sqrt((v[i].first - v[j].first) * (v[i].first - v[j].first) +
                          (v[i].second - v[j].second) * (v[i].second - v[j].second))));
        }
    }

    int x, y;
    int k = n - 1;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        int xx = find(x);
        int yy = find(y);
        if (xx != yy)
        {
            k--;
            a[xx] = yy;
        }
    }

    sort(G.begin(), G.end(), [](Edge& ll, Edge& rr) -> bool { return ll.w < rr.w; });

    double ans = 0;
    for (auto e : G)
    {
        if (k <= 0)
        {
            break;
        }
        int x = find(e.u);
        int y = find(e.v);
        if (x != y)
        {
            a[x] = y;
            ans += e.w;
            k--;
        }
    }
    cout << fixed << setprecision(2) << ans << endl;
}