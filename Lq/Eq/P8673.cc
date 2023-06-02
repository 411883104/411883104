/*
 * @Author       : Outsider
 * @Date         : 2023-05-29 09:21:02
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-05-29 15:58:01
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Eq\P8673.cc
 */
#include <iostream>
#include <queue>
using namespace std;

const int c = 1005;
int n, k;
string m[c];
struct point
{
    int x, y, k, s;
    point(int x, int y, int k, int s) : x(x), y(y), k(k), s(s) {}
};

queue<point> q;
int vis[c][c];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int ans = 0xfffffff;
void bfs(int x, int y)
{
    if (m[x][y] == '%')
    {
        q.emplace(x, y, k, 0);
    }
    else
    {
        q.emplace(x, y, 0, 0);
    }
    vis[x][y] = true;
    while (!q.empty())
    {
        auto now = q.front();
        if (now.x == n - 1 && now.y == n - 1)
        {
            ans = min(now.s, ans);
        }
        else
        {
            for (int i = 0; i < 4; i++)
            {
                int xx = now.x + dx[i];
                int yy = now.y + dy[i];
                if (xx >= 0 && xx < n && yy >= 0 && yy < n)
                {
                    if (m[xx][yy] == 'X' && now.k > 0)
                    {
                        if (vis[xx][yy] == -1 ||
                            (vis[xx][yy] != -1 && vis[xx][yy] < now.k))
                        {
                            q.emplace(xx, yy, now.k-1, now.s + 1);
                            vis[xx][yy] = max(0, now.k);
                        }
                    }
                    else if (m[xx][yy] == '.')
                    {
                        if (vis[xx][yy] == -1 ||
                            (vis[xx][yy] != -1 && vis[xx][yy] < now.k))
                        {
                            q.emplace(xx, yy, now.k-1, now.s + 1);
                            vis[xx][yy] = max(0, now.k);
                        }
                    }
                    else if (m[xx][yy] == '%')
                    {
                        if (vis[xx][yy] == -1 ||
                            (vis[xx][yy] != -1 && vis[xx][yy] < now.k))
                        {
                            q.emplace(xx, yy, k, now.s + 1);
                            vis[xx][yy] = k;
                        }
                    }
                }
            }
        }
        q.pop();
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> m[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            vis[i][j] = -1;
        }
    }
    bfs(0, 0);
    cout << ans << endl;
    return 0;
}