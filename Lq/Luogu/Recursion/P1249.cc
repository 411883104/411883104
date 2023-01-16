/*
 * @Author: Outsider
 * @Date: 2023-01-16 14:22:26
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-16 15:40:06
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\Recursion\P1249.cc
 */
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
vector<int> ans;
vector<int> tem;
ll maxx = 0;

void dfs(int start, int cnt, int sum)
{
    if (cnt == sum)
    {
        ll num = 1;
        for (int i = 0; i < tem.size(); i++)
        {
            num *= tem[i];
        }
        if (maxx < num)
        {
            ans = tem;
            maxx = num;
        }
        return;
    }

    for (int i = start; i < 1000; i++)
    {
        if (cnt + i > sum)
        {
            return;
        }
        tem.push_back(i);
        dfs(i + 1, cnt + i, sum);
        tem.pop_back();
    }
}

int main()
{
    int n;
    cin >> n;
    dfs(1, 0, n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ' ';
    }
    cout << endl
         << maxx << endl;
}