/*
 * @Author       : Outsider
 * @Date         : 2023-03-17 11:16:26
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-03-17 12:06:23
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\Math\P1029.cc
 */
#include <iostream>
using namespace std;

int x, y;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int main()
{
    cin >> x >> y;
    int tol = x * y;
    int ll = x, rr = y;
    int ans = 0;
    while (ll <= rr)
    {
        if (ll * rr == tol && gcd(rr, ll) == x)
        {
            if (ll == rr)
            {
                ans++;
            }
            else
            {
                ans += 2;
            }
            ll++, rr--;
        }
        else if (ll * rr > tol)
        {
            rr--;
        }
        else
        {
            ll++;
        }
    }
    cout << ans << endl;
}