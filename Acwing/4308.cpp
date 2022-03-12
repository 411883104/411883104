/*
 * @Author: Outsider
 * @Date: 2022-03-11 20:02:04
 * @LastEditors: Outsider
 * @LastEditTime: 2022-03-11 20:07:51
 * @Description: In User Settings Edit
 * @FilePath: \C++\Acwing\4308.cpp
 */

#include<iostream>
#include<algorithm>
using namespace std;

string a,b;

int main()
{
    cin>>a>>b;
    string str="zzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
    for(int i=1;i<=a.size();i++)
    {
        for(int j=1;j<=b.size();j++){
            string s=a.substr(0,i)+b.substr(0,j);
            str=min(str,s);
        }
    }
    cout<<str<<endl;
    system("pause");
}