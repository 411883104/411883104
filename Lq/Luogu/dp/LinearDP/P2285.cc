#include <iostream>
using namespace std;

const int c = 10005;
int dp[c];

struct status
{
    int t, x, y;
};

status it[c];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> it[i].t >> it[i].x >> it[i].y;
    }
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (abs(it[i].x - it[j].x) + abs(it[i].y - it[j].y) <= it[i].t - it[j].t)
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}