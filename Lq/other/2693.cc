#include <iostream>
using namespace std;

pair<int, int> a[200005];

long long n, m;
bool check(int x)
{
    long long tol = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].first < x)
        {
            if (a[i].second < x - a[i].first)
            {
                return false;
            }
            tol += x - a[i].first;
        }
    }
    if (tol <= m)
    {
        return true;
    }
    return false;
}

int main()
{
    cin >> n >> m;
    int ll = 0xfffffff, rr = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        ll = min(ll, a[i].first);
        rr = max(rr, a[i].first);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].second;
    }
    rr += 1;
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