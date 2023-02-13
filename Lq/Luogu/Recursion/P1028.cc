#include <iostream>

using namespace std;
int vis[2005];
int ans = 1;
int dfs(int n)
{
    if (vis[n] != 0)
    {
        return vis[n];
    }
    else
    {
        int tol = 1;
        for (int i = n / 2; i > 0; i--)
        {
            tol += dfs(i);
        }
        return vis[n] = tol;
    }
}
int dp[2005];
int main()
{
    int n;
    cin >> n;
    vis[1] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1;
        for (int j = i / 2; j > 0; j--)
        {
            dp[i] += dp[j];
        }
    }
    cout << dp[n] << endl;
}