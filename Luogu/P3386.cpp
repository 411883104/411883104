/*
 * @Author: Outsider
 * @Date: 2022-03-10 21:02:16
 * @LastEditors: Outsider
 * @LastEditTime: 2022-03-11 19:33:33
 * @Description: In User Settings Edit
 * @FilePath: \C++\Luogu\P3386.cpp
 */


#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const int c=50005;

vector<int> arr[c];

int cnt[c]={0};
int n,m,e;
int vis[c];
bool dfs(int x)
{
    for(int i=0;i<arr[x].size();i++)
    {
        if(vis[i]==1){
            continue;
        }
        vis[i]=1;
        if(cnt[arr[x].at(i)]==0||dfs(cnt[arr[x].at(i)]))
        {
            cnt[arr[x].at(i)]=x;
            return true;
        }
    }
    return false;
}

int main()
{
    cin>>n>>m>>e;
    int u,v;
    for(int i=0;i<e;i++)
    {
        cin>>u>>v;
        arr[u].push_back(v);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        ans+=dfs(i);
    }
    cout<<ans<<endl;
    system("pause");
}