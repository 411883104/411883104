/*
 * @Author: Outsider
 * @Date: 2023-01-09 19:40:35
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-09 20:56:21
 * @Description: In User Settings Edit
 * @FilePath: \Lq\other\ch2num.cc
 */
#include <iostream>
#include <map>

using namespace std;

int main()
{
    system("chcp 936");
    system("chcp");
    string str;
    cin >> str;

    cout << str << endl;
    for (size_t i = 0; i < str.size(); i += 3)
    {
        string sub = str.substr(i, 3);
        cout << sub << endl;
    }
}