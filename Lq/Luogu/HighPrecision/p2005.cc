/*
 * @Author: Outsider
 * @Date: 2023-01-14 08:38:16
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-14 17:17:15
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\HighPrecision\p2005.cc
 */
#include <iostream>

using namespace std;

int a[50000] = {0};
int b[50000] = {0};
int ans[50000] = {0};

int cmp(int l, int r, int len)
{
    if (r - l < len)
    {
        return -1;
    }
    if (r - l > len)
    {
        return 1;
    }
    for (int i = l, j = 0; i < r && j < len; i++, j++)
    {
        if (a[i] < b[j])
            return -1;
        if (a[i] > b[j])
            return 1;
    }
    return 0;
}

int sub(int l, int r, int len)
{
    for (int i = r - 1, j = len - 1; i >= l && j >= 0; i--, j--)
    {
        if (a[i] >= b[j])
        {
            a[i] -= b[j];
        }
        else
        {
            a[i - 1]--;
            a[i] = a[i] + 10 - b[j];
        }
    }
    while (a[l] == 0 && l < r)
    {
        l++;
    }
    return l;
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;

    if (str1.size() < str2.size())
    {
        cout << "0" << endl;
        return 0;
    }

    for (int i = str1.size() - 1; i >= 0; i--)
    {
        a[i] = str1[i] - '0';
    }
    for (int i = str2.size() - 1; i >= 0; i--)
    {
        b[i] = str2[i] - '0';
    }

    int l = 0, r = 1;

    int idx = 0;
    while (r <= str1.size())
    {
        int ret = cmp(l, r, str2.size());
        if (ret == -1)
        {
            if (r > str1.size())
            {
                break;
            }
            if (r - 1 == idx)
            {
                ans[idx++] = 0;
            }
            r++;
            while (a[l] == 0 && l < r - 1)
            {
                l++;
            }
        }
        else if (ret == 0)
        {
            ans[idx++] = 1;
            l = r;
            r++;
        }
        else if (ret == 1)
        {
            while (cmp(l, r, str2.size()) >= 0)
            {
                l = sub(l, r, str2.size());
                ans[idx]++;
            }
            idx++;
            if (l == r)
            {
                r++;
            }
        }
    }
    int i = 0;
    while (ans[i] == 0 && i < idx - 1)
    {
        i++;
    };
    for (; i < idx; i++)
    {
        cout << ans[i];
    }
}