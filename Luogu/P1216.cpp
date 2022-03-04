/*
 * @Author: Outsider
 * @Date: 2022-03-04 14:32:23
 * @LastEditors: Outsider
 * @LastEditTime: 2022-03-04 15:03:55
 * @Description: In User Settings Edit
 * @FilePath: \C++\Luogu\P1216.cpp
 */

#include<iostream>

using namespace std;

int n;

const int c=1005;

int arr[c][c];

int dp[c][c]={0};

int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++)
        {
            dp[i][j]+=(max(dp[i-1][j],dp[i-1][j-1])+arr[i][j]);
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
       if(dp[n-1][i]>ans){
           ans=dp[n-1][i];
       }
    }
    cout<<ans<<endl;
    system("pause");
}