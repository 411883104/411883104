/*
 * @Author: Outsider
 * @Date: 2023-01-27 13:19:58
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-27 14:17:07
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\DP\LinearDP\P1439.cc
 */
#include <iostream>

using namespace std;

const int c = 105;

int a[c];
int b[c];
int dp[c];

int map[c];

int main()
{
    int n;
    cin >> n;
    int x;
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
        cin >> x;
        map[x] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        b[i] = map[x];
    }

    int maxx = 0;
    for (int i = 1; i <= n; i++)
    {
        int l = 0, r = maxx;
        while (l < r)
        {
            int mid = l + ((r - l) >> 1);
            if (dp[mid] == b[i])
            {
                r = mid;
            }
            else if (dp[mid] > b[i])
            {
                r = mid;
            }
            else if (dp[mid] < b[i])
            {
                l = mid + 1;
            }
        }
        dp[l] = b[i];
        if (l == maxx)
        {
            maxx++;
        }
    }
    cout << maxx << endl;
}