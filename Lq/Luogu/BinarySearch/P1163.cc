/*
 * @Author: Outsider
 * @Date: 2023-02-16 12:18:54
 * @LastEditors: Outsider
 * @LastEditTime: 2023-02-16 12:57:46
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\BinarySearch\P1163.cc
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
    double ll = 0, rr = 100;
    while (rr - ll > 1e-6)
    {
        double mm = ll + ((rr - ll) / 2);
        if (check(mm))
        {
            ll = mm + 0.0001;
        }
        else
        {
            rr = mm;
        }
    }
    cout << fixed << setprecision(1) << ll * 100 << endl;
}