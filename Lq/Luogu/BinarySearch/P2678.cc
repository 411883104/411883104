#include <iostream>
using namespace std;

int l, n, m;
int a[50005];
bool check(int x)
{
    int tol = 0;
    int cnt = 0;
    for (int i = 0; i <= n; i++)
    {
        if (a[i] - cnt < x)
        {
            tol++;
        }
        else
        {
            cnt = a[i];
        }
    }
    return tol <= m;
}
int main()
{
    cin >> l >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    a[n] = l;
    int ll = 0, rr = l + 1;
    while (ll < rr)
    {
        int mm = ll + ((rr - ll) >> 1);
        if (check(mm))
        {
            ll = mm + 1;
        }
        else
        {
            rr = mm;
        }
    }
    cout << ll - 1 << endl;
}