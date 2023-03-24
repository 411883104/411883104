/*
 * @Author       : Outsider
 * @Date         : 2023-03-17 14:44:19
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-03-17 16:35:38
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\Math\P1072.cc
 */
#include <iostream>
#include <cmath>
using namespace std;

long long a0, a1, b0, b1;

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
    int tt;
    cin >> tt;
    while (tt--)
    {
        int ans = 0;
        cin >> a0 >> a1 >> b0 >> b1;
        for (int i = 1; i * i <= b0; i++)
        {
            if (b0 % i == 0)
            {
                if (gcd(b1 / b0 * i, a0) == a1 &&
                    b1 / b0 * i * b0 / gcd(b1 / b0 * i, b0) == b1)
                {
                    ans++;
                }
                if (i != b0 / i && gcd(b1 / b0 * (b0 / i), a0) == a1 &&
                    b1 / b0 * (b0 / i) * b0 / gcd(b1 / b0 * (b0 / i), b0) == b1)
                {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}