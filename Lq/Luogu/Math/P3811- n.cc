/*
 * @Author       : Outsider
 * @Date         : 2023-03-18 16:40:20
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-03-20 19:46:15
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\Math\P3811- n.cc
 */
#include <iostream>

using namespace std;

long long inv[3000005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n, p;
    scanf("%lld%lld", &n, &p);

    inv[1] = 1;
    printf("%lld\n", inv[1]);
    for (int i = 2; i <= n; i++)
    {
        inv[i] = ((-p / i * inv[p % i]) % p + p) % p;
        printf("%lld\n", inv[i]);
    }
}