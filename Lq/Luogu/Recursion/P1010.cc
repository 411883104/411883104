/*
 * @Author: Outsider
 * @Date: 2023-02-08 13:02:56
 * @LastEditors: Outsider
 * @LastEditTime: 2023-02-08 17:49:08
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\Recursion\P1010.cc
 */
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<string> ans;
int lowbit(int x)
{
    return x & (-x);
}
void dfs(int n, string &ss)
{
    if (n == 1)
    {
        ss.append("2(0)");
        return;
    }
    if (n == 2)
    {
        ss.append("2");
        return;
    }
    ss.append("2(");
    int x = log2(n);
    while (x > 0)
    {
        int s = 1;
        while (s <= x)
        {
            s <<= 1;
        }
        s >>= 1;
        x -= s;
        dfs(s, ss);
        ss.append("+");
    }
    ss.pop_back();
    ss.append(")");
}

int main()
{
    int n;
    cin >> n;
    while (n > 0)
    {
        int s = 1;
        while (s <= n)
        {
            s <<= 1;
        }
        s >>= 1;
        n -= s;
        string ss;
        dfs(s, ss);
        cout << ss << "+\n"[n == 0];
    }
}