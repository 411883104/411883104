/*
 * @Author: Outsider
 * @Date: 2023-01-03 16:44:48
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-03 19:58:13
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\p1217.cc
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numlg(int n)
{
    int ans = 0;
    while (n)
    {
        n /= 10;
        ans++;
    }
    return ans;
}

vector<string> res;
string dst = "";
void dfs(int r, int c)
{
    if (r == c)
    {
        res.push_back(dst);
        return;
    }
    if (r == 0)
    {
        for (int i = 1; i <= 9; i += 2)
        {
            dst.push_back(48 + i);
            dfs(r + 1, c);
            dst.pop_back();
        }
    }
    else
    {
        for (int i = 0; i <= 9; i++)
        {
            dst.push_back(48 + i);
            dfs(r + 1, c);
            dst.pop_back();
        }
    }
}

vector<int> ans;
void num(int left, int right)
{
    for (int i = left; i <= right; i++)
    {
        if (i == 1)
        {
            dfs(0, 1);
            for (int i = res.size() - 1; i >= 0; i--)
            {
                ans.push_back(stoi(res[i]));
                res.pop_back();
            }
            continue;
        }
        int tol = i / 2;
        if (i % 2 == 1)
        {
            dfs(0, tol + 1);
            for (int i = 0; i < res.size(); i++)
            {
                for (int j = res[i].size() - 2; j >= 0; j--)
                {
                    res[i].push_back(res[i][j]);
                }
            }
            for (int i = res.size() - 1; i >= 0; i--)
            {
                ans.push_back(stoi(res[i]));
                res.pop_back();
            }
        }
        else
        {
            dfs(0, tol);
            for (int i = 0; i < res.size(); i++)
            {
                for (int j = res[i].size() - 1; j >= 0; j--)
                {
                    res[i].push_back(res[i][j]);
                }
            }
            for (int i = res.size() - 1; i >= 0; i--)
            {
                ans.push_back(stoi(res[i]));
                res.pop_back();
            }
        }
    }
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << endl;
    // }
}

bool isprime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int a, b;
    cin >> a >> b;
    num(numlg(a), numlg(b));

    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] >= a && ans[i] <= b)
        {
            if (isprime(ans[i]))
            {
                cout << ans[i] << endl;
            }
        }
    }
}