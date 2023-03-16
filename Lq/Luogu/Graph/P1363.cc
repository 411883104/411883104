/*
 * @Author       : Outsider
 * @Date         : 2023-03-14 20:09:11
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-03-15 19:46:20
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\Graph\P1363.cc
 */
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int c = 1505;
int check[c][c];
string map[c];
int n, m;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int fx(int x, int y) { return (x) * 131 + (y ) * 13; }

bool bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    check[x][y] = fx(x, y);
    while (!q.empty())
    {
        auto now = q.front();
        for (int i = 0; i < 4; i++)
        {
            auto x = dx[i] + now.first;
            auto y = dy[i] + now.second;

            int tx = (x + n * 4) % n;
            int ty = (y + m * 4) % m;

            if (map[tx][ty] != '#')
            {
                int hash = fx(x, y);

                if (check[tx][ty] == 0)
                {
                    q.push(make_pair(x, y));
                    check[tx][ty] = hash;
                }
                else if (check[tx][ty] != hash)
                {
                    return true;
                }
            }
        }
        q.pop();
    }
    return false;
}

int main()
{
    int x, y;
    while (cin >> n >> m)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> map[i];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (map[i][j] == 'S')
                {
                    x = i;
                    y = j;
                    goto end;
                }
            }
        }
    end:
        memset(check, 0, sizeof(check));
        if (bfs(x, y))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}