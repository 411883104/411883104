/*
 * @Author: Outsider
 * @Date: 2023-01-10 19:09:19
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-10 19:09:37
 * @Description: In User Settings Edit
 * @FilePath: \Lq\other\p1126.cc
 */
#include <iostream>
using namespace std;
int main()
{
    long long b, p, k, result = 1;
    cin >> b >> p >> k;
    cout << b << "^" << p << " mod " << k << "=";
    while (p > 0)
    {
        if (p & 1)
            result = (result * b) % k;
        b = ((b % k) * (b % k)) % k;
        p >>= 1;
    }
    cout << result << endl;
    return 0;
}