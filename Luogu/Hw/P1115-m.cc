/*
 * @Author       : Outsider
 * @Date         : 2023-04-23 19:23:09
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-04-24 09:33:30
 * @Description  : In User Settings Edit
 * @FilePath     : \Luogu\Hw\P1115-m.cc
 */
#include <iostream>
using namespace std;

int a[200005];

int main()
{
    int n;
    cin >> n;
    int maxx = -0xfffffff;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++) // 枚举子区间
        {
            int sum = 0;
            for (int k = j; k <= i; k++)
            {
                sum += a[k]; // 求子区间和
            }
            maxx = max(maxx, sum);
        }
    }
    cout << maxx << endl;
    return 0;
}