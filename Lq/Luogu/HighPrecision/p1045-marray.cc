/*
 * @Author: Outsider
 * @Date: 2023-01-10 15:05:39
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-11 13:33:23
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\HighPrecision\p1045-marray.cc
 */
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
using namespace std;

int ans[1000000] = {0};
int base[1000000] = {0};
int right[1000000] = {0};
int mulans[1000000] = {0};

int mul(int lt[], int j, int rt[], int k)
{
    for (int i = 0; i < j + k; i++)
    {
        mulans[i] = 0;
    }
    for (int m = 0; m < j; m++)
    {
        for (int n = 0; n < k; n++)
        {
            mulans[m + n] += lt[m] * rt[n];
            mulans[m + n + 1] += mulans[m + n] / 10000;
            mulans[m + n] %= 10000;
        }
    }

    int idx = j + k - 2;
    if (mulans[idx + 1] != 0)
    {
        memcpy(lt, mulans, (idx + 2) * 4);
        return idx + 2;
    }
    else
    {
        while (mulans[idx] == 0 && --idx > 0)
            ;
        memcpy(lt, mulans, (idx + 1) * 4);
        return idx + 1;
    }
}

int sub(int lt[], int j, int rt[], int k)
{
    int m = 0;
    for (; m < j && m < k; m++)
    {
        if (lt[m] < 0 || lt[m] < rt[m])
        {
            lt[m + 1] -= 1;
            lt[m] += 10000;
        }
        lt[m] -= rt[m];
    }
    while (m < j)
    {
        if (lt[m++] < 0)
        {
            lt[m + 1] -= 1;
            lt[m] += 10000;
        }
    }

    if (lt[j - 1] != 0)
    {
        return j;
    }
    else
    {
        while (lt[--j] == 0 && j > 0)
            ;
        return j + 1;
    }
}

int main()
{
    int p;
    cin >> p;
    cout << int(p * log10(2)) + 1 << endl;

    ans[0] = 1;
    base[0] = 2;
    int i = 1;
    int j = 1;
    while (p)
    {
        if (p % 2 == 1)
            i = mul(ans, i, base, j);
        j = mul(base, j, base, j);
        p >>= 1;
    }
    int arr[2] = {1, 0};
    i = sub(ans, i, arr, 1);
    int idx = 124;
    int tol = 500;
    while (tol > 0)
    {
        int cnt = 12;

        if (tol % 4 == 0)
        {
            while (cnt)
            {
                cout << setw(4) << setfill('0') << ans[idx--];
                tol -= 4;
                cnt--;
            }
            cout << setw(2) << setfill('0') << ans[idx] / 100 << endl;
            tol -= 2;
        }
        else
        {
            cout << setw(2) << setfill('0') << ans[idx--] % 100;
            tol -= 2;
            while (cnt)
            {
                cout << setw(4) << setfill('0') << ans[idx--];
                tol -= 4;
                cnt--;
            }
            cout << endl;
        }
    }
}
