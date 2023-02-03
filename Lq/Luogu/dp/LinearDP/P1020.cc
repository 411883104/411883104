/*
 * @Author: Outsider
 * @Date: 2023-01-27 09:59:36
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-27 11:50:56
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\DP\LinearDP\P1020.cc
 */
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int c = 105;
int arr[c];

int dp[c] = {0};
int main()
{
    int a = 0;
    while (cin >> arr[++a])
        ;
    int maxx = 0;

    for (int i = 1; i <= a; i++)
    {
        int l = 0, r = maxx;
        while (l < r)
        {
            int mid = l + ((r - l) >> 1);
            if (dp[mid] == arr[i])
            {
                l = mid + 1;
            }
            else if (dp[mid] > arr[i])
            {
                l = mid + 1;
            }
            else if (dp[mid] < arr[i])
            {
                r = mid;
            }
        }
        dp[l] = arr[i];
        if (l == maxx)
        {
            maxx++;
        }
    }

    cout << maxx-1 << endl;

    memset(dp, 0, c * 4);
    maxx = 0;
    for (int i = 1; i <= a; i++)
    {
        int l = 0, r = maxx;
        while (l < r)
        {
            int mid = l + ((r - l) >> 1);
            if (dp[mid] == arr[i])
            {
                r = mid;
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
        if (l == maxx)
        {
            maxx++;
        }
    }

    cout << maxx << endl;
}