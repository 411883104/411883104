#include <iostream>
#include <cmath>
using namespace std;

long long a[100005];
int main()
{
    int n, t;
    cin >> t;

    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        long long rr;
        long long tol = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> rr;
            tol += abs(rr - a[i]);
            tol %= 2;
        }
        cout << tol % 2 << endl;
    }
}