/*
 * @Author       : Outsider
 * @Date         : 2023-05-11 20:39:28
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-05-11 21:05:22
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Eq\P8800.cc
 */
#include <iostream>
using namespace std;

long long a[200010];
long long r[200010];
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
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    long long ll = a[0], rr = b[0];
    for (int i = 0; i < n; i++)
    {
        ll = min(ll, a[i]);
        rr = max(rr, a[i] + b[i]);
    }

    while (ll < rr)
    {
        long long mm = ll + ((rr - ll) >> 1);
        if (check(mm))
        {
            ll = mm + 1;
        }
        else
        {
            rr = mm;
        }
    }
    cout << ll - 1 << endl;
    return 0;
}