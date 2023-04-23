//日志统计 2018年第九届省赛C/C++大学A组  https://www.lanqiao.cn/problems/179/learning

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+50;
int num[N];    //num[i]：记录id=i的帖子的赞的数量
int flag[N];   //flag[i]：id=i的贴子曾是热帖
struct post{int id, ts;}p[N];       //记录帖子
int cmp(post x,post y){ return x.ts < y.ts;  } //按时间从小到大排序
int main(){
    int n,d,k; cin>>n>>d>>k;
    for(int i=0;i<n;i++) scanf("%d%d",&p[i].ts,&p[i].id);
    sort(p,p+n,cmp);            //按时间从小到大排序
    for(int i=0,j=0;i<n;i++){
        num[p[i].id]++;
        while(p[i].ts - p[j].ts >= d){
            num[p[j].id]--;     //随着时间流逝，d之前的每个贴的次数都减1
            j++;
        }
        if(num[p[i].id] >= k)   //在区间[i-d,i)上达到k个赞
            flag[p[i].id]=1;
    }
    for(int i=0;i<N;i++)
        if(flag[i]==1) printf("%d\n",i);
    return 0;
}
