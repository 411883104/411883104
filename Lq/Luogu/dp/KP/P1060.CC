#include <iostream>

using namespace std;
int dp[35][30005];
int main()
{
    int n, m;
    cin >> n >> m;
    int v, p;
    for (int i = 1; i <= m; i++)
    {
        cin >> v >> p;
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (v <= j)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v] + v * p);
            }
        }
    }
    cout << dp[m][n] << endl;
}