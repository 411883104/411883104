/*
 * @Author: Outsider
 * @Date: 2023-02-04 17:18:06
 * @LastEditors: Outsider
 * @LastEditTime: 2023-02-04 22:07:37
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\DP\LinearDP\P5858-search.cc
 */
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int a[5005];
long long n, w, s;

long long maxx = LONG_LONG_MIN;
void dfs(int start, long long tol, long long z)
{
    tol += (++z) * a[start];
    if (start == n)
    {
        maxx = max(maxx, tol);
        return;
    }
    for (int i = 0; i < min(z + 1, w); i++)
    {
        if (z - i <= s)
            dfs(start + 1, tol, i);
    }
}
int main()
{
    cin >> n >> w >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    dfs(0, 0, 0);
    cout << maxx << endl;
}