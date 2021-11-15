/*
 * @Author: Outsider
 * @Date: 2021-10-30 21:45:43
 * @LastEditors: Outsider
 * @LastEditTime: 2021-11-13 11:10:40
 * @Description: In User Settings Edit
 * @FilePath: \C++\C++NewFeature\lambda.cpp
 */
#include<iostream>
using namespace std;
int main()
{
    int a=10;
    [&]()->int{
        cout<<a<<endl;
    };
    return 0;
    system("pause");
}
