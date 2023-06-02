/*
 * @Author       : Outsider
 * @Date         : 2023-05-03 21:21:35
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-05-16 10:03:50
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\Graph\P1983.cc
 */
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int n, m;

vector<int> G[1005];
int in[1005];
int qq[1005];
int dep[1005];
unordered_set<int> s;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x;
        vector<int> v;
        for (int j = 0; j < x; j++)
        {
            cin >> y;
            v.push_back(y);
            s.insert(y);
        }
        for (auto j = v[0]; j <= v[v.size() - 1]; j++)
        {
            if (s.find(j) == s.end())
            {
                for (auto x : v)
                {
                    G[x].push_back(j);
                    in[j]++;
                }
            }
        }
    }

    int hh = 0, tt = -1;

    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
        {
            qq[++tt] = i;
            dep[i] = 1;
        }
    }

    while (tt >= hh)
    {
        auto x = qq[hh++];
        for (auto n : G[x])
        {
            dep[n] = dep[x] + 1;
            if (--in[n] == 0)
            {
                qq[++tt] = n;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        ans = max(ans, dep[i]);
    }
    cout << ans << endl;
}