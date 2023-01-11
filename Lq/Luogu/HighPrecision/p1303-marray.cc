/*
 * @Author: Outsider
 * @Date: 2023-01-10 10:39:04
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-11 09:50:21
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\HighPrecision\p1303-marray.cc
 */
#include <iostream>
#include <iomanip>

using namespace std;

int lt[2005] = {0};
int rt[2005] = {0};
int ans[4005] = {0};

int main()
{
    string left, right;
    cin >> left >> right;

    int j = 0;
    for (int i = left.size(); i > 0; i -= 4)
    {
        if (i - 4 >= 0)
            lt[j++] = stoi(left.substr(i - 4, 4));
        else
            lt[j++] = stoi(left.substr(0, i));
    }
    int k = 0;
    for (int i = right.size(); i > 0; i -= 4)
    {
        if (i - 4 >= 0)
            rt[k++] = stoi(right.substr(i - 4, 4));
        else
            rt[k++] = stoi(right.substr(0, i));
    }

    for (int m = 0; m < j; m++)
    {
        for (int n = 0; n < k; n++)
        {
            ans[m + n] += lt[m] * rt[n];
            ans[m + n + 1] += ans[m + n] / 10000;
            ans[m + n] %= 10000;
        }
    }

    int idx = j + k - 2;
    if (ans[idx + 1] != 0)
    {
        cout << ans[idx + 1];
        while (idx >= 0)
        {
            cout << setw(4) << setfill('0') << ans[idx--];
        }
    }
    else
    {
        while (ans[idx] == 0 && --idx > 0)
            ;
        cout << ans[idx--];
        while (idx >= 0)
        {
            cout << setw(4) << setfill('0') << ans[idx--];
        }
    }
}