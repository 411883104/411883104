/*
 * @Author: Outsider
 * @Date: 2023-01-10 09:10:02
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-10 09:54:57
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\HighPrecision\p1601.cc
 */
#include <iostream>

using namespace std;

// char left[505];
// char right[505];

int main()
{
    string left, right;
    cin >> left >> right;
    int i = left.size(), j = right.size();
    int ov = 0;
    string ans;
    while (i > 0 && j > 0)
    {
        int c = (left[--i] - 48) + (right[--j] - 48) + ov;
        ov = c / 10;
        ans.push_back((c % 10) + 48);
    }
    while (i > 0)
    {
        int c = (left[--i] - 48) + ov;
        ov = c / 10;
        ans.push_back((c % 10) + 48);
    }
    while (j > 0)
    {
        int c = (right[--j] - 48) + ov;
        ov = c / 10;
        ans.push_back((c % 10) + 48);
    }
    if (ov != 0)
        ans.push_back(ov + 48);
    cout << string(ans.rbegin(), ans.rend()) << endl;
}