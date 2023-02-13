#include <iostream>
#include <algorithm>
using namespace std;
int a[205];
int lbs(int l, int r, int t)
{
    while (l < r)
    {
        int m = l + ((r - l) >> 1);
        if (a[m] == t)
        {
            r = m;
        }
        else if (a[m] > t)
        {
            l = m + 1;
        }
        else if (a[m] < t)
        {
            r = m;
        }
    }
    return r;
}
int rbs(int l, int r, int t)
{
    while (l < r)
    {
        int m = l + ((r - l) >> 1);
        if (a[m] == t)
        {
            l = m + 1;
        }
        else if (a[m] > t)
        {
            l = m + 1;
        }
        else if (a[m] < t)
        {
            r = m;
        }
    }
    return r;
}
int main()
{
    int n, c;
    cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n, greater<int>());
    long long ans = 0;
    for (int i = 0; i < n && a[i] >= c; i++)
    {
        int ll = lbs(i + 1, n, a[i] - c);
        int rr = rbs(i + 1, n, a[i] - c);
        ans += (rr - ll);
    }
    cout << ans << endl;
}