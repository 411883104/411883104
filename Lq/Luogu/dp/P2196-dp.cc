/*
 * @Author: Outsider
 * @Date: 2023-01-20 13:33:22
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-20 19:52:24
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\dp\P2196-dp.cc
 */
#include <iostream>
#include <vector>

using namespace std;

int arr[100][100];
int num[100];
int dp[100];
int pre[100];
int n;

int maxx = 0;

void print(int res)
{
    if (res != 0)
    {
        print(pre[res]);
        cout << res << " ";
    }
}

int main()
{

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
        dp[i] = num[i];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            cin >> arr[i][j];
            arr[j][i] = arr[i][j];
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i ; j <= n; j++)
        {
            if (arr[i][j] == 1)
            {
                if (dp[j] < dp[i] + num[j])
                {
                    dp[j] = dp[i] + num[j];
                    pre[j] = i;
                }
            }
            if (dp[j] > maxx)
            {
                res = j;
                maxx = dp[j];
            }
        }
    }

    print(res);

    cout << endl
         << maxx << endl;
}