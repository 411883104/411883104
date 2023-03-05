/*
 * @Author       : Outsider
 * @Date         : 2023-03-01 19:14:52
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-03-04 10:57:40
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\RD_ST_Heap\P2880-treearray.cc
 */
#include <iostream>
using namespace std;

int tt_max[10005];
int tt_min[10005];
int aa[10005];
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}
int n, t;
void add(int x, int v)
{
    for (int i = x; i <= n; i += (i & (-i)))
    {
        tt_max[i] = max(tt_max[i], v);
        tt_min[i] = min(tt_min[i], v);
    }
}

int query_max(int x, int y)
{
    if (y > x)
    {
        int k = (y & (-y));
        if (y - k + 1 >= x)
        {
            return max(tt_max[y], query_max(x, y - k));
        }
        else
        {
            return max(aa[y], query_max(x, y - 1));
        }
    }
    return aa[x];
}

int query_min(int x, int y)
{
    if (y > x)
    {
        int k = (y & (-y));
        if (y - k + 1 >= x)
        {
            return min(tt_min[y], query_min(x, y - k));
        }
        else
        {
            return min(aa[y], query_min(x, y - 1));
        }
    }
    return aa[x];
}

int main()
{
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
    {
        tt_min[i] = 0xfffffff;
    }

    for (int i = 1; i <= n; i++)
    {
        aa[i] = read();
        add(i, aa[i]);
    }
    int ll, rr;
    while (t--)
    {
        ll = read();
        rr = read();
        cout << query_max(ll, rr) - query_min(ll, rr) << endl;
    }
}