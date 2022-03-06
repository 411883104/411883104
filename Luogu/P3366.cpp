/*
 * @Author: Outsider
 * @Date: 2022-03-04 16:45:58
 * @LastEditors: Outsider
 * @LastEditTime: 2022-03-04 17:30:23
 * @Description: In User Settings Edit
 * @FilePath: \C++\Luogu\P3366.cpp
 */

#include<iostream>
#include<algorithm>
using namespace std;

int n,m;

struct Edge{
    int u,v,w;
};

int arr[5005];

int find(int x)
{
    if(arr[x]==x){
        return x;
    }
    return arr[x]=find(arr[x]);
}

bool cmp(Edge a,Edge b)
{
    return a.w<b.w;
}

int main()
{
    cin>>n>>m;
    Edge edge[200005];
    for(int i=0;i<m;i++){
        cin>>edge[i].u>>edge[i].v>>edge[i].w;
    }

    for(int i=1;i<=n;i++){
        arr[i]=i;
    }

    sort(edge,edge+m,cmp);

    int ans=0;
    int cnt=0;
    for(int i=0;i<m;i++){
        int x=find(edge[i].u);
        int y=find(edge[i].v);
        if(x==y){
            continue;
        }
        arr[x]=y;
        ans+=edge[i].w;
        if(++cnt==n-1){
            break;
        }
    }
    cnt=0;
    for(int i=1;i<=n;i++){
        if(arr[i]==i){
            cnt++;
        }
    }
    if(cnt==1){
        cout<<ans<<endl;
    }
    else{
        cout<<"orz"<<endl;
    }

    system("pause");
}