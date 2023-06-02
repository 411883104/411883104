/*
 * @Author       : Outsider
 * @Date         : 2023-05-23 21:55:11
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-05-27 17:21:51
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\Math\P1835.cc
 */
#include <iostream>

int prime[500005];
int flag[500005];
int cnt[2000005];
int tol = 0;
const int N = 500005;
using namespace std;

int main()
{
    for (int i = 2; i < N; i++)
    {
        if (flag[i] == 0)
        {
            prime[tol++] = i;
        }
        for (int j = 0; j < tol && prime[j] * i < N; j++)
        {
            flag[i * prime[j]] = 1;
            if (i % prime[j] == 0)
            {
                break;
            }
        }
    }
    // for (int i = 0; i < tol; i++)
    // {
    //     cout << prime[i] << endl;
    // }
    int l, r;
    cin >> l >> r;
    if (l == r)
    {
    }
    for (int i = 0; i < tol && prime[i] * prime[i] <= r; i++)
    {
        for (long long j = max(2 * prime[i], l / prime[i] * prime[i]); j <= r;
             j += prime[i])
        {
            if (j - l >= 0) cnt[j - l] = 1;
        }
    }
    int ans = 0;
    for (int i = 0; i <= r - l; i++)
    {
        if (cnt[i] == 0)
        {
            ans++;
        }
    }
    if (l == 1)
    {
        ans--;
    }
    cout << ans << endl;
    return 0;
}