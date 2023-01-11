/*
 * @Author: Outsider
 * @Date: 2023-01-02 20:51:29
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-02 21:05:13
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\p2241.cc
 */
#include <iostream>

using namespace std;

long long n, m;
long long ans = 0;

int main()
{
    cin >> n >> m;
    long long tol = (n + 1) * (n) / 2 * (m) * (m + 1) / 2;
    int a = n, b = m;
    for (; a > 0 && b > 0; a--, b--)
    {
        ans += a * b;
    }
    cout << ans << " " << tol - ans << endl;
}