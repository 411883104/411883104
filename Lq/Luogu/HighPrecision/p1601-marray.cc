/*
 * @Author: Outsider
 * @Date: 2023-01-10 22:16:13
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-10 23:04:25
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\HighPrecision\p1601-marray.cc
 */
#include <iostream>
#include <iomanip>
using namespace std;

int lt[505] = {0};
int rt[505] = {0};

int main()
{
    string left, right;
    cin >> left >> right;
    int j = 0;
    for (int i = left.size(); i > 0; i -= 8)
    {
        if (i - 8 >= 0)
            lt[j++] = stoi(left.substr(i - 8, 8));
        else
            lt[j++] = stoi(left.substr(0, i));
    }
    int k = 0;
    for (int i = right.size(); i > 0; i -= 8)
    {
        if (i - 8 >= 0)
            rt[k++] = stoi(right.substr(i - 8, 8));
        else
            rt[k++] = stoi(right.substr(0, i));
    }

    int maxx = (j > k ? j : k);
    for (int i = 0; i < maxx; i++)
    {
        int cnt = rt[i] + lt[i];
        rt[i] = cnt % 100000000;
        rt[i + 1] += cnt / 100000000;
    }
    if (rt[maxx] != 0)
        cout << rt[maxx];
    else
        cout << rt[--maxx];
    while (maxx > 0)
    {
        cout << setw(8) << setfill('0') << rt[--maxx];
    }
}