/*
 * @Author: Outsider
 * @Date: 2023-02-04 09:50:13
 * @LastEditors: Outsider
 * @LastEditTime: 2023-02-04 12:50:14
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\DP\LinearDP\P1091-opt.cc
 */
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
int arr[105];
int dp[105];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int maxx = 0;
    for (int i = 0; i < n; i++)
    {
        memset(dp, 0, 105 * 4);
        int ans = 0;
        for (int j = i; j >= 0; j--)
        {
            if (arr[j] < arr[i])
            {
                int l = 0, r = ans;
                while (l < r)
                {
                    int mid = l + ((r - l) >> 1);
                    if (dp[mid] == arr[j])
                    {
                        r = mid;
                    }
                    else if (dp[mid] > arr[j])
                    {
                        l = mid + 1;
                    }
                    else if (dp[mid] < arr[j])
                    {
                        r = mid;
                    }
                }
                dp[l] = arr[j];
                if (l == ans)
                {
                    ans++;
                }
            }
        }
        memset(dp, 0, 105 * 4);
        int res = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                int l = 0, r = res;
                while (l < r)
                {
                    int mid = l + ((r - l) >> 1);
                    if (dp[mid] == arr[j])
                    {
                        r = mid;
                    }
                    else if (dp[mid] > arr[j])
                    {
                        l = mid + 1;
                    }
                    else if (dp[mid] < arr[j])
                    {
                        r = mid;
                    }
                }
                dp[l] = arr[j];
                if (l == res)
                {
                    res++;
                }
            }
        }
        maxx = max(res + ans + 1, maxx);
    }
    cout << n - maxx << endl;
}