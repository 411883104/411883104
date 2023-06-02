#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int c = 1005;
int dp[c] = {0};
int pre[c] = {0};
vector<string> ss;

void print(int s)
{
    if (s == -1)
    {
        return;
    }
    print(pre[s]);
    cout << ss[s];
}
int main()
{
    string s;
    cin >> s;
    int b = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            if (i != 0)
            {
                ss.push_back(s.substr(b, i - b));
            }
            b = i;
        }
    }
    ss.push_back(s.substr(b, s.size() - b));
    int ans = 0;
    int last = 0;
    for (int i = 0; i < ss.size(); i++)
    {
        dp[i] = 1;
        pre[i] = -1;
        for (int j = 0; j < i; j++)
        {
            if (ss[i] > ss[j])
            {
                if (dp[i] <= dp[j] + 1)
                {
                    pre[i] = j;
                    dp[i] = dp[j] + 1;
                }
            }
        }
        if (ans <= dp[i])
        {
            ans = dp[i];
            last = i;
        }
    }

    print(last);
    return 0;
}