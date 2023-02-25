/*
 * @Author: Outsider
 * @Date: 2023-02-15 10:29:37
 * @LastEditors: Outsider
 * @LastEditTime: 2023-02-15 10:50:59
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\BinarySearch\P1873.cc
 */
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int hh[1005];
bool check(int h)
{
    long long tol = 0;
    for (int i = 0; i < n && hh[i] > h; i++)
    {
        tol += (hh[i] - h);
    }
    if (tol >= m)
    {
        return true;
    }
    return false;
}
int main()
{
    cin >> n >> m;
    int maxx = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> hh[i];
        maxx = max(maxx, hh[i]);
    }
    sort(hh, hh + n, greater<int>());
    int ll = 0, rr = maxx + 1;
    while (ll < rr)
    {
        int mm = ll + ((rr - ll) >> 1);
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
}