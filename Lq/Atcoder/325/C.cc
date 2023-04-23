#include <iostream>
#include <algorithm>
using namespace std;
int a[500005];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int j = i + 1;
        for (; a[j] == a[i] && j < n; j++)
            ;
        ans += (j - i) >> 1;
        i = j - 1;
    }
    cout << ans << endl;
}