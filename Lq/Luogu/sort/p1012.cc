/*
 * @Author: Outsider
 * @Date: 2023-01-06 21:53:51
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-08 21:46:29
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\sort\p1012.cc
 */
#include <iostream>
#include <algorithm>

using namespace std;

string arr[25];

bool cmp(string a, string b)
{
    if (a.size() == b.size())
    {
        return a > b;
    }
    if (a.size() < b.size())
    {
        if (b.substr(0, a.size()) == a)
        {
            for (int i = a.size(); i < b.size() && i < 2 * a.size() - 1; i++)
            {
                if (a[i - a.size()] > b[i])
                {
                    return false;
                }
                if (a[i - a.size()] < b[i])
                {
                    return true;
                }
            }
        }
        return a > b;
    }
    if (a.size() > b.size())
    {
        if (a.substr(0, b.size()) == b)
        {
            for (int i = b.size(); i < a.size() && i < 2 * b.size() - 1; i++)
            {
                if (b[i - b.size()] > a[i])
                {
                    return true;
                }
                if (b[i - b.size()] < a[i])
                {
                    return false;
                }
            }
        }
        return a > b;
    }
}
int n;

void bsort()
{
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j].size() == arr[j + 1].size())
            {
                if (arr[j] < arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                }
            }
            else if (arr[j].size() < arr[j + 1].size())
            {
                if (arr[j + 1].substr(0, arr[j].size()) == arr[j])
                {
                    for (int k = arr[j].size();
                         k < arr[j + 1].size() && k < 2 * arr[j].size();
                         k++)
                    {
                        if (arr[j][k - arr[j].size()] < arr[j + 1][k])
                        {
                            swap(arr[j], arr[j + 1]);
                            break;
                        }
                    }
                }
                else
                {
                    if (arr[j] < arr[j + 1])
                    {
                        swap(arr[j], arr[j + 1]);
                    }
                }
            }
            else if (arr[j].size() > arr[j + 1].size())
            {
                if (arr[j].substr(0, arr[j + 1].size()) == arr[j + 1])
                {
                    for (int k = arr[j + 1].size();
                         k < arr[j].size() && k < 2 * arr[j + 1].size();
                         k++)
                    {
                        if (arr[j + 1][k - arr[j + 1].size()] > arr[j][k])
                        {
                            swap(arr[j], arr[j + 1]);
                            break;
                        }
                    }
                }
                else
                {
                    if (arr[j] < arr[j + 1])
                    {
                        swap(arr[j], arr[j + 1]);
                    }
                }
            }
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // sort(arr, arr + n, cmp);
    bsort();

    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
    cout << endl;
}