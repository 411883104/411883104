#include <iostream>
#include <cmath>
using namespace std;

const int c = 55;
int dis[c][c];
bool check[c][c][65];
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
        check[u][v][0] = true;
    }

    for (int k = 1; k <= 64; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                for (int t = 1; t <= n; t++)
                {
                    if (check[i][t][k - 1] && check[t][j][k - 1])
                    {
                        check[i][j][k] = true;
                        dis[i][j] = 1;
                    }
                }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);

    cout << dis[1][n] << endl;
}