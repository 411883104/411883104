/*
 * @Author       : Outsider
 * @Date         : 2023-06-06 11:56:54
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-06-06 12:04:38
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\Math\B3634.cc
 */
#include <iostream>
#include <algorithm>
using namespace std;

long long Gcd(long long x, long long y)
{
    if (y == 0)
    {
        return x;
    }
    return Gcd(y, x % y);
}

int main()
{
    long long a, b;
    cin >> a >> b;
    cout << __gcd(a, b) << " " << a * b / __gcd(a, b) << endl;
    return 0;
}