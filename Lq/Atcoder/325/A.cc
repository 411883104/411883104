/*
 * @Author       : Outsider
 * @Date         : 2023-03-25 20:33:13
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-03-25 20:36:18
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Atcoder\325\A.cc
 */
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    bool ans = false;
    string s;
    while (n--)
    {
        cin >> s;
        if (s == "and" || s == "not" || s == "that" || s == "the" || s == "you")
        {
            ans = true;
        }
    }
    if (ans)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}