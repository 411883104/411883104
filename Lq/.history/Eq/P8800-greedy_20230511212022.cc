/*
 * @Author       : Outsider
 * @Date         : 2023-05-11 20:39:28
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-05-11 21:20:22
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Eq\P8800-greedy.cc
 */
#include <iostream>
using namespace std;

pair<long long, long long> a[200010];
long long b[200010];
long long n, m;

bool check(long long x)
{
    long long res = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < x)
        {
            if (x - a[i] > b[i])
            {
                return false;
            }
            res += x - a[i];
        }
    }
    return res <= m;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        r[i] = a[i];
        r[i] = r[i] - r[i - 1];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++)
    {
    }

    return 0;
}