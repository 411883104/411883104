/*
 * @Author: Outsider
 * @Date: 2022-03-04 15:26:57
 * @LastEditors: Outsider
 * @LastEditTime: 2022-03-04 15:28:47
 * @Description: In User Settings Edit
 * @FilePath: \C++\Luogu\P1434.cpp
 */

#include<iostream>

using namespace std;

int r,c;

int arr[105][105];
int cnt[105][105];

void dfs(int x,int y){

}


int main()
{
    cin>>r>>c;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++){
            cnt[i][j]=1;
            cin>>arr[i][j];
        }
    }
}