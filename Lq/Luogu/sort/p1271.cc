/*
 * @Author: Outsider
 * @Date: 2023-01-05 10:03:28
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-05 10:05:19
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\sort\p1271.cc
 */
#include <iostream>
#include <algorithm>
using namespace std;

int arr[2000005];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + m);
    for (int i = 0; i < m; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}