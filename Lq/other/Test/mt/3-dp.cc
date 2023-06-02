#include <iostream>
#include <queue>
using namespace std;

string mm[205];
int n, m, k;
bool vis[205][205];
int coin[205][205];
int dp[205][205];
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
            int c = now.coin + coin[now.x + 1][now.y];
            if (mm[now.x][now.y] != mm[now.x + 1][now.y])
            {
                c -= k;
            }
            ans = max(c, ans);
            q.push({now.x + 1, now.y, c});
        }
        if (now.y + 1 < m)
        {
            vis[now.x][now.y + 1] = true;
            int c = now.coin + coin[now.x][now.y + 1];
            if (mm[now.x][now.y] != mm[now.x][now.y + 1])
            {
                c -= k;
            }
            ans = max(c, ans);
            q.push({now.x, now.y + 1, c});
        }
        q.pop();
    }
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> mm[i];
        mm[i].insert(mm[i].begin(), mm[i][0]);
        if (i == 1)
        {
            mm[i - 1] = mm[i];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> coin[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int left = coin[i][j - 1] - k * (int)(mm[i][j - 1] != mm[i][j]);
            int top = coin[i - 1][j] - k * (int)(mm[i - 1][j] != mm[i][j]);
            if (left < 0 && top < 0)
            {
                cout << ans << endl;
                return 0;
            }
            if (left < 0 && top == 0 && i == 1)
            {
                cout << ans << endl;
                return 0;
            }
            if (i == 1 && j == 1)
            {
                continue;
            }
            if (top < 0 && left == 0 && j == 1)
            {
                cout << ans << endl;
                return 0;
            }
            coin[i][j] += max(left, top);
            ans = max(coin[i][j], ans);
        }
    }
    cout << ans << endl;
    return 0;
}
