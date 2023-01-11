/*
 * @Author: Outsider
 * @Date: 2023-01-10 15:05:39
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-10 18:43:55
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\HighPrecision\p1045.cc
 */
#include <iostream>
#include <cmath>
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

string sub(string left, string right)
{
    int i = left.size(), j = right.size();
    int ov = 0;
    string ans;
    while (i > 0 && j > 0)
    {
        int lt = (left[--i] - 48);
        int rt = (right[--j] - 48);
        int c = lt - ov - rt;
        if (c < 0)
        {
            c = lt - ov + 10 - rt;
            ov = 1;
        }
        else
        {
            ov = 0;
        }
        ans.push_back((c) + 48);
    }
    while (i > 0)
    {
        int c = (left[--i] - 48) - ov;
        ans.push_back((c) + 48);
    }
    return string(ans.rbegin(), ans.rend());
}

int main()
{
    int p;
    cin >> p;
    cout << int(p * log10(2)) + 1 << endl;
    string ans = "1";
    string m = "2";
    while (p > 0)
    {
        if (p % 2 == 1)
        {
            ans = mul(ans, m);
        }
        m = mul(m, m);
        p >>= 1;
    }
    // cout << ans << endl;
    if (ans.size() < 500)
    {
        string res = string(500 - ans.size(), '0');
        res.append(sub(ans, "1"));
        for (int i = 0; i < 500; i += 50)
        {
            cout << res.substr(i, 50) << endl;
        }
    }
    else
    {
        string res = sub(string(ans.end() - 500, ans.end()), "1");
        for (int i = 0; i < 500; i += 50)
        {
            cout << res.substr(i, 50) << endl;
        }
    }
}
