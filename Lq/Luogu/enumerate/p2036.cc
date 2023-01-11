/*
 * @Author: Outsider
 * @Date: 2023-01-04 09:50:46
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-04 10:07:03
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\p2036.cc
 */
#include <iostream>

using namespace std;
int n;
int arr[12][2];

int minn;
int cnt = 0;
void dfs(int i, int left, int right)
{
    if (i == n)
    {
        if (cnt == 0)
        {
            return;
        }
        minn = min(minn, abs(left - right));
        return;
    }
    dfs(i + 1, left, right);
    cnt++;
    dfs(i + 1, left * arr[i][0], right + arr[i][1]);
    if (cnt == 1)
    {
        cnt = 0;
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
    }
    minn = 0xfffffff;
    dfs(0, 1, 0);
    cout << minn << endl;
}