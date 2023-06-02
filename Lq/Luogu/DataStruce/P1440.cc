/*
 * @Author       : Outsider
 * @Date         : 2023-04-01 21:08:12
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-04-01 21:30:42
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\DataStruce\P1440.cc
 */
#include <iostream>
using namespace std;

pair<int, int> q[2007];

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int n, m;
    scanf("%d%d", &n, &m);
    // cin >> n >> m;
    int x;
    int hh = 0, tt = -1;
    for (int i = 0; i < n; i++)
    {
        // cin >> x;
        scanf("%d", &x);
        // cout << q[hh].first << endl;
        printf("%d\n", q[hh].first);
        while (hh <= tt && q[tt].first >= x)
        {
            tt--;
        }
        q[++tt] = make_pair(x, i);
        if (q[tt].second - q[hh].second == m)
        {
            hh++;
        }
    }
}
