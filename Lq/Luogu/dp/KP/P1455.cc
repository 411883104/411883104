/*
 * @Author       : Outsider
 * @Date         : 2023-02-25 14:06:34
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-02-25 17:32:02
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\DP\KP\P1455.cc
 */
#include <iostream>
#include <vector>
using namespace std;
int dp[2][10005];
pair<int, int> item[10005];
int ss[10005];
int find(int x)
{
    if (ss[x] == x)
    {
        return x;
    }
    return ss[x] = find(ss[x]);
}
int rank[10005];
void merge(int x, int y)
{
    if (::rank[x] > ::rank[y])
    {
        ss[y] = x;
        item[x].second += item[y].second;
        item[x].first += item[y].first;
    }
    else if (::rank[y] > ::rank[x])
    {
        ss[x] = y;
        item[y].second += item[x].second;
        item[y].first += item[x].first;
    }
    else
    {
        ss[y] = x;
        item[x].second += item[y].second;
        item[x].first += item[y].first;
        ::rank[y] += 1;
    }
}
int main()
{
    int n, m, w;
    cin >> n >> m >> w;
    for (int i = 1; i <= n; ++i)
    {
        cin >> item[i].first >> item[i].second;
    }
    for (int i = 1; i <= n; i++)
    {
        ss[i] = i;
    }
    int x, y;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        int xx = find(x);
        int yy = find(y);
        if (xx != yy)
        {
            // ss[xx] = yy;
            merge(xx, yy);
        }
    }
    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        if (ss[i] == i)
        {
            v.push_back(i);
        }
    }
    for (size_t i = 1; i <= v.size(); i++)
    {
        for (int j = 1; j <= w; j++)
        {
            dp[i & 1][j] = dp[(i - 1) & 1][j];
            if (item[v[i - 1]].first <= j)
            {
                dp[i & 1][j] =
                    max(dp[(i - 1) & 1][j], dp[(i - 1) & 1][j - item[v[i - 1]].first] +
                                                item[v[i - 1]].second);
            }
        }
    }
    cout << dp[(v.size()) & 1][w] << endl;
}