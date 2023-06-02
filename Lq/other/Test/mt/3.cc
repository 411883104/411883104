#include <iostream>
#include <queue>
using namespace std;

string mm[205];
int n, m, k;
bool vis[205][205];
int coin[205][205];
class status
{
public:
    int x, y, coin;
    status(int x, int y, int c) : x(x), y(y), coin(c) {}
};

queue<status> q;

int ans = 0;
int res = 0;
void bfs(int x, int y)
{
    q.push({x, y, 0});
    vis[x][y] = true;
    while (!q.empty())
    {
        auto now = q.front();
        if (now.x + 1 < n && vis[now.x + 1][now.y] == false)
        {
            vis[now.x + 1][now.y] = true;
            int c = now.coin;
            if (mm[now.x][now.y] != mm[now.x + 1][now.y])
            {
                c -= k;
            }
            if (c >= 0)
            {
                c += coin[now.x + 1][now.y];
                q.push({now.x + 1, now.y, c});
                ans = max(c, ans);
            }
        }
        if (now.y + 1 < m)
        {
            vis[now.x][now.y + 1] = true;
            int c = now.coin;
            if (mm[now.x][now.y] != mm[now.x][now.y + 1])
            {
                c -= k;
            }
            if (c >= 0)
            {
                c += coin[now.x][now.y + 1];
                q.push({now.x, now.y + 1, c});
                ans = max(c, ans);
            }
        }
        q.pop();
    }
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> mm[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> coin[i][j];
        }
    }
    bfs(0, 0);
    cout << ans << endl;
    return 0;
}
