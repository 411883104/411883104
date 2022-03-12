/*
 * @Author: Outsider
 * @Date: 2022-03-12 10:08:55
 * @LastEditors: Outsider
 * @LastEditTime: 2022-03-12 11:32:16
 * @Description: In User Settings Edit
 * @FilePath: \C++\Luogu\P1048.cpp
 */

// #include<iostream>
// #include<algorithm>

// using namespace std;

// int dp[105][1005]={0};
// int t,m;

// int main()
// {
//     cin>>t>>m;
//     int w,v;
//     for(int i=1;i<=m;i++){
//         cin>>w>>v;
//         for(int j=1;j<=t;j++){
//             if(j>=w){
//                 dp[i][j]=max(dp[i-1][j],dp[i-1][j-w]+v);
//             }
//             else{
//                 dp[i][j]=dp[i-1][j];
//             }
//         }
//     }
//     cout<<dp[m][t]<<endl;
//     system("pause");
// }

#include<iostream>
#include<algorithm>

using namespace std;

int dp[1005]={0};
int t,m;

int main()
{
    cin>>t>>m;
    int w,v;
    for(int i=1;i<=m;i++){
        cin>>w>>v;
        for(int j=t;j>=w;j--){
            dp[j]=max(dp[j],dp[j-w]+v);
        }
    }
    cout<<dp[t]<<endl;
    system("pause");
}