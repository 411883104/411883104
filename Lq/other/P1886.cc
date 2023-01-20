/*
 * @Author: Outsider
 * @Date: 2023-01-18 12:28:09
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-19 17:06:21
 * @Description: In User Settings Edit
 * @FilePath: \Lq\other\P1886.cc
 */
#include <iostream>

using namespace std;

pair<int, int> q[1000005];

int arr[1000005] = {0};

int main()
{
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int t = -1, h = 0;
    for (int i = 0; i < n; i++)
    {
        while (t >= h && q[t].second >= arr[i])
            t--;
        q[++t] = make_pair(i, arr[i]);
        if (i - q[h].first + 1 > k)
        {
            ++h;
        }
        if (i >= k-1)
            cout << q[h].second << " ";
    }
    cout << endl;

    t = -1, h = 0;
    for (int i = 0; i < n; i++)
    {
        while (t >= h && q[t].second <= arr[i])
            t--;
        q[++t] = make_pair(i, arr[i]);
        if (i - q[h].first + 1 > k)
        {
            ++h;
        }
        if (i >= k-1)
            cout << q[h].second << " ";
    }
    cout << endl;
}