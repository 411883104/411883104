/*
 * @Author: Outsider
 * @Date: 2021-11-30 19:51:37
 * @LastEditors: Outsider
 * @LastEditTime: 2021-11-30 19:56:05
 * @Description: In User Settings Edit
 * @FilePath: \DataStructureTest\test3\arrary.cpp
 */
#include<iostream>
using namespace std;
void print(int **a){
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<a[i*j+j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int a[2][2]={1,2,3,4};
}