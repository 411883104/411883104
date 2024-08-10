/*
 * @Author       : Outsider
 * @Date         : 2023-04-23 19:23:09
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-04-24 09:44:50
 * @Description  : In User Settings Edit
 * @FilePath     : \Luogu\Hw\P1115-divide.cc
 */
#include <iostream>
#include <climits>
using namespace std;

int a[200005];

int divide(int ll, int rr)
{
    if (ll >= rr)
    {
        return a[ll];
    }
    int mm = ll + ((rr - ll) >> 1);
    int left = divide(ll, mm);
    int right = divide(mm + 1, rr);

    int lt = INT_MIN;
    int tt = 0;
    for (int i = mm; i >= ll; i--)
    {
        tt += a[i];
        lt = max(lt, tt);
    }
    int rt = INT_MIN;
    tt = 0;
    for (int i = mm + 1; i <= rr; i++)
    {
        tt += a[i];
        rt = max(rt, tt);
    }

    return max(max(left, right), lt + rt);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    cout << divide(1, n) << endl;
    return 0;
}