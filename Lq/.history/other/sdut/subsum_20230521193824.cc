/*
 * @Author       : Outsider
 * @Date         : 2023-05-21 18:13:16
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-05-21 19:38:23
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\other\sdut\subsum.cc
 */
#include <iostream>
#include <vector>

using namespace std;

int a[100005];
int n, sum;

int ans = 0;
vector<int> res;
bool f = false;

void dfs(int x, int s)
{
    if (f)
    {
        return;
    }
    if (s == sum)
    {
        ans++;
        for (auto &n : res)
        {
            cout << n << " ";
        }
        cout << endl;
        return;
    }
    for (int i = x; i < n; i++)
    {
        res.push_back(a[i]);
        dfs(i + 1, s + a[i]);
        res.pop_back();
        if (f)
        {
            return;
        }
    }
}

int main()
{
    cin >> n >> sum;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    dfs(0, 0);
    cout << ans << endl;

    return 0;
}