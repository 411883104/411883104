/*
 * @Author: Outsider
 * @Date: 2023-01-10 22:16:13
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-10 22:27:30
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\HighPrecision\p1601-array.cc
 */
#include <iostream>
using namespace std;

int lt[505] = {0};
int rt[505] = {0};

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

    int maxx = (right.size() > left.size() ? right.size() : left.size());
    for (int i = 0; i < maxx; i++)
    {
        int cnt = rt[i] + lt[i];
        rt[i] = cnt % 10;
        rt[i + 1] += cnt / 10;
    }
    if (rt[maxx] != 0)
        cout << rt[maxx];
    while (maxx > 0)
    {
        cout << rt[--maxx];
    }
}