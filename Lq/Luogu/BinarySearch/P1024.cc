/*
 * @Author: Outsider
 * @Date: 2023-02-15 12:30:59
 * @LastEditors: Outsider
 * @LastEditTime: 2023-02-15 12:40:12
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\BinarySearch\P1024.cc
 */
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double a, b, c, d;
double fun(double x)
{
    return a * x * x * x + b * x * x + c * x + d;
}
int main()
{
    cin >> a >> b >> c >> d;
    for (double i = -100; i <= 100; i += 0.001)
    {
        if (fun(i) * fun(i + 0.001) < 0)
        {
            cout << fixed << setprecision(2) << (i + i + 0.001) / 2 << " ";
        }
    }
}