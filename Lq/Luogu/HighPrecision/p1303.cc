/*
 * @Author: Outsider
 * @Date: 2023-01-10 10:39:04
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-10 14:09:50
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\HighPrecision\p1303.cc
 */
#include <iostream>

using namespace std;

int main()
{
    string left, right;
    cin >> left >> right;

    string ans;
    for (int i = right.size() - 1; i >= 0; i--)
    {
        int ov = 0;
        string cnt = string(right.size() - 1 - i, '0');
        for (int j = left.size() - 1; j >= 0; j--)
        {
            int c = (left[j] - 48) * (right[i] - 48) + ov;
            ov = c / 10;
            cnt.push_back((c % 10) + 48);
        }
        if (ov != 0)
            cnt.push_back(ov + 48);
        int aov = 0;
        int j = 0, k = 0;
        for (; j < cnt.size() && k < ans.size(); j++, k++)
        {
            int c = (cnt[j] - 48) + (ans[k] - 48) + aov;
            aov = c / 10;
            ans[k] = ((c % 10) + 48);
        }
        while (k < ans.size())
        {
            int c = (ans[k] - 48) + aov;
            aov = c / 10;
            ans[k++] = ((c % 10) + 48);
        }
        while (j < cnt.size())
        {
            int c = (cnt[j++] - 48) + +aov;
            aov = c / 10;
            ans.push_back((c % 10) + 48);
        }
        if (aov != 0)
        {
            ans.push_back(aov + 48);
        }
    }
    for (int i = ans.size() - 1; i > 0 && ans[i] == '0'; i--)
    {
        ans.pop_back();
    }
    cout << string(ans.rbegin(), ans.rend()) << endl;
}