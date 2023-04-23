/*
 * @Author       : Outsider
 * @Date         : 2023-04-11 17:44:52
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-04-13 09:15:31
 * @Description  : In User Settings Edit
 * @FilePath     : \Luogu\Emulation\P1786.cc
 */
#include <iostream>
#include <algorithm>
using namespace std;

struct st
{
    int idx;
    string a, b;
    int c, d, e;
};

st a[200];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        a[i].idx = i;
        cin >> a[i].a >> a[i].b >> a[i].c >> a[i].d;
        if (a[i].b == "BangZhu")
        {
            a[i].e = 1;
        }
        else if (a[i].b == "FuBangZhu")
        {
            a[i].e = 2;
        }
        else if (a[i].b == "Hufa")
        {
            a[i].e = 3;
        }
        else if (a[i].b == "Zhanglao")
        {
            a[i].e = 4;
        }
        else if (a[i].b == "TangZhu")
        {
            a[i].e = 5;
        }
        else if (a[i].b == "JingYing")
        {
            a[i].e = 6;
        }
        else if (a[i].b == "BangZhong")
        {
            a[i].e = 7;
        }
    }

    int i = 0;
    for (; i < 3; i++)
    {
        if (a[i].b == "BangZhu" || a[i].b == "FuBangZhu")
        {
            cout << a[i].a << " " << a[i].b << " " << a[i].d << endl;
        }
    }
    if (i >= n)
    {
        return 0;
    }

    sort(a + 3, a + n, [](st &a, st &b) -> bool {
        if (a.c != b.c) return a.c > b.c;
        return a.idx < b.idx;
    });

    sort(a + 3, a + 5 > a + n ? a + n : a + 5, [](st &a, st &b) -> bool {
        if (a.d != b.d) return a.d > b.d;
        return a.idx < b.idx;
    });

    for (; i < n && i < 5; i++)
    {
        cout << a[i].a << " HuFa " << a[i].d << endl;
    }
    if (i >= n)
    {
        return 0;
    }
    sort(a + 5, a + 9 > a + n ? a + n : a + 9, [](st &a, st &b) -> bool {
        if (a.d != b.d) return a.d > b.d;
        return a.idx < b.idx;
    });
    for (; i < n && i < 9; i++)
    {
        cout << a[i].a << " ZhangLao " << a[i].d << endl;
    }
    if (i >= n)
    {
        return 0;
    }
    sort(a + 9, a + 16 > a + n ? a + n : a + 16, [](st &a, st &b) -> bool {
        if (a.d != b.d) return a.d > b.d;
        return a.idx < b.idx;
    });
    for (; i < n && i < 16; i++)
    {
        cout << a[i].a << " TangZhu " << a[i].d << endl;
    }
    if (i >= n)
    {
        return 0;
    }
    sort(a + 16, a + 41 > a + n ? a + n : a + 41, [](st &a, st &b) -> bool {
        if (a.d != b.d) return a.d > b.d;
        return a.idx < b.idx;
    });
    for (; i < n && i < 41; i++)
    {
        cout << a[i].a << " JingYing " << a[i].d << endl;
    }
    if (i >= n)
    {
        return 0;
    }
    sort(a + 41, a + n, [](st &a, st &b) -> bool {
        if (a.d != b.d) return a.d > b.d;
        return a.idx < b.idx;
    });
    for (; i < n; i++)
    {
        cout << a[i].a << " BangZhong " << a[i].d << endl;
    }
    return 0;
}
