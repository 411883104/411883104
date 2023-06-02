/*
 * @Author       : Outsider
 * @Date         : 2023-05-24 21:47:59
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-05-25 11:17:43
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Eq\P8655-tp.cc
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
const int c = 1005;
int s[c];
int vis[c];
int n;

vector<int> G[c];
queue<int> q;
int main()
{
    cin >> n;
    int x, y;
    int src, dst;
    for (int i = 0; i < n; i++)
    {
        G[x].push_back(y);
        G[y].push_back(x);
        s[x]++;
        s[y]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (s[i] <= 1)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        auto n = q.front();
        for (auto& x : G[n])
        {
            if (--s[x] == 1)
            {
                
            }
        }
    }

    return 0;
}