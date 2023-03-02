/*
 * @Author       : Outsider
 * @Date         : 2023-02-27 17:06:17
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-02-27 17:15:15
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\KMP\P3375.cc
 */
#include <iostream>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    int i, j;
    for (i = 0, j = 0; i < a.size() && j < b.size();)
    {
        if (a[i] == b[j])
        {
            ++j;
            ++i;
        }
        else
        {
            j = 0;
            i = i - j + 1;
        }
    }
    if (j == b.size())
    {
        cout << "true" << endl;
    }
}