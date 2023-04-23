/*
 * @Author: Outsider
 * @Date: 2023-01-26 12:09:55
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-27 09:57:27
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\dp\B3637-greedy.cc
 */
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int c = 50005;

int arr[c];
int dp[c];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        int ll = 0, rr = idx;
        while (ll < rr)
        {
            int mm = ll + ((rr - ll) >> 1);
            if (dp[mm] == arr[i])
            {
                rr = mm;
            }
            else if (dp[mm] < arr[i])
            {
                ll = mm + 1;
            }
            else if (dp[mm] > arr[i])
            {
                rr = mm;
            }
        }
        dp[ll] = arr[i];
        if (ll == idx)
        {
            idx++;
        }
    }
    cout << idx << endl;
}