/*
 * @Author: Outsider
 * @Date: 2022-02-27 19:00:51
 * @LastEditors: Outsider
 * @LastEditTime: 2022-02-27 20:05:30
 * @Description: In User Settings Edit
 * @FilePath: \C++\ACM\POJ1321.cpp
 */
#include<iostream>

using namespace std;

int n,k;
char arr[10][10];

int cnt[10];

int ans=0,ant=0;

void dfs(int num)
{
    if(ant==k){
        ans++;
        return;
    } 
    if(num>=n){
        return;
    }
    
    for(int i=0;i<n;i++)
    {
        if((arr[num][i]=='#')&&cnt[i]){
            cnt[i]=0;
            ant++;
            dfs(num+1);
            cnt[i]=1; 
            ant--;
        }
    }
    dfs(num+1);
}

int main()
{
    while(cin>>n>>k&&n!=-1&&k!=-1)
    {
        ans=0;
        ant=0;
        for(int i=0;i<n;i++){
            cnt[i]=1;
            for(int j=0;j<n;j++)
            {
                cin>>arr[i][j];
            }
        }
        dfs(0);
        cout<<ans<<endl;
    }
    system("pause");
}