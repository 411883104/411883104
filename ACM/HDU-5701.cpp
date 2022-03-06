/*
 * @Author: Outsider
 * @Date: 2022-03-04 18:49:13
 * @LastEditors: Outsider
 * @LastEditTime: 2022-03-04 18:53:58
 * @Description: In User Settings Edit
 * @FilePath: \C++\ACM\HDU-5701.cpp
 */

#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int* arr=new int[n+1];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int k=n/2;

    nth_element(arr,arr+k-1,arr+n);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    system("pause");
}
