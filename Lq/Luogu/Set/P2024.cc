#include <iostream>

using namespace std;

int s[300005];

int find(int x)
{
    if (s[x] == x)
    {
        return x;
    }
    return s[x] = find(s[x]);
}

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= 3 * n; i++)
    {
        s[i] = i;
    }
    int op, x, y;
    int ans = 0;
    while (k--)
    {
        cin >> op >> x >> y;
        if (x > n || y > n)
        {
            ans++;
        }
        else if (op == 1)
        {
            if (find(x) == find(y + n) || find(y) == find(x + n))
            {
                ans++;
            }
            else
            {
                s[find(x)] = find(y);
                s[find(x + n)] = find(y + n);
                s[find(x + n + n)] = find(y + n + n);
            }
        }
        else if (op == 2)
        {
            if (find(x) == find(y + n) || find(y) == find(x))
            {
                ans++;
            }
            else
            {
                s[find(x + n)] = find(y);
                s[find(x + n + n)] = find(y + n);
                s[find(x)] = find(y + n + n);
            }
        }
    }
    cout << ans << endl;
}