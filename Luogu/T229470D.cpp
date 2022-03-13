/*
 * @Author: Outsider
 * @Date: 2022-03-12 16:10:27
 * @LastEditors: Outsider
 * @LastEditTime: 2022-03-12 16:12:48
 * @Description: In User Settings Edit
 * @FilePath: \C++\Luogu\T229470D.cpp
 */

#include<iostream>
using namespace std;

int arr[100005];

int main()
{
    int n,k;
    cin>>n>>k;
    arr[0]=0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        arr[i]=arr[i]*arr[i];
        arr[i]+=arr[i-1];
    }
    
}