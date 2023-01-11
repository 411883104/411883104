/*
 * @Author: Outsider
 * @Date: 2023-01-10 15:05:39
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-11 17:07:38
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\HighPrecision\p1045-8marray.cc
 */
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
using namespace std;

long long ans[1000000] = {0};
long long base[1000000] = {0};
long long right[1000000] = {0};
long long mulans[1000000] = {0};

int mul(long long lt[], int j, long long rt[], int k)
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
            mulans[m + n + 1] += mulans[m + n] / 100000000;
            mulans[m + n] %= 100000000;
        }
    }

    int idx = j + k - 2;
    if (mulans[idx + 1] != 0)
    {
        memcpy(lt, mulans, (idx + 2) * 8);
        return idx + 2;
    }
    else
    {
        while (mulans[idx] == 0 && --idx > 0)
            ;
        memcpy(lt, mulans, (idx + 1) * 8);
        return idx + 1;
    }
}

int sub(long long lt[], int j, long long rt[], int k)
{
    int m = 0;
    for (; m < j && m < k; m++)
    {
        if (lt[m] < 0 || lt[m] < rt[m])
        {
            lt[m + 1] -= 1;
            lt[m] += 100000000;
        }
        lt[m] -= rt[m];
    }
    while (m < j)
    {
        if (lt[m++] < 0)
        {
            lt[m + 1] -= 1;
            lt[m] += 100000000;
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
    int i = 505;
    int j = 505;
    while (p)
    {
        if (p % 2 == 1)
            mul(ans, i, base, j);
        mul(base, j, base, j);
        p >>= 1;
    }
    long long arr[2] = {1, 0};
    i = sub(ans, i, arr, 1);
    int idx = 62;
    int tol = 500;
    while (tol > 0)
    {
        int cnt = 12;

        switch (tol % 8)
        {
        case 4:
        {
            cout << setw(4) << setfill('0') << ans[idx--] % 10000;
            cout << setw(8) << setfill('0') << ans[idx--];
            cout << setw(8) << setfill('0') << ans[idx--];
            cout << setw(8) << setfill('0') << ans[idx--];
            cout << setw(8) << setfill('0') << ans[idx--];
            cout << setw(8) << setfill('0') << ans[idx--];
            cout << setw(6) << setfill('0') << ans[idx] / 100;
        }
        break;
        case 2:
        {
            cout << setw(2) << setfill('0') << ans[idx--] % 100;
            cout << setw(8) << setfill('0') << ans[idx--];
            cout << setw(8) << setfill('0') << ans[idx--];
            cout << setw(8) << setfill('0') << ans[idx--];
            cout << setw(8) << setfill('0') << ans[idx--];
            cout << setw(8) << setfill('0') << ans[idx--];
            cout << setw(8) << setfill('0') << ans[idx--];
        }
        break;
        case 0:
        {
            cout << setw(8) << setfill('0') << ans[idx--];
            cout << setw(8) << setfill('0') << ans[idx--];
            cout << setw(8) << setfill('0') << ans[idx--];
            cout << setw(8) << setfill('0') << ans[idx--];
            cout << setw(8) << setfill('0') << ans[idx--];
            cout << setw(8) << setfill('0') << ans[idx--];
            cout << setw(2) << setfill('0') << ans[idx] / 1000000;
        }
        break;
        case 6:
        {
            cout << setw(6) << setfill('0') << ans[idx--] % 1000000;
            cout << setw(8) << setfill('0') << ans[idx--];
            cout << setw(8) << setfill('0') << ans[idx--];
            cout << setw(8) << setfill('0') << ans[idx--];
            cout << setw(8) << setfill('0') << ans[idx--];
            cout << setw(8) << setfill('0') << ans[idx--];
            cout << setw(4) << setfill('0') << ans[idx] / 10000;
        }
        break;

        default:
            break;
        }
        cout << endl;
        tol -= 50;
    }
}
