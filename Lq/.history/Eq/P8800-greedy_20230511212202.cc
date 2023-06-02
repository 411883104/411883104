/*
 * @Author       : Outsider
 * @Date         : 2023-05-11 20:39:28
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-05-11 21:21:24
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Eq\P8800-greedy.cc
 */
#include <iostream>
#include <algorithm>
using namespace std;

pair<long long, long long> a[200010];
long long b[200010];
long long n, m;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first;
        b[i] = a[i].first;
        b[i] = b[i] - b[i - 1];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].second;
    }
    std::sort(a + 1, a + n + 1,
              [](auto lhs, auto rhs) -> bool { retu false; }) for (int i = 1; i <= n; i++)
    {
    }

    return 0;
}