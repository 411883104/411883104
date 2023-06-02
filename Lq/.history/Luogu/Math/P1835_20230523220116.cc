/*
 * @Author       : Outsider
 * @Date         : 2023-05-23 21:55:11
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-05-23 22:01:03
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\Math\P1835.cc
 */
#include <iostream>

int prime[100005];
int flag[100005];
int tol = 0;
const int N = 100000;
using namespace std;

int main()
{
    for (int i = 2; i <= N; i++)
    {
        if (flag[i] == 0)
        {
            prime[tol++] = i;
        }
        for (int j = 0; j < tol && prime[j] * i <= N; j++)
        {
            flag[i * prime[j]] = 1;
            if (i % prime[j] == 0)
            {
                break;
            }
        }
    }
    // for (int i = 0; i < tol; i++)
    // {
    //     cout << prime[i] << endl;
    // }
    int l, r;
    cin >> l >> r;
}