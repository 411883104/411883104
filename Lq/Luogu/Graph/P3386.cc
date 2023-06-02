#include <iostream>
#include <vector>
using namespace std;
const int c = 1005;
vector<int> G[c];
bool vis[c];
int mth[c];

int match(int x)
{
    for (auto e : G[x])
    {
        if (!vis[e])
        {
            vis[e] = true;
            if (mth[e] == 0 || match(mth[e]))
            {
                mth[e] = x;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int n, m, e;
    cin >> n >> m >> e;
    int u, v;
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v;
        G[u].push_back(v);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        fill(vis, vis + n + 1, false);
        ans += match(i);
    }

    cout<<ans<<endl;
    return 0;
}