#include <iostream>
using namespace std;

int dp[1005];
int n;

bool prime(int x)
{
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cin >> n;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for (int i = 4; i <= n; i++)
    {
        int ans = 0;
        for (int j = 1; j + j <= i; j++)
        {
            ans += dp[j] * dp[i - j];
        }
        dp[i] = ans;
    }
    cout << dp[n] << endl;
    return 0;
}