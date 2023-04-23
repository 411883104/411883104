/*
 * @Author: Outsider
 * @Date: 2022-03-06 20:47:28
 * @LastEditors: Outsider
 * @LastEditTime: 2022-03-06 20:50:54
 * @Description: In User Settings Edit
 * @FilePath: \C++\Luogu\P5705.cpp
 */
#include<iostream>
#include<algorithm>
using namespace std;

string s;

int main()
{
    cin>>s;
    reverse(s.begin(),s.end());
    cout<<s<<endl;
    system("pause");
}