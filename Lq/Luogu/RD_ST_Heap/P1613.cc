#include <iostream>
#include <cmath>
using namespace std;

const int c = 55;
int dis[c][c];
int main()
{
    int n, m;
    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dis[i][j] = 0xfffffff;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        dis[u][v] = 1;
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);

    dis[1][n]--;

    int ans = 1;
    int debris = log2(dis[1][n]);
    dis[1][n] -= (1 << debris);
    while (dis[1][n])
    {
        if ((1 << debris) > dis[1][n])
        {
            debris--;
        }
        else
        {
            ans++;
            dis[1][n] -= (1 << debris);
        }
    }
    cout << ans << endl;
}