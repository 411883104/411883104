#include <iostream>
using namespace std;
const int m = 10005;
int v, n, c;
int dp[m];
int main()
{
    cin >> v >> n >> c;
    int x, y;

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        for (int j = c; j >= y; j--)
        {
            dp[j] = max(dp[j], dp[j - y] + x);
        }
    }
    for (int i = 0; i <= c; i++)
    {
        if (dp[i] >= v)
        {
            cout << c - i << endl;
            return 0;
        }
    }
    cout << "Impossible" << endl;
    return 0;
}