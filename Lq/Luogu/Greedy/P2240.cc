#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

struct st
{
    double w, v;
    double s;
};

st a[205];

int main()
{
    int n, t;
    cin >> n >> t;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].w >> a[i].v;
        a[i].s = a[i].v / a[i].w;
    }
    std::sort(a, a + n, [](st &lhs, st &rhs) -> bool {
        if (lhs.s < rhs.s)
        {
            return false;
        }
        return true;
    });
    int idx = 0;
    double ans = 0;
    while (t && idx < n)
    {
        if (a[idx].w < t)
        {
            t -= a[idx].w;
            ans += a[idx].v;
        }
        else
        {
            ans += a[idx].s * t;
            t = 0;
        }
        idx++;
    }
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}