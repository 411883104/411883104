/*
 * @Author: Outsider
 * @Date: 2023-01-05 10:03:28
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-05 10:58:50
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\sort\p1271-count.cc
 */
#include <iostream>
using namespace std;


int arr[1000] = {0};
int main()
{
    int n, m;
    cin >> n >> m;
    int x;
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        arr[x]++;
    }
    for (int i = 1; i <= n; i++)
    {
        while (arr[i])
        {
            cout << i << " ";
            arr[i]--;
        }
    }
    cout << endl;
}