/*
 * @Author       : Outsider
 * @Date         : 2023-05-06 21:35:15
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-05-07 17:53:17
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\LST\P5057.cc
 */
#include <iostream>
using namespace std;

const int c = 100005;
int tt[c];
int n;

int lowbit(int x) { return x & (-x); }

void modify(int x, int val)
{
    for (int i = x; i <= n; i += lowbit(i))
    {
        tt[i] += val;
    }
}

int query(int x)
{
    int sum = 0;
    for (int i = x; i > 0; i -= lowbit(i))
    {
        sum += tt[i];
    }
    return sum;
}

int main()
{
    int m;
    cin >> n >> m;
    int op, x, y;
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> x;
    //     modify(i, x);
    // }
    while (m--)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> x >> y;
            modify(x, 1);
            modify(y + 1, -1);
        }
        else if (op == 2)
        {
            cin >> x;
            cout << query(x) % 2 << endl;
        }
    }
    return 0;
}