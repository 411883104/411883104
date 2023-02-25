#include <iostream>

using namespace std;
int dp[5000][15005];
int main()
{
    int n, m;
    cin >> n >> m;
    int w, v;
    for (int i = 1; i <= n; i++)
    {
        cin >> w >> v;
        for (int j = 0; j <= m; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (v <= j)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - v] + w);
            }
        }
    }
    cout << dp[n][m] << endl;
}