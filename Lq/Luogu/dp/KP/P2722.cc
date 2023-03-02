#include <iostream>
using namespace std;

int dp[2][10005];

int main()
{
    int m, n;
    cin >> m >> n;
    int p, t;
    for (int i = 1; i <= n; i++)
    {
        cin >> p >> t;
        for (int j = 1; j <= m; j++)
        {
            dp[i & 1][j] = dp[(i - 1) & 1][j];
            if (j >= t) dp[i & 1][j] = max(dp[(i - 1) & 1][j], dp[i & 1][j - t] + p);
        }
    }
    cout << dp[n & 1][m] << endl;
}