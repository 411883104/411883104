/*
 * @Author: Outsider
 * @Date: 2022-03-04 21:15:48
 * @LastEditors: Outsider
 * @LastEditTime: 2022-03-04 21:24:47
 * @Description: In User Settings Edit
 * @FilePath: \C++\Luogu\P1168.cpp
 */

#include<iostream>

#include<algorithm>

using namespace std;

const int c=100005;
int arr[c];
int n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    sort(arr+1,arr+n+1);

    for(int i=1;i<=n;i+=2){
        cout<<arr[(i+1)/2]<<endl;;
    }
    

    system("pause");
}