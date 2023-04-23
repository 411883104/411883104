/*
 * @Author       : Outsider
 * @Date         : 2023-04-23 19:23:09
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-04-23 19:40:37
 * @Description  : In User Settings Edit
 * @FilePath     : \Luogu\Hw\P1115.cc
 */
#include <iostream>
using namespace std;

int a[200005];
int b[200005];

int main()
{
    int n;
    cin >> n;
    int maxx = 0xfffffff;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = b[i - 1] + a[i];
        maxx = min(maxx, a[i]);
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            maxx = max(maxx, b[i] - b[j]);
        }
    }
    cout << maxx << endl;
    return 0;
}