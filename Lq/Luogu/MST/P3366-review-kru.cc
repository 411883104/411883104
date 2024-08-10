#include <iostream>
#include <algorithm>
using namespace std;

const int c = 200005;
struct Edge
{
    int u, v, w;
};

Edge edges[c];

int s[c];

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
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    std::sort(edges, edges + m,
              [](Edge &lhs, Edge &rhs) -> bool { return lhs.w < rhs.w; });

    int ans = 0, tol = 0;
    for (int i = 0; i < m && tol < n; i++)
    {
        int xx = find(edges[i].u);
        int yy = find(edges[i].v);
        if (xx != yy)
        {
            s[xx] = yy;
            ans += edges[i].w;
            tol++;
        }
    }
    if (tol != n - 1)
    {
        cout << "orz" << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}