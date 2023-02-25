#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;
int n, m;
int nn[1005];
int mm[1005];
int mbs(int ll, int rr, int tt)
{
    while (ll <= rr)
    {
        int mid = ll + ((rr - ll) >> 1);
        if (nn[mid] == tt)
        {
            return 0;
        }
        else if (nn[mid] > tt)
        {
            rr = mid - 1;
        }
        else if (nn[mid] < tt)
        {
            ll = mid + 1;
        }
    }
    int lv = ll < n ? abs(nn[ll] - tt) : INT_MAX;
    int rv = rr >= 0 ? abs(nn[rr] - tt) : INT_MAX;
    return lv > rv ? rv : lv;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> nn[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> mm[i];
    }
    sort(nn, nn + n);
    long long ans = 0;
    for (int i = 0; i < m; i++)
    {
        ans += mbs(0, n - 1, mm[i]);
    }
    cout << ans << endl;
}