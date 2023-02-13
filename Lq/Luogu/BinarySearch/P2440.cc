#include <iostream>
using namespace std;
int a[1005];
int n, k;
bool check(int x)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (a[i] / x);
    }
    if (sum >= k)
        return true;
    return false;
}

int main()
{
    cin >> n >> k;
    int maxx = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        maxx = max(maxx, a[i]);
    }
    int l = 1, r = maxx;
    while (l < r)
    {
        int m = l + ((r - l) >> 1);
        if (check(m))
        {
            l = m + 1;
        }
        else
        {
            r = m;
        }
    }
    cout << l - 1 << endl;
}