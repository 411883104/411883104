#include <iostream>

using namespace std;
typedef long long ll;
int main()
{
    string s;
    ll n;
    cin >> s >> n;
    int len = s.size();
    if (len == 1)
    {
        cout << s << endl;
        return 0;
    }
    while (n > len)
    {
        ll t = len;
        while (t < n)
            t <<= 1;
        t >>= 1;
        n -= (t + 1);
        if (n == 0)
            n = t;
    }
    cout << s[n - 1] << endl;
}