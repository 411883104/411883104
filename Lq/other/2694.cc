#include <iostream>
using namespace std;

string s;
long long ans = 0;
void dfs(int idx, int aa, int bb)
{
    if (idx == s.size())
    {
        ans = max(ans, stoll(s));
        return;
    }
    int c = '9' - s[idx];
    char ch = s[idx];
    if (aa >= c)
    {
        s[idx] = '9';
        dfs(idx + 1, aa - c, bb);
        s[idx] = ch;
    }
    else
    {
        s[idx] += aa;
        dfs(idx + 1, 0, bb);
        s[idx] = ch;
    }
    if (10 - c <= bb)
    {
        s[idx] = '9';
        dfs(idx + 1, aa, bb - 10 + c);
        s[idx] = ch;
    }
}
int main()
{
    cin >> s;
    int a, b;
    cin >> a >> b;
    dfs(0, a, b);
    cout << ans << endl;
}