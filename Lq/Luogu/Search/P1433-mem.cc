/*
 * @Author: Outsider
 * @Date: 2023-02-18 11:47:13
 * @LastEditors: Outsider
 * @LastEditTime: 2023-02-21 21:42:24
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\Search\P1433-mem.cc
 */
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

pair<double, double> m[20];
int n;
double dist(pair<double, double> n, pair<double, double> m)
{
    return sqrt((n.first - m.first) * (n.first - m.first) +
                (n.second - m.second) * (n.second - m.second));
}
int ch[20];
double minn = 1e9;
double mem[20][1 << 20];
void dfs(int c, double dd, int s, int cur)
{
    if (c == n || dd >= minn)
    {
        minn = min(minn, dd);
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (ch[i] == 0)
        {
            if (mem[i][s | (1 << i)] != 0 && mem[i][s | (1 << i)] < dd + dist(m[cur], m[i]))
            {
                continue;
            }
            ch[i] = 1;
            mem[i][s | (1 << i)] = dd + dist(m[cur], m[i]);
            dfs(c + 1, dd + dist(m[cur], m[i]), s | (1 << i), i);
            ch[i] = 0;
        }
    }
}

int main()
{
    cin >> n;
    m[0].first = m[0].second = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> m[i].first >> m[i].second;
    }
    dfs(0, 0, 0, 0);
    cout << fixed << setprecision(2) << minn << endl;
}