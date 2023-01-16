/*
 * @Author: Outsider
 * @Date: 2023-01-16 09:09:00
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-16 09:50:34
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\Recursion\P1464.cc
 */
#include <iostream>

using namespace std;

typedef long long ll;

ll ans[25][25][25] = {0};

ll w(ll a, ll b, ll c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return 1;
    }
    if (a > 20 || b > 20 || c > 20)
    {
        if (ans[20][20][20] != 0)
            return ans[20][20][20];
        ans[20][20][20] = w(20, 20, 20);
        return ans[20][20][20];
    }
    if (a < b && b < c)
    {
        if (ans[a][b][c] != 0)
            return ans[a][b][c];
        ans[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
        return ans[a][b][c];
    }
    if (ans[a][b][c] != 0)
        return ans[a][b][c];
    ans[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) -
                   w(a - 1, b - 1, c - 1);
    return ans[a][b][c];
}

int main()
{
    int a, b, c;
    while ((cin >> a >> b >> c) && !(a == -1 && b == -1 && c == -1))
    {
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl;
    }
}