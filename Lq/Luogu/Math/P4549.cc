/*
 * @Author       : Outsider
 * @Date         : 2023-06-06 12:47:48
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-06-06 13:14:15
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\Math\P4549.cc
 */
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int ans = 0;
    int n;
    cin >> n;
    int x;

    while (n--)
    {
        cin >> x;
        ans = __gcd(abs(x), ans);
    }
    cout << ans << endl;
    return 0;
}