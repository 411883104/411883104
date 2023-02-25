#include <iostream>
using namespace std;

int a[1005];
int b[1005];
int l, n, k;

bool check(int x)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += ((b[i] - 1) / x);
    }
    if (sum <= k)
        return true;
    return false;
}

int main()
{
    cin >> l >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i] - a[i - 1];
    }
    int ll = 1, rr = l;
    while (ll < rr)
    {
        int mm = ll + ((rr - ll) >> 1);
        if (check(mm))
        {
            rr = mm;
        }
        else
        {
            ll = mm + 1;
        }
    }
    cout << ll << endl;
}