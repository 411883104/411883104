/*
 * @Author: Outsider
 * @Date: 2023-01-04 14:23:38
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-04 16:50:46
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\p3799.cc
 */
#include <iostream>
#include <map>

using namespace std;

int m[500005] = {0};
const int c = 1000000007;

int main()
{
    int n;
    cin >> n;
    int x;
    int maxx = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        m[x]++;
        maxx = max(x, maxx);
    }
    int ans = 0;

    for (int i = 0; i <= maxx; i++)
    {
        if (m[i] >= 2)
        {
            int tol = m[i] * (m[i] - 1) / 2;

            for (int j = 0; j < i && j * 2 <= i; j++)
            {
                if (m[j] != 0)
                {
                    int cnt = i - j;
                    if (m[cnt] != 0)
                    {
                        if (j != cnt)
                        {
                            ans += tol * m[cnt] * m[j];
                        }
                        else if (m[cnt] >= 2)
                        {
                            int j = m[cnt] * (m[cnt] - 1) / 2;
                            ans += tol * j;
                        }
                        ans %= c;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}