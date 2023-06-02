/*
 * @Author       : Outsider
 * @Date         : 2023-04-01 12:47:01
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-04-01 14:38:32
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\other\2659.cc
 */
#include <iostream>
using namespace std;

int a[505][505];
int b[505][505];

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            b[i][j] = a[i][j] + b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int p = i - 1; p >= 0; p--)
            {
                for (int q = j - 1; q >= 0; q--)
                {
                    if (b[i][j] - b[p][j] - b[i][q] + b[p][q] <= k)
                    {
                        ans++;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}