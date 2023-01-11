/*
 * @Author: Outsider
 * @Date: 2023-01-02 22:08:11
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-02 22:11:13
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\p1088.cc
 */
#include <iostream>
#include <algorithm>

using namespace std;

int num[10005];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    for (int i = 0; i < m; i++)
    {
        next_permutation(num, num + n);
    }
    for (int i = 0; i < n; i++)
    {
        cout << num[i] << " ";
    }
    cout << endl;
}