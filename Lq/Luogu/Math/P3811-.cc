/*
 * @Author       : Outsider
 * @Date         : 2023-03-18 16:40:20
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-03-20 19:29:19
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\Math\P3811-.cc
 */
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, p;
    cin >> n >> p;

    for (int i = 1; i <= n; i++)
    {
        int x = p - 2;
        long long ans = 1;
        long long b = i;

        while (x)
        {
            if (x & 1)
            {
                ans *= b;
                ans %= p;
            }
            b *= b;
            b %= p;
            x >>= 1;
        }
        cout << ans % p << endl;
    }
}