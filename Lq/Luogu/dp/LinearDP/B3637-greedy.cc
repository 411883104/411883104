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
        int l = 0, r = idx;
        while (l < r)
        {
            int mid = l + ((r - l) >> 1);
            if (dp[mid] == arr[i])
            {
                l = r = mid;
            }
            else if (dp[mid] < arr[i])
            {
                l = mid + 1;
            }
            else if (dp[mid] > arr[i])
            {
                r = mid;
            }
        }
        dp[l] = arr[i];
        if (l == idx)
        {
            idx++;
        }
    }
    cout << idx << endl;
}