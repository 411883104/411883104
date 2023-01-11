/*
 * @Author: Outsider
 * @Date: 2023-01-10 14:28:46
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-10 14:55:35
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\HighPrecision\p1009.cc
 */
#include <iostream>

using namespace std;

string mul(string left, string right)
{
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
    return string(ans.rbegin(), ans.rend());
}

string add(string left, string right)
{
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
    return string(ans.rbegin(), ans.rend());
}

int main()
{
    int n;
    cin >> n;
    string ans = "0";
    for (int i = 1; i <= n; i++)
    {
        string cnt = "1";
        for (int j = 1; j <= i; j++)
        {
            char arr[10];
            sprintf(arr, "%d", j);
            cnt = mul(cnt, arr);
        }
        ans = add(ans, cnt);
    }
    cout << ans << endl;
}