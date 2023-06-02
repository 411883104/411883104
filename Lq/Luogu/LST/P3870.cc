/*
 * @Author       : Outsider
 * @Date         : 2023-05-28 14:09:16
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-05-28 14:20:11
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\LST\P3870.cc
 */
#include <iostream>
using namespace std;

const int c = 1005;
int aa[c];
int n, m;

int lowbit(int x) { return x & (-x); }

void modify(int x, int val)
{
    for (int i = x; i <= n; i += lowbit(i))
    {
        aa[i] += val;
    }
}

int query(int x)
{
    int sum = 0;
    for (int i = x; i > 0; i -= lowbit(i))
    {
        sum += aa[i];
    }
    return sum;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0)
        {
            modify(b, 1);
            modify(c + 1, -1);
        }
        else
        {
            int ans = 0;
            for (int i = b; i <= c; i++)
            {
                if (query(i) % 2 == 1)
                {
                    ans++;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}