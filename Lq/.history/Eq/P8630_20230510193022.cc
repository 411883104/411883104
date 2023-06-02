#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<string, int> m;
int main()
{
    string s, r;
    cin >> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> r;
        sort(r.begin(), r.end());
        m[r]++;
    }

    int ans = 0;
    for (int i = 0; i < s.size() - 8; i++)
    {
        r = s.substr(i, 8);
        sort(r.begin(), r.end());
        ans += m[r];
    }
    cou
}