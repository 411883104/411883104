/*
 * @Author       : Outsider
 * @Date         : 2023-02-26 11:57:04
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-02-26 15:27:54
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\DP\KP\P2170.cc
 */
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int ss[20050];
int rr[20050];
int tol[20050];

int find(int x)
{
    if (ss[x] == x)
    {
        return x;
    }
    return ss[x] = find(ss[x]);
}
void merge(int x, int y)
{
    if (rr[x] < rr[y])
    {
        ss[x] = y;
        tol[y] += tol[x];
    }
    else if (rr[x] > rr[y])
    {
        ss[y] = x;
        tol[x] += tol[y];
    }
    else
    {
        ss[x] = y;
        tol[y] += tol[x];
        rr[y]++;
    }
}
int dp[40050];
int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
    {
        ss[i] = i;
        tol[i] = 1;
    }

    int x, y;
    for (int i = 0; i < k; i++)
    {
        cin >> x >> y;
        int xx = find(x);
        int yy = find(y);
        if (xx != yy)
        {
            merge(xx, yy);
        }
    }
    vector<int> v;

    int off = 0;
    for (int i = 1; i <= n; i++)
    {
        if (ss[i] == i)
        {
            v.push_back(i);
            off = max(off, tol[i]);
        }
    }

    for (size_t i = 1; i <= v.size(); i++)
    {
        for (int j = m + off; j >= tol[v[i - 1]]; j--)
        {
            dp[j] = max(dp[j], dp[j - tol[v[i - 1]]] + tol[v[i - 1]]);
        }
    }
    int maxx = dp[m];
    for (int i = m + 1; i <= m + off; i++)
    {
        if (dp[i] > dp[m])
        {
            maxx = dp[i];
            break;
        }
    }
    if (abs(m - dp[m]) <= abs(maxx - m))
    {
        cout << dp[m] << endl;
        return 0;
    }
    cout << maxx << endl;
    return 0;
}