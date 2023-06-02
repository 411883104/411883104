/*
 * @Author       : Outsider
 * @Date         : 2023-04-01 11:21:24
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-04-01 12:16:23
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\other\2692.cc
 */
#include <iostream>

using namespace std;

long long prime[10005];
long long vis[10000005];

int main()
{
    long long n;
    cin >> n;
    long long cnt = 0;

    for (long long i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cnt++;
        }
    }
    if (cnt == 0)
    {
        cout << 1 << endl;
        return 0;
    }

    cnt = 0;
    for (long long i = 2; i <= 10000000; i++)
    {
        if (vis[i] == 0)
        {
            prime[cnt++] = i;
        }
        for (long long j = 0; j < cnt && prime[j] * i <= 10000000; j++)
        {
            vis[prime[j] * i] = 1;
            if (i % prime[j] == 0)
            {
                break;
            }
        }
    }

    long long ans = 0;
    for (long long j = 0; j < cnt && prime[j] * prime[j] <= n && n > 1; j++)
    {
        if (n % prime[j] == 0)
        {
            ans++;
            while (n % prime[j] == 0)
            {
                n /= prime[j];
            }
        }
    }
    if (n > 1)
    {
        ans++;
    }
    cout << ans << endl;
    return 0;
}