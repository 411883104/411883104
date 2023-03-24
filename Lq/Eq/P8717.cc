/*
 * @Author       : Outsider
 * @Date         : 2023-03-19 21:51:58
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-03-19 21:59:51
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Eq\P8717.cc
 */
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;
int a[100005];
int main()
{
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a + n);
    cout << a[n - 1] << endl
         << a[0] << endl
         << fixed << setprecision(2) << ((double)sum) / n << endl;
}