/*
 * @Author: Outsider
 * @Date: 2023-01-11 19:34:35
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-11 22:55:24
 * @Description: In User Settings Edit
 * @FilePath: \Lq\other\p1255.cc
 */
#include <iostream>

using namespace std;

int a1[10000] = {0};
int a2[10000] = {0};

int add(int a1[], int m, int a2[], int n)
{
    int maxx = (m > n ? m : n);
    for (int i = 0; i < maxx; i++)
    {
        int cnt = a1[i] + a2[i];
        a1[i] = cnt % 10;
        a1[i + 1] += cnt / 10;
    }
    if (a1[maxx] != 0)
        return maxx + 1;
    while (a1[maxx] == 0 && --maxx > 0)
        ;
    return maxx + 1;
}

void print(int arr[], int len)
{
    while (len-- > 0)
    {
        cout << arr[len];
    }
}

int main()
{
    int n;
    cin >> n;

    int a = 1, b = 1;
    a1[0] = 1, a2[0] = 2;
    for (int i = 3; i <= n; i++)
    {
        if (i % 2 == 1)
        {
            a = add(a1, a, a2, b);
        }
        else
        {
            b = add(a2, b, a1, a);
        }
    }
    if (n % 2 == 0)
    {
        print(a2, b);
    }
    else
    {
        print(a1, a);
    }
}