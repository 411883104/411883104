/*
 * @Author       : Outsider
 * @Date         : 2023-05-21 18:13:16
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-05-21 19:28:55
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\other\sdut\subsum.cc
 */
#include <iostream>

using namespace std;

int a[100005];
int n, sum;

int ans = 0;
void dfs(int x, int s)
{
    if (s == sum)
    {
        ans++;
        return;
    }
    for (int i = x; i < n; i++)
    {
        dfs(i + 1, s + a[i]);
    }
}

int main()
{
    cin >> n >> sum;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}