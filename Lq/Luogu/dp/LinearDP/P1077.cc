#include <iostream>
#include <vector>
using namespace std;
int ans = 0;
int n, m;
int arr[105];
vector<pair<int, int>> v;
int pre[5055][5055];
void dfs(int sum, int start)
{
    if (sum == m)
    {
        ans++;
        return;
    }
    if (sum > m)
    {
        return;
    }
    if (start < n)
    {
        for (int j = 0; j <= arr[start]; j++)
        {
            dfs(sum + j, start + 1);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    dfs(0, 0);
    cout << ans << endl;
}