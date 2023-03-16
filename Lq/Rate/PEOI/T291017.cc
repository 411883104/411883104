#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b;
        cin >> a >> b;
        long long ans = 0;
        for (long long i = 1; i <= a; i++)
        {
            for (long long j = 1; j <= b; j++)
            {
                ans += (i ^ j);
                ans %= 998244353;
            }
        }
        cout << ans << endl;
    }
}