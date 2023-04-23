#include <iostream>
#include <algorithm>
using namespace std;
const int c = 1005;
pair<int, int> ff[c];
long long ss[c];
long long vv[c];
int dp[1000005];
int n, p, s;
bool check(int x)
{
    if (vv[x] >= p && ss[x] <= s)
    {
        return true;
    }
    return false;
}
int main()
{
    cin >> n >> p >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> ff[i].first >> ff[i].second;
    }

    sort(ff + 1, ff + n + 1,
         [](pair<int, int>& a, pair<int, int>& b) -> bool { return a.first < b.first;
         });

    for (int i = 1; i <= n; i++)
    {
        for (int j = s; j >= ff[i].first; j--)
        {
            dp[j] = max(dp[j], dp[j - ff[i].first] + ff[i].second);
        }
        if (dp[s] >= p)
        {
            cout << ff[i].first << endl;
            return 0;
        }
    }

    if (dp[s] < p)
    {
        cout << "No Solution!" << endl;
    }
    else
    {
        cout << dp[s] << endl;
    }
}