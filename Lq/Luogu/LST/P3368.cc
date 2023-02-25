/*
 * @Author: Outsider
 * @Date: 2023-01-24 18:18:10
 * @LastEditors: Outsider
 * @LastEditTime: 2023-02-18 17:47:32
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\LST\P3368.cc
 */
#include <iostream>

using namespace std;

int arr[500005];
int n, m;

int lowbit(int x)
{
    return x & (-x);
}

void update(int ix, int val)
{
    for (int i = ix; i <= n; i += lowbit(i))
    {
        arr[i] += val;
    }
}

int query(int idx)
{
    int sum = 0;
    for (int i = idx; i > 0; i -= lowbit(i))
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    cin >> n >> m;
    int left, right;
    for (int i = 1; i <= n; i++)
    {
        cin >> right;
        update(i, right - left);
        left = right;
    }

    int op;
    while (m--)
    {
        cin >> op;
        int x, k, y;
        if (op == 1)
        {
            cin >> x >> y >> k;
            update(x, k);
            update(y + 1, -k);
        }
        else if (op == 2)
        {
            cin >> x;
            cout << query(x) << endl;
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i + 1] << endl;
    // }
}