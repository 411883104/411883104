#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int c = 1005;
vector<int> G[c];
int s[c];
int tol[c];
bool check[c];
void dfs(int n)
{
    check[n] = true;
    tol[n]++;
    for (auto e : G[n])
    {
        if (!check[e])
        {
            dfs(e);
        }
    }
}

int main()
{
    int k, n, m;

    cin >> k >> n >> m;
    for (int i = 1; i <= k; i++)
    {
        cin >> s[i];
    }
    int u, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        G[v].push_back(u);
    }

    for (int i = 1; i <= k; i++)
    {
        fill(check, check + 2 + n, false);
        dfs(s[i]);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (tol[i] == k)
        {
            ans++;
        }
    }
    cout << ans << endl;
}