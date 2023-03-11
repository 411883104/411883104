/*
 * @Author       : Outsider
 * @Date         : 2023-03-06 16:49:25
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-03-06 17:45:51
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\Graph\P1113.cc
 */
#include <iostream>
#include <vector>
using namespace std;

const int c = 1005;

vector<int> G[c];
int in[c];
int out[c];
int t[c];
int qq[c];
int ans[c];
int main()
{
    int n;
    cin >> n;
    int x, y;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        t[x] = y;
        while (cin >> y && y)
        {
            G[y].push_back(x);
            out[y]++;
            in[x]++;
        }
    }

    int hh = 0, tt = -1;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
        {
            qq[++tt] = i;
            ans[i] = t[i];
        }
    }
    while (tt >= hh)
    {
        int n = qq[hh++];
        for (auto e : G[n])
        {
            in[e]--;
            ans[e] = max(t[e] + ans[n], ans[e]);
            if (in[e] == 0)
            {
                qq[++tt] = e;
            }
        }
    }

    int maxx = 0;
    for (int i = 1; i <= n; i++)
    {
        maxx = max(ans[i], maxx);
    }

    cout << maxx << endl;
}