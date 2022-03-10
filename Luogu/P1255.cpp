/*
 * @Author: Outsider
 * @Date: 2022-03-06 21:16:30
 * @LastEditors: Outsider
 * @LastEditTime: 2022-03-06 21:22:10
 * @Description: In User Settings Edit
 * @FilePath: \C++\Luogu\P1255.cpp
 */

#include<iostream>

using namespace std;

long long dp[5005];


int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        dp[i]=0;
    }
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[n]<<endl;
    system("pause");
}