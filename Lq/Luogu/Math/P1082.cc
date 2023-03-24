#include <iostream>
using namespace std;

int a, b;

void extGcd(int a, int b, int& x, int& y)
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
    cin >> a >> b;
    int x, y;
    extGcd(a, b, x, y);
    cout << (x % b + b) % b << endl;
}