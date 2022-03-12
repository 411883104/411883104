/*
 * @Author: Outsider
 * @Date: 2022-03-11 20:21:54
 * @LastEditors: Outsider
 * @LastEditTime: 2022-03-11 20:37:43
 * @Description: In User Settings Edit
 * @FilePath: \C++\Luogu\P1439.cpp
 */

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
const int c=100005;
vector<vector<int>> dp(c,vector<int>(c,0));
int arr1[c];
int arr2[c];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr1[i];
    }
    for(int i=1;i<=n;i++){
        cin>>arr2[i];
    }
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            dp[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(arr1[i]==arr2[j]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[n][n]<<endl;

    system("pause");

}