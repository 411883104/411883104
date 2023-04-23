/*
 * @Author       : Outsider
 * @Date         : 2023-03-25 14:47:53
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-03-25 15:07:38
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\BasicMath\P3383.cc
 */
#include <iostream>

using namespace std;

const int c = 100000005;

int arr[c];
int ans[c];
int n, q;
int k = 0;
void prime()
{
    for (int i = 2; i <= n; i++)
    {
        if (arr[i] == 0)
        {
            ans[++k] = i;
        }
        for (int j = 1; j <= k && ans[j] * i <= n; j++)
        {
            arr[i * ans[j]] = 1;
            if (i % ans[j] == 0)
            {
                break;
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    prime();
    while (q--)
    {
        cin >> n;
        cout << ans[n] << endl;
    }
}