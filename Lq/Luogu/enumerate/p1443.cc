/*
 * @Author: Outsider
 * @Date: 2023-01-16 21:03:00
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-16 21:18:23
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\enumerate\p1443.cc
 */
#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;
const int c = 405;
int vis[c][c];
int arr[c][c];
int n, m, x, y;
int arr1[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int arr2[8] = {2, 1, -1, -2, -2, -1, 1, 2};
struct p
{
    int s1;
    int s2;
};
queue<p> q;
void bfs()
{
    p now, next;
    now.s1 = x;
    now.s2 = y;
    vis[now.s1][now.s2] = 1;
    q.push(now);
    while (!q.empty())
    {
        now = q.front();
        for (int i = 0; i < 8; i++)
        {
            next.s1 = now.s1 + arr1[i];
            next.s2 = now.s2 + arr2[i];
            if (next.s1 > 0 && next.s1 <= n && next.s2 > 0 && next.s2 <= m && !vis[next.s1][next.s2])
            {
                arr[next.s1][next.s2] = arr[now.s1][now.s2] + 1;
                vis[next.s1][next.s2] = 1;
                q.push(next);
            }
        }
        q.pop();
    }
}
int main()
{
    cin >> n >> m >> x >> y;
    bfs();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (vis[i][j] == 0 && !(i == x && j == y))
                arr[i][j] = -1;
            cout << left << setw(5) << arr[i][j];
        }
        cout << endl;
    }
    return 0;
}