#include <iostream>
using namespace std;
string dp[1050];
string add(string left, string right)
{
    string ans;
    int ov = 0;
    int i = 0;
    for (; i < (left.size(), right.size()); i++)
    {
        int tol = (left[i] - 48 + right[i] - 48 + ov);
        ov = tol / 10;
        ans.push_back((tol % 10) + 48);
    }
    while (i < left.size())
    {
        int tol = (left[i++] - 48 + ov);
        ov = tol / 10;
        ans.push_back((tol % 10) + 48);
    }
    while (i < right.size())
    {
        int tol = (right[i++] - 48 + ov);
        ov = tol / 10;
        ans.push_back((tol % 10) + 48);
    }
    if (ov == 1)
    {
        ans.push_back(ov + 48);
    }
    return ans;
}
int main()
{
    int n, m;
    cin >> n >> m;
    dp[n] = "1";
    dp[n - 1] = "0";
    for (int i = n + 1; i <= m; i++)
    {
        dp[i] = add(dp[i - 1], dp[i - 2]);
    }
    cout << string(dp[m].rbegin(), dp[m].rend()) << endl;
}