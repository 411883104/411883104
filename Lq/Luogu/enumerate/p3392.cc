/*
 * @Author: Outsider
 * @Date: 2023-01-02 22:23:35
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-03 11:43:04
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\p3392.cc
 */
#include <iostream>

using namespace std;

int n, m;

string arr[55];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        if (arr[0][i] != 'W')
        {
            ans++;
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (arr[n - 1][i] != 'R')
        {
            ans++;
        }
    }
    int minn = 0xfffff;

    for (int i = n - 2; i > 0; i--)
    {
        int cnt = 0;

        for (int j = n - 2; j > i; j--)
        {
            for (int k = 0; k < m; k++)
            {
                if (arr[j][k] != 'R')
                {
                    cnt++;
                }
            }
        }
        for (int j = i - 1; j >= 0; j--)
        {
            int bnt = 0;
            for (int a = i; a > j ; a--)
            {
                for (int b = 0; b < m; b++)
                {
                    if (arr[a][b] != 'B')
                    {
                        bnt++;
                    }
                }
            }
            for (int a = j; a > 0; a--)
            {
                for (int b = 0; b < m; b++)
                {
                    if (arr[a][b] != 'W')
                    {
                        bnt++;
                    }
                }
            }
            minn = min(minn, cnt + bnt);
        }
    }
    cout << ans + minn << endl;
}