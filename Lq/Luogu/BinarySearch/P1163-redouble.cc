/*
 * @Author: Outsider
 * @Date: 2023-02-16 12:18:54
 * @LastEditors: Outsider
 * @LastEditTime: 2023-02-16 13:28:59
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\BinarySearch\P1163-redouble.cc
 */
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
double n, m, k;
bool check(double x)
{
    double tol = 0;
    double b = 1;
    for (int i = 1; i <= k; i++)
    {
        b *= (1 + x);
        tol += (m / b);
    }
    return tol >= n;
}
int main()
{
    cin >> n >> m >> k;
    double dd = 1e-8;
    double ans = 1e-8;
    while (dd > 1e-10)
    {
        if (check(ans + dd))
        {
            ans += dd;
            dd *= 2;
        }
        else
        {
            dd /= 2;
        }
    }
    cout << fixed << setprecision(1) << ans * 100 << endl;
}