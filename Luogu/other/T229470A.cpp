/*
 * @Author: Outsider
 * @Date: 2022-03-12 15:32:35
 * @LastEditors: Outsider
 * @LastEditTime: 2022-03-12 15:35:45
 * @Description: In User Settings Edit
 * @FilePath: \C++\Luogu\T229470A.cpp
 */

#include<iostream>

using namespace std;

string str;

int main()
{
    cin>>str;
    int n=str.size();
    string s="chuanzhi";
    int ans=0;
    for(int i=0;i<=n-8;i++){
        if(str.substr(i,8)==s){
            ans++;
        }
    }
    cout<<ans<<endl;
    system("pause");
}