/*
 * @Author: Outsider
 * @Date: 2022-02-27 20:10:27
 * @LastEditors: Outsider
 * @LastEditTime: 2022-03-03 10:32:21
 * @Description: In User Settings Edit
 * @FilePath: \C++\ACM\POJ3984.cpp
 */

#include<iostream>
#include<queue>

using namespace std;

int arr[5][5];

struct point{
    int x;
    int y;
    point* next;
};

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

queue<point*>q;

int cnt[5][5];
point* now=new point();
void bfs()
{
    now->x=0;
    now->y=0;
    q.push(now);
    while(!q.empty()){
        now=q.front();
        if(now->x==5&&now->y==5){
            return;
        }
        for(int i=0;i<4;i++){
            int xx=now->x+dx[i];
            int yy=now->y+dy[i];
            if(xx<5&&xx>=0&&yy>=0&&yy<5&&cnt[xx][yy]&&arr[xx][yy]==0){
                point* next=new point();
                next->x=xx;
                next->y=yy;
                next->next=now;
                q.push(next);
                cnt[xx][yy]=0;
            }
        }
        q.pop();
    }
}

void print(point* now){
    if(!now){
        return;
    }
    print(now->next);
    cout<<'('<<now->x<<", "<<now->y<<')'<<endl;
}

int main()
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cnt[i][j]=1;
            cin>>arr[i][j];
        }
    }

    bfs();

    // for(int i=0;i<5;i++)
    // {
    //     for(int j=0;j<5;j++)
    //     {
    //         cout<<cnt[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    print(now);

    system("pause");
}