/*
 * @Author: Outsider
 * @Date: 2022-03-04 15:26:57
 * @LastEditors: Outsider
 * @LastEditTime: 2022-03-04 16:12:11
 * @Description: In User Settings Edit
 * @FilePath: \C++\Luogu\P1434.cpp
 */

#include<iostream>

using namespace std;

int r,c;

int arr[105][105];

int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

int ans=1;
int minn=0;

void dfs(int x,int y,int sum){
    if((arr[x][y]-minn+1+sum)<=ans){
        return;
    }

    int cnt=0;
    for(int i=0;i<4;i++){
        int xx=x+dx[i];
        int yy=y+dy[i];
        cnt=(cnt||(xx>=0&&xx<r&&yy>=0&&yy<c&&arr[xx][yy]<arr[x][y]));
    }
    if(cnt){
        for(int i=0;i<4;i++){
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(xx>=0&&xx<r&&yy>=0&&yy<c){
                if(arr[xx][yy]<arr[x][y]){
                    dfs(xx,yy,sum+1);
                }
            }  
        }
    }
    else{
        ans=max(ans,sum);
        return;
    }
}


int main()
{
    cin>>r>>c;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++){
            cin>>arr[i][j];
            minn=min(minn,arr[i][j]);
        }
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++){
            dfs(i,j,1);
        }
    }
    cout<<ans<<endl;

    system("pause");
}