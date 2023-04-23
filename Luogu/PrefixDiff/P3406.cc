/*
 * @Author       : Outsider
 * @Date         : 2023-04-09 09:46:19
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-04-09 12:29:22
 * @Description  : In User Settings Edit
 * @FilePath     : \Luogu\PrefixDiff\P3406.cc
 */
#include <iostream>
using namespace std;

const int c = 1005;

int aa[c];
int diff[c];

int main()
{
    int n, m;
    cin >> n >> m;
    int ll, rr;
    if (m != 0)
        cin >> ll;
    for (int i = 1; i < m; i++)
    {
        cin >> rr;
        if (rr > ll)
        {
            diff[ll] += 1;
            diff[rr] -= 1;
        }
        else
        {
            diff[rr] += 1;
            diff[ll] -= 1;
        }
        ll = rr;
    }

    int a, b, c;

    long long ans = 0;
    long long sum = 0;
    for (int i = 1; i < n; i++)
    {
        sum += diff[i];
        cin >> a >> b >> c;
        if (sum != 0)
        {
            ans += min(a * sum, b * sum + c);
        }
    }
    cout << ans << endl;
    return 0;
}