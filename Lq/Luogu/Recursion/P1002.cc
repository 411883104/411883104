/*
 * @Author: Outsider
 * @Date: 2023-01-15 10:52:36
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-15 12:31:15
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\Recursion\P1002.cc
 */
#include <iostream>
#include <queue>

using namespace std;
struct point
{
    int x, y;
};
queue<point> q;

int dx[] = {2, 2, 1, 1, -2, -2, -1, -1};
int dy[] = {1, -1, 2, -2, 1, -1, 2, -2};

int cnt[25][25];

long long bfs(int x, int y, int n, int m)
{
    point now = {x, y};
    point next;
    for (int i = 0; i < 8; i++)
    {
        next = {now.x + dx[i], now.y + dy[i]};
        if (next.x >= 0 && next.x <= n && next.y >= 0 && next.y <= m && cnt[next.x][next.y] == 0)
        {
            cnt[next.x][next.y] = 1;
        }
    }
    cnt[x][y] = 1;

    long long ans = 0;
    now.x = 0, now.y = 0;
    if (cnt[0][0] == 0)
    {
        cnt[0][0] = 1;
        q.push(now);
    }
    while (!q.empty())
    {
        now = q.front();
        if (now.x == n && now.y == m)
        {
            ans++;
        }
        else
        {
            next = {now.x, now.y + 1};
            if (next.x >= 0 && next.x <= n && next.y >= 0 && next.y <= m && cnt[next.x][next.y] == 0)
            {
                // cnt[next.x][next.y] = 1;
                q.push(next);
            }
            next = {now.x + 1, now.y};
            if (next.x >= 0 && next.x <= n && next.y >= 0 && next.y <= m && cnt[next.x][next.y] == 0)
            {
                // cnt[next.x][next.y] = 1;
                q.push(next);
            }
        }
        q.pop();
    }
    return ans;
}

int main()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    cout << bfs(x, y, n, m) << endl;
}