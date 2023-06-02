#include <iostream>
#include <bitset>
using namespace std;
const int c = 100005;
int s[c];
char t[c];
int find(int x)
{
    if (x == s[x])
    {
        return x;
    }
    return s[x] = find(s[x]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
        s[i] = i;
    }
    int x, y;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        int xx = find(x);
        int yy = find(y);
        if (t[x] == t[y])
        {
            s[xx] = yy;
        }
    }
    char ch;
    string ans;
    while (m--)
    {
        cin >> x >> y >> ch;
        int xx = find(x);
        int yy = find(y);
        if (xx == yy)
        {
            ans.push_back((t[xx] == ch) + 48);
        }
        else
        {
            ans.push_back('1');
        }
    }
    cout << ans << endl;
    return 0;
}