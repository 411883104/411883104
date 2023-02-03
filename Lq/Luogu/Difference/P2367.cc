/*
 * @Author: Outsider
 * @Date: 2023-02-03 17:13:35
 * @LastEditors: Outsider
 * @LastEditTime: 2023-02-03 17:33:17
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\Difference\P2367.cc
 */
#include <iostream>
#include <algorithm>
using namespace std;
int a[5000005];
int b[5000005];

int main()
{
    int n, p;
    cin >> n >> p;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i] - a[i - 1];
    }
    int x, y, z;
    while (p--)
    {
        cin >> x >> y >> z;
        b[x] += z;
        b[y + 1] -= z;
    }
    int minn = 1e9;
    for (int i = 1; i <= n; i++)
    {
        b[i] += b[i - 1];
        minn = min(b[i], minn);
    }
    cout << minn << endl;
}