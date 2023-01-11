/*
 * @Author: Outsider
 * @Date: 2023-01-03 21:06:54
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-03 22:32:27
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\p2392.cc
 */
#include <iostream>
#include <algorithm>

using namespace std;

int arr[25];
int minn;
void dfs(int r, int c, int cnt, int left, int right)
{
    if (r < cnt)
        return;
    if (r == c)
    {
        minn = min(minn, max(left, right));
        return;
    }
    for (int i = cnt; i < c; i++)
    {
        dfs(r + 1, c, i + 1, left + arr[i], right);
        dfs(r + 1, c, i + 1, left, right + arr[i]);
    }
}

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = 0;

    for (int i = 0; i < a; i++)
    {
        cin >> arr[i];
    }
    minn = 0xfffff;
    dfs(0, a, 0, 0, 0);
    ans += minn;

    for (int i = 0; i < b; i++)
    {
        cin >> arr[i];
    }
    minn = 0xfffff;
    dfs(0, b, 0, 0, 0);
    ans += minn;

    for (int i = 0; i < c; i++)
    {
        cin >> arr[i];
    }
    minn = 0xfffff;
    dfs(0, c, 0, 0, 0);
    ans += minn;

    for (int i = 0; i < d; i++)
    {
        cin >> arr[i];
    }
    minn = 0xfffff;
    dfs(0, d, 0, 0, 0);
    ans += minn;

    cout << ans << endl;
}