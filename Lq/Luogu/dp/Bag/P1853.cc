#include <iostream>
using namespace std;
const int c = 1000006;
int dp[c];
pair<int, int> it[15];

int main()
{
    int n, s, d;
    cin >> s >> n >> d;

    for (int i = 1; i <= d; i++)
    {
        cin >> it[i].first >> it[i].second;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            for (int k = it[j].first / 1000; k <= s / 1000; k++)
            {
                dp[k] = max(dp[k], dp[k - it[j].first/1000] + it[j].second);
            }
        }
        s += dp[s / 1000];
    }
    cout << s << endl;
}