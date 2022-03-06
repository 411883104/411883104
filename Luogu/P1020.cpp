/*
 * @Author: Outsider
 * @Date: 2022-03-05 09:03:52
 * @LastEditors: Outsider
 * @LastEditTime: 2022-03-05 10:20:40
 * @Description: In User Settings Edit
 * @FilePath: \C++\Luogu\P1020.cpp
 */

#include<iostream>
#include<algorithm>

using namespace std;

const int c=100005;
int arr[c];

int dp[c]={0};
int main()
{
    int a=1;
    while(cin>>arr[a]){
        ++a;
    }
    int maxx=1;
    for(int i=1;i<=a-1;i++){
        dp[i]=1;
        for(int j=1;j<i;j++){
            if(arr[i]<=arr[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        maxx=max(maxx,dp[i]);
    }
    cout<<maxx<<endl;
    maxx=1;
    for(int i=1;i<=a-1;i++){
        dp[i]=1;
        for(int j=1;j<i;j++){
            if(arr[i]>arr[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        } 
        maxx=max(maxx,dp[i]);
    }
    cout<<maxx<<endl;

    system("pause");
}