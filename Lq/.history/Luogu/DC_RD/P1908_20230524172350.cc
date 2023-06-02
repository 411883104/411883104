#include <iostream>

using namespace std;

int a[500005];
int b[500005];

int divide(int l, int r)
{
    if (l < r)
    {
        int m = (l + ((r - l) >> 1));
        int ans = divide(l, m) + divide(m + 1, r);
        int ll = l, rr = m + 1, kk = 0;
        int tol = 0;
        while (ll <= m && rr <= r)
        {
            if (a[ll] > a[rr])
            {
                b[kk++] = a[rr++];
                tol++;
            }
            else
            {
                b[kk++] = a[ll++];
            }
        }
        while (ll <= m)
        {
            b[kk++] = a[ll++];
        }
        while (rr <= r)
        {
            b[kk++] = a[rr++];
        }
        ll = l;
        for (int i = 0; i < kk; i++)
        {
            a[ll++] = b[kk];
        }
        return tol;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    cout << divide(0, n - 1) << endl;
    return 0;
}