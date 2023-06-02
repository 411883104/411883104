/*
 * @Author       : Outsider
 * @Date         : 2023-05-11 20:39:28
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-05-11 20:39:48
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Eq\P8800.cc
 */
#include <iostream>
using namespace std;

int a[100010];
int b[100010];
int n, m;

bool check(int x)
{
    int res = 0;
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
    int ll = a[0], rr = b[0];
    for (int i = 0; i < n; i++)
    {
        ll = min(ll, a[i]);
        rr = max(rr, a[i] + b[i]);
    }

    while (ll < rr)
    {
        int mm = ll + ((rr - ll) >> 1);
        if (check(mm))
        {
            ll = mm + 1;
        }
    }
}