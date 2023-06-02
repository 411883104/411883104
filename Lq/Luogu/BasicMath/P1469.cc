/*
 * @Author       : Outsider
 * @Date         : 2023-03-28 19:06:32
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-03-28 19:09:35
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\BasicMath\P1469.cc
 */
#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int x;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        ans ^= x;
    }
    cout << ans << endl;
    return 0;
}