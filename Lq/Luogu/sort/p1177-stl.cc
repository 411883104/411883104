/*
 * @Author: Outsider
 * @Date: 2023-01-05 22:21:24
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-05 22:21:41
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\sort\p1177-stl.cc
 */
#include <iostream>
#include <algorithm>

using namespace std;
int arr[100005];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    cout << endl;
}