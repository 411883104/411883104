/*
 * @Author: Outsider
 * @Date: 2023-02-18 11:47:13
 * @LastEditors: Outsider
 * @LastEditTime: 2023-02-21 21:12:56
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\Search\P1433.cc
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
void dfs(int c, double dd, pair<double, double> s)
{
    if (c == n || dd >= minn)
    {
        minn = min(minn, dd);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (ch[i] == 0)
        {
            ch[i] = 1;
            dfs(c + 1, dd + dist(s, m[i]), m[i]);
            ch[i] = 0;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m[i].first >> m[i].second;
    }
    dfs(0, 0, make_pair(0, 0));
    cout << fixed << setprecision(2) << minn << endl;
}