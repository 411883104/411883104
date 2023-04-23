/*
 * @Author: Outsider
 * @Date: 2021-12-05 10:35:00
 * @LastEditors: Outsider
 * @LastEditTime: 2021-12-05 10:51:56
 * @Description: In User Settings Edit
 * @FilePath: \C++\Luogu\P1536.cpp
 */
#include<iostream>
using namespace std;

int arr[10005];

int find(int x){
    if(arr[x]==x)
        return x;
    else{
        return arr[x]=find(arr[x]);
    }
}

int main()
{
    int n,m;
    while(cin>>n&&n!=0){
        cin>>m;
        for(int i=1;i<=n;i++){
            arr[i]=i;
        }
        int ans=n;
        for(int i=1;i<=m;i++){
            int a,b;
            
            cin>>a>>b;
            int ta=find(a);
            int tb=find(b);
            if(ta!=tb){
                arr[ta]=tb;
                --ans;
            }
        }
        cout<<ans-1<<endl;

    }
}