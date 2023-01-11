/*
 * @Author: Outsider
 * @Date: 2023-01-03 12:55:40
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-03 13:46:52
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\p36544.cc
 */
#include <iostream>

using namespace std;

int main()
{
    int r, c, k;
    string arr[102];
    cin >> r >> c >> k;
    for (int i = 0; i < r; i++)
    {
        cin >> arr[i];
    }
    int ans = 0;
    for (int i = 0; i < r; i++)
    {
        string sub(k, '.');
        int pos = 0;
        while ((pos = arr[i].find(sub, pos)) != string::npos)
        {
            ans++;
            pos++;
        }
    }
    string str[102];
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            str[i].push_back(arr[j][i]);
        }
    }
    for (int i = 0; i < c; i++)
    {
        string sub(k, '.');
        int pos = 0;
        while ((pos = str[i].find(sub, pos)) != string::npos)
        {
            ans++;
            pos++;
        }
    }
    if (k == 1)
    {
        ans /= 2;
    }
    cout << ans << endl;
}