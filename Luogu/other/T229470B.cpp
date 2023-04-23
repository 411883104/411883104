/*
 * @Author: Outsider
 * @Date: 2022-03-12 15:40:16
 * @LastEditors: Outsider
 * @LastEditTime: 2022-03-12 15:48:45
 * @Description: In User Settings Edit
 * @FilePath: \C++\Luogu\T229470B.cpp
 */

#include<iostream>
using namespace std;

int arr[110];

int main()
{
    int n;
    cin>>n;
    int x;
    while(n--){
        cin>>x;
        for(int i=0;i<x;i++){
            cin>>arr[i];
        }
        int ans=0;
        for(int i=0;i<x;i++){
            for(int j=i;j<x;j++){
                for(int k=j;k<x;k++){
                    if(arr[i]+arr[j]==arr[k]){
                        ans++;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    system("pause");
}