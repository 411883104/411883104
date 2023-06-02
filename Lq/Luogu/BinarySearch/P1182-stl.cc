/*
 * @Author       : Outsider
 * @Date         : 2023-04-07 21:03:02
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-04-07 21:04:58
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\BinarySearch\P1182-stl.cc
 */

// undo

#include <iostream>
using namespace std;
int n, m;
int a[1005];
bool check(int x)
{
    int tol = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (cnt + a[i] > x)
        {
            cnt = a[i];
            tol++;
        }
        else
        {
            cnt += a[i];
        }
    }
    if (tol == m)
    {
        return false;
    }
    else if (tol < m)
    {
        return true;
    }
    return false;
}
int main()
{
    cin >> n >> m;
    int minn = 0;
    int maxx = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        minn = max(minn, a[i]);
        maxx += a[i];
    }
    int ll = minn, rr = maxx + 1;
    while (ll < rr)
    {
        int mm = ll + ((rr - ll) >> 1);
        if (check(mm))
        {
            rr = mm;
        }
        else
        {
            ll = mm + 1;
        }
    }
    cout << ll << endl;
}