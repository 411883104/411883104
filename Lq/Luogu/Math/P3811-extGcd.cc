#include <iostream>

using namespace std;

void extGcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return;
    }
    else
    {
        extGcd(b, a % b, x, y);
        int t = x;
        x = y;
        y = t - a / b * y;
        return;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, p;
    cin >> n >> p;
    int x, y;
    for (int i = 1; i <= n; i++)
    {
        extGcd(i, p, x, y);
        cout << (x % p + p) % p << endl;
    }
}