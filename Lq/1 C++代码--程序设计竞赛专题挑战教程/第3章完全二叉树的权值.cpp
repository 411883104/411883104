//完全二叉树的权值  2019年第十届省赛C/C++A组
// https://www.lanqiao.cn/problems/183/learning

#include<bits/stdc++.h>
using namespace std;
int a[101000];
int p(int deep){                 //返回第deep层的数量，1,2,4,8,16,...
    return pow(2,deep);
}
int main(){
    int n,mindeep=1,i=2,deep=2;
    scanf("%d %d",&n,&a[1]);
    long long maxx = a[1];       //最大和，初值为第一层的和
    for(i=2;i<=n;i++) scanf("%d",&a[i]);
    i = 2;                       //第二层从a[2]开始
    while(i<=n){
        long long sum=0;
        for(;i<p(deep)&&i<=n;i++)  sum+=a[i];   //计算第deep层的和
        if(sum > maxx) maxx = sum, mindeep = deep;
        deep++;
  }
   cout << mindeep;
   return 0;
}
