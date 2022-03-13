/*
 * @Author: Outsider
 * @Date: 2022-03-12 11:45:42
 * @LastEditors: Outsider
 * @LastEditTime: 2022-03-12 12:11:01
 * @Description: In User Settings Edit
 * @FilePath: \C++\Luogu\P1616.cpp
 */

#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

const int c=10000005;
ll dp[c]={0};
ll t,m;

int main()
{
    cin>>t>>m;
    int w,v;
    for(int i=0;i<m;i++){
        cin>>w>>v;
        for(int j=w;j<=t;j++){
            dp[j]=max(dp[j],dp[j-w]+v);
        }
    }
    cout<<dp[t]<<endl;
    system("pause");
}