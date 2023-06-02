/*
 * @Author       : Outsider
 * @Date         : 2023-03-31 09:11:37
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-03-31 09:22:18
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\Combinatorics\P5520.cc
 */
#include <iostream>
using namespace std;

const int c = 2000005;

int main()
{
    int t;
    cin >> t;
    int n, m, p;
    cin >> n >> m >> p;

    long long ans = 1;
    for (int i = n - 2 * m + 2; i <= n - m + 1; i++)
    {
        ans = ((ans * i) % p);
    }
    cout << ans << endl;
    return 0;
}