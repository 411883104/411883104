//外卖店优先级 2019年第十届蓝桥省赛C/C++大学A组
//https://www.lanqiao.cn/problems/184/learning/

//改写自：https://www.jianshu.com/p/1e625af51a3a
#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
int order[N];  //order[id]  第id号店上一次的订单
int prior[N];  //prior[id]  第id号店的优先级
int flag[N];   //flag[id]   第id号店在不在优先缓存中
struct node{int time,id;}a[N];
bool cmp(node a, node b){  //结构体排序
    if(a.id == b.id) return a.time<b.time;
    return a.id<b.id;
}
int main(){
    int m,n,T;  cin>>n>>m>>T;
    for(int i=0;i<m;i++) cin>>a[i].time>>a[i].id;
    sort(a,a+m,cmp);           //按结构体中的时间排序
    for(int i=0;i<m;i++){
        int tt=a[i].time,  id=a[i].id;
        if(tt != order[id]) //如果当前订单不等于上一次的订单，减去它们之间的间隔
            prior[id] -= tt-order[id]-1;
        prior[id] = prior[id] < 0 ? 0: prior[id];  //不小于0
        if(prior[id]<=3)  flag[id]=0;
        prior[id]+=2;
        if(prior[id]> 5)  flag[id]=1;
        order[id] = tt;
    }
    for(int i=1;i<=n;i++)  //最后处理第T时刻
        if(order[i]<T){
            prior[i] -= T-order[i];
            if(prior[i]<=3)
                flag[i]=0;
        }
    int ans=0;
    for(int i=0;i<=n;i++)
        if(flag[i]) ans++;
    cout<<ans;
    return 0;
}
