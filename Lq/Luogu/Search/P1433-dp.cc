/*
 * @Author: Outsider
 * @Date: 2023-02-18 11:47:13
 * @LastEditors: Outsider
 * @LastEditTime: 2023-02-21 09:57:04
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\Search\P1433-dp.cc
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
double minn = 1e9;

double mem[20][1 << 16] = {0};

int main()
{
    cin >> n;
    m[0].first = m[0].second = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> m[i].first >> m[i].second;
    }
    for (int i = 0; i < n; i++)
    {
        mem[i][1 << i] = dist(m[0], m[i]);
    }
    for (int ss = 1; ss <= (1 << n); ss++)
    {
        // if ((ss & 1) == 0)
        // {
        //     continue;
        // }
        for (int i = 1; i <= n; i++)
        {
            if ((ss & (1 << i)) == 0)
            {
                continue;
            }
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                    continue;
                if ((ss & (1 << j)) != 0)
                {
                    mem[i][ss] = min(mem[i][ss], mem[j][ss - (1 << i - 1)] + dist(m[i], m[j]));
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        minn = min(mem[i][1 << n], minn);
    }
    cout << fixed << setprecision(2) << minn << endl;
}