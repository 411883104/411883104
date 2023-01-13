/*
 * @Author: Outsider
 * @Date: 2023-01-13 10:07:11
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-13 13:44:48
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\HighPrecision\p1480.cc
 */
#include <iostream>

using namespace std;

int a[5005] = {0};
long long b = 0;
long long x = 0;
int res[5005] = {0};

int main()
{
    string str;
    cin >> str;
    cin >> b;
    for (int i = str.size() - 1; i >= 0; i--)
    {
        a[i] = str[i] - '0';
    }

    for (int i = 0; i < str.size(); i++)
    {
        res[i] = (x * 10 + a[i]) / b;
        x = (x * 10 + a[i]) % b;
    }

    int cnt = -1;
    while (++cnt < str.size() - 1 && res[cnt] == 0)
        ;
    while (cnt < str.size())
    {
        cout << res[cnt++];
    }
    cout << endl;
}