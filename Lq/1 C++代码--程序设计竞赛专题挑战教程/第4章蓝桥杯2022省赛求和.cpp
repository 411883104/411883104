#include<iostream>
using namespace std;
#define ll long long
const int N = 200000 + 100;
ll n, a[N], sum[N];
int main()
{
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", a + i);
        sum[i] = sum[i - 1] + a[i];
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++)
        ans += a[i] * (sum[n] - sum[i]);

    printf("%lld", ans);
    return 0;
}
