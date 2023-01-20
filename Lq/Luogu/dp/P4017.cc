/*
 * @Author: Outsider
 * @Date: 2023-01-20 20:30:15
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-20 21:55:07
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\dp\P4017.cc
 */
#include <iostream>

using namespace std;

int arr[5050][5050] = {0};

long long dp[5050];
int in[5050];
int out[5000005];

int q[5050];

const int c = 80112002;

int main()
{
    int n, m;
    cin >> n >> m;
    int x, y;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        arr[x][y] = 1;
        in[y]++;
        out[x]++;
    }

    int hh = 0, tt = -1;
    for (int j = 1; j <= n; j++)
    {
        if (in[j] == 0)
        {
            dp[j] = 1;
            q[++tt] = j;
        }
    }

    while (hh <= tt)
    {
        int s = q[hh++];
        for (int i = 1; i <= n; i++)
        {
            if (arr[s][i] == 1)
            {
                dp[i] += dp[s];
                dp[i] %= c;
                in[i]--;
                if (in[i] == 0)
                {
                    q[++tt] = i;
                }
            }
        }
    }

    int maxx = 0;
    // for (int j = 1; j <= n; j++)
    // {
    //     for (int i = 1; i <= n; i++)
    //     {
    //         if (arr[i][j] == 1)
    //         {
    //             dp[j] += dp[i];
    //             dp[j] %= c;
    //         }
    //     }
    // }

    for (int j = 1; j <= n; j++)
    {
        if (out[j] == 0)
        {
            maxx += dp[j];
            maxx %= c;
        }
    }

    cout << maxx << endl;
}