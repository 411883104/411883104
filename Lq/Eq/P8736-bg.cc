#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;
const int c = 1005;
string dp[c];
int pos[c];
vector<string> ss;

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
    int len = 0;
    for (int i = 0; i < ss.size(); i++)
    {
        int ll = 0, rr = len;
        while (ll < rr)
        {
            int mm = ll + ((rr - ll) >> 1);
            if (dp[mm] == ss[i])
            {
                ll = rr = mm;
            }
            else if (dp[mm] < ss[i])
            {
                ll = mm + 1;
            }
            else if (dp[mm] > ss[i])
            {
                rr = mm;
            }
        }
        dp[ll] = ss[i];
        pos[i] = ll;
        if (ll == len) len++;
    }

    if (len == 0)
    {
        return 0;
    }
    len--;

    stack<string> ans;

    for (int i = ss.size() - 1; i >= 0; i--)
    {
        if (pos[i] == len)
        {
            ans.push(ss[i]);
            len--;
        }
    }
    while (!ans.empty())
    {
        cout << ans.top();
        ans.pop();
    }
    cout << endl;
    return 0;
}