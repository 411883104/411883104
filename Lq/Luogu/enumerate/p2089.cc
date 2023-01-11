/*
 * @Author: Outsider
 * @Date: 2023-01-02 14:50:02
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-02 15:09:47
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\p2089.cc
 */
#include <iostream>
#include <vector>

using namespace std;
int n;
vector<vector<int>> res;
vector<int> v;
int ans = 0;
void dfs(int sum)
{
    if (v.size() == 10)
    {
        if (sum == n)
        {
            res.push_back(v);
            ans++;
        }
        return;
    }
    for (int i = 1; i <= 3; i++)
    {
        v.push_back(i);
        dfs(sum + i);
        v.pop_back();
    }
}

int main()
{
    cin >> n;
    dfs(0);
    cout << ans << endl;
    for (auto v : res)
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
}