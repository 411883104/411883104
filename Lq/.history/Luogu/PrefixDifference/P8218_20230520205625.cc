#include <iostream>
using namespace std;

const int c = 100005;

int a[c];

int main()
{
    int n, m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    cin >> m;
    int ll, rr;
    while (m--)
    {
        cin >> ll >> rr;
        cout << a[rr] - a[ll - 1] << endl;
    }
    return 0;
}