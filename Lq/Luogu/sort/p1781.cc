/*
 * @Author: Outsider
 * @Date: 2023-01-06 15:14:17
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-06 15:39:20
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\sort\p1781.cc
 */
#include <iostream>
#include <algorithm>

using namespace std;

string arr[25];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int maxx = 0;
    string str;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].size() > maxx)
        {
            maxx = arr[i].size();
            str = arr[i];
        }
    }
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].size() == maxx)
        {
            if (str <= arr[i])
            {
                str = arr[i];
                idx = i + 1;
            }
        }
    }

    cout << idx << endl;
    cout << str << endl;
}