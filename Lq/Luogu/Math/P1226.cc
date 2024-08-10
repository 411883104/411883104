#include <iostream>
using namespace std;

int main()
{
    long long a, b, p;
    cin >> a >> b >> p;
    cout << a << "^" << b << " mod " << p << "=";

    long long ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = ((ans % p) * (a % p)) % p;
        }
        a = ((a % p) * (a % p)) % p;
        b >>= 1;
    }
    cout << ans << endl;
    return 0;
}