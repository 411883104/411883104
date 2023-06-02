/*
 * @Author       : Outsider
 * @Date         : 2023-02-27 17:06:17
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-05-24 16:21:28
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\KMP\P3375-stl.find.cc
 */
#include <iostream>
using namespace std;
int main()
{
    string a, b;
    cin >> a >> b;

    int i = 0;
    while ((i = a.find(b, i)) != string::npos)
    {
        cout << i + 1 << endl;
    }

    for (size_t i = 2; i <= b.size() + 1; i++)
    {
    }
    cout << endl;
}