/*
 * @Author       : Outsider
 * @Date         : 2023-05-25 11:39:26
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-05-25 14:50:38
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\DP\LinearDP\P1874.cc
 */
#include <iostream>
using namespace std;

int n;
string str;
long long ans = 0xffffffff;
void dfs(size_t s, long long sum, long long tol)
{
    if (sum == n)
    {
        ans = min(ans, tol);
        return;
    }
    if (sum > n || ans <= tol)
    {
        return;
    }
    for (size_t i = s; i < str.size(); i++)
    {
        int num = stoi(str.substr(s, i - s + 1));
        if (num > n)
        {
            return;
        }
        if (i + 1 == str.size())
            dfs(i + 1, sum + num, tol);
        else
            dfs(i + 1, sum + num, tol + 1);
    }
}

int main()
{
    cin >> str;
    cin >> n;
    dfs(0, 0, 0);
    cout << (int)ans << endl;
    return 0;
}