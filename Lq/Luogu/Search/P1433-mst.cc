/*
 * @Author: Outsider
 * @Date: 2023-02-18 11:47:13
 * @LastEditors: Outsider
 * @LastEditTime: 2023-02-20 19:12:59
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\Search\P1433-mst.cc
 */
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

pair<double, double> m[20];
int n;
double dist(pair<double, double> n, pair<double, double> m)
{
    return sqrt((n.first - m.first) * (n.first - m.first) +
                (n.second - m.second) * (n.second - m.second));
}
class Edge
{
public:
    int u, v;
    double w;

    Edge(int u, int v, double w) : u(u), v(v), w(w) {}
};
vector<Edge> v;
int arr[200];

int find(int x)
{
    if (arr[x] == x)
    {
        return x;
    }
    return arr[x] = find(arr[x]);
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m[i].first >> m[i].second;
    }
    m[n].first = 0;
    m[n].second = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            v.push_back(Edge(i, j, dist(m[i], m[j])));
        }
    }

    for (size_t i = 0; i < v.size(); i++)
    {
        arr[i] = i;
    }

    sort(v.begin(), v.end(), [](Edge ll, Edge rr) -> bool
         { return ll.w < rr.w; });

    double cost = 0;
    int cnt = 0;
    for (size_t i = 0; i < v.size(); i++)
    {
        int x = find(v[i].u);
        int y = find(v[i].v);
        if (x == y)
        {
            continue;
        }
        arr[x] = y;
        cost += v[i].w;
        if (++cnt == n)
        {
            break;
        }
    }
    cout << cost << endl;
}