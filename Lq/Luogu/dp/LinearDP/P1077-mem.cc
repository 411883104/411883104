/*
 * @Author: Outsider
 * @Date: 2023-02-01 17:26:28
 * @LastEditors: Outsider
 * @LastEditTime: 2023-02-01 20:12:14
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\DP\LinearDP\P1077-mem.cc
 */
#include <iostream>
#include <vector>
using namespace std;
int ans = 0;
int n, m;
int arr[105];
int pre[5055][5055];
const int p = 1e6 + 7;
int dfs(int sum, int start)
{
    if (sum == m)
    {
        return 1;
    }
    if (sum > m)
    {
        return 0;
    }
    if (start < n)
    {
        if (pre[start][sum] != 0)
            return pre[start][sum];
        int tol = 0;
        for (int j = 0; j <= arr[start]; j++)
        {
            tol += dfs(sum + j, start + 1);
            tol %= p;
        }
        return pre[start][sum] = tol;
    }
    else
    {
        return 0;
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << dfs(0, 0) << endl;
}