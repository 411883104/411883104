/*
 * @Author       : Outsider
 * @Date         : 2023-03-22 21:07:27
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-03-23 16:56:36
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\ShortPath\P1991.cc
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Edge
{
    int u, v;
    double w;
    Edge(int u, int v, double w) : u(u), v(v), w(w) {}
};
vector<Edge> G;
vector<pair<int, int>> v(500);

int a[505];
int find(int x)
{
    if (a[x] == x)
    {
        return x;
    }
    return a[x] = find(a[x]);
}

int main()
{
    int s, p;
    cin >> s >> p;

    for (int i = 1; i <= p; i++)
    {
        cin >> v[i].first >> v[i].second;
        a[i] = i;
    }
    for (int i = 1; i <= p; i++)
    {
        for (int j = i + 1; j <= p; j++)
        {
            G.push_back(
                Edge(i, j,
                     sqrt((v[i].first - v[j].first) * (v[i].first - v[j].first) +
                          (v[i].second - v[j].second) * (v[i].second - v[j].second))));
        }
    }

    sort(G.begin(), G.end(), [](Edge& ll, Edge& rr) -> bool { return ll.w < rr.w; });

    int k = p - s;

    double maxx = 0;
    for (auto e : G)
    {
        int x = find(e.u);
        int y = find(e.v);
        if (x != y)
        {
            k--;
            a[x] = y;
            maxx = max(maxx, e.w);
            if (k == 0)
            {
                break;
            }
        }
    }

    cout << fixed << setprecision(2) << maxx << endl;
}