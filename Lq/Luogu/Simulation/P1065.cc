/*
 * @Author       : Outsider
 * @Date         : 2023-07-01 10:50:18
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-07-02 09:52:57
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\Simulation\P1065.cc
 */
#include <iostream>

using namespace std;

int ls[450];
int ss[25][25];
int tt[25][25];

int beach[25][10000];
int last[25];

int step[25];

int main()
{
    int ans = 0;
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m * n; i++)
    {
        cin >> ls[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> ss[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> tt[i][j];
        }
    }

    for (int i = 1; i <= n * m; i++)
    {
        int n = ls[i];
        int s = ++step[n];

        int tol = 0;
        for (int j = last[n] + 1; j <= 10000; j++)
        {
            if (beach[ss[n][s]][j] == 0)
            {
                tol++;
            }
            else
            {
                tol = 0;
            }
            if (tol == tt[n][s])
            {
                for (int k = j; k > j - tt[n][s]; k--)
                {
                    beach[ss[n][s]][k] = 1;
                }
                ans = max(ans, j);
                last[n] = j;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}