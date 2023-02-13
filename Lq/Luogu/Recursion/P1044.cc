/*
 * @Author: Outsider
 * @Date: 2023-02-05 13:34:15
 * @LastEditors: Outsider
 * @LastEditTime: 2023-02-05 14:38:22
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\Recursion\P1044.cc
 */
#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int vis[20][20];
int ans = 0;
int n;

int dfs(int in, int out)
{
    int tol = 0;
    if (vis[in][out] != 0)
    {
        return vis[in][out];
    }
    else
    {
        if (in > 0)
        {
            tol += dfs(in - 1, out + 1);
        }
        if (out > 0)
        {
            tol += dfs(in, out - 1);
        }
    }
    return vis[in][out] = tol;
}

int main()
{
    cin >> n;
    vis[0][0] = 1;
    cout << dfs(n, 0) << endl;
}