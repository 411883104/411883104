/*
 * @Author: Outsider
 * @Date: 2023-01-02 12:17:07
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-02 14:40:22
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\p1618-dfs.cc
 */
#include <iostream>
#include <algorithm>

using namespace std;

int cnt = 0;
int arr[10];
int vis[10] = {0};
int ans = 0;
int a, b, c;
void dfs()
{
    if (cnt == 9)
    {
        int x = arr[1] * 100 + arr[2] * 10 + arr[3];
        int y = arr[4] * 100 + arr[5] * 10 + arr[6];
        int z = arr[7] * 100 + arr[8] * 10 + arr[9];
        if (x * b == y * a && y * c == z * b)
        {
            ans++;
            cout << x << " " << y << " " << z << endl;
        }
        return;
    }
    for (int i = 1; i <= 9; i++)
    {
        if (vis[i] == 0)
        {
            vis[i] = 1;
            arr[++cnt] = i;
            dfs();
            --cnt;
            vis[i] = 0;
        }
    }
}

int main()
{
    cin >> a >> b >> c;
    dfs();
    if (ans == 0)
    {
        cout << "No!!!" << endl;
    }
}
