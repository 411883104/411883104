/*
 * @Author: Outsider
 * @Date: 2023-01-10 10:39:04
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-11 09:29:28
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\HighPrecision\p1303-array.cc
 */
#include <iostream>

using namespace std;

int lt[2005] = {0};
int rt[2005] = {0};
int ans[4005] = {0};

int main()
{
    string left, right;
    cin >> left >> right;

    for (int i = 0; i < left.size(); i++)
    {
        lt[i] = left[left.size() - i - 1] - 48;
    }
    for (int i = 0; i < right.size(); i++)
    {
        rt[i] = right[right.size() - 1 - i] - 48;
    }

    for (int i = 0; i < left.size(); i++)
    {
        for (int j = 0; j < right.size(); j++)
        {
            ans[i + j] += lt[i] * rt[j];
            ans[i + j + 1] += ans[i + j] / 10;
            ans[i + j] %= 10;
        }
    }

    int idx = left.size() + right.size() - 2;
    if (ans[idx + 1] != 0)
    {
        cout << ans[idx + 1];
        while (idx >= 0)
        {
            cout << ans[idx--];
        }
    }
    else
    {
        while (ans[idx] == 0 && --idx > 0)
            ;
        while (idx >= 0)
        {
            cout << ans[idx--];
        }
    }
}