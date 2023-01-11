/*
 * @Author: Outsider
 * @Date: 2023-01-04 11:21:39
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-04 12:09:48
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\p1149.cc
 */
#include <iostream>

using namespace std;

int arr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int totol(int n)
{
    int tol = 0;
    do
    {
        tol += arr[n % 10];
        n /= 10;
    } while (n);
    return tol;
}
int n;
int ans = 0;
void dfs(int r, int right, int sum, int tol, int start)
{
    if (r == 2)
    {
        if (totol(sum) + tol + 4 == n)
        {
            ans++;
            if (right != sum - right)
                ans++;
        }
        return;
    }
    for (int i = start; i < 1000; i++)
    {
        dfs(r + 1, i, sum + i, tol + totol(i), i);
    }
}

int main()
{
    cin >> n;
    dfs(0, 0, 0, 0, 0);
    cout << ans << endl;
}