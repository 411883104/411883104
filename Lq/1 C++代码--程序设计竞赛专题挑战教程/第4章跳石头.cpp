//跳石头 https://www.lanqiao.cn/problems/364/learning/
#include<cstdio>
int len,n,m;
int stone[50005];
bool check(int d){   //检查距离d是否合适
    int num=0;       //num记录搬走石头的数量
    int pos=0;       //当前站立的石头
    for(int i=1;i<=n;++i)
        if(stone[i]-pos < d)  num++;          //第i块石头可以搬走
        else                  pos = stone[i];   //第i块石头不能搬走
    if(num <= m) return true;  //要移动的石头比m少，满足条件
    else return false;         //要移动的石头比m多，不满足条件
}
int main(){
    scanf("%d%d%d",&len,&n,&m);
    for(int i=1;i<=n;++i) scanf("%d",&stone[i]);
    int L=0,R=len,mid;
    while(L<R){
        mid = L+(R-L)/2;
        if(check(mid)) L = mid+1;  //满足条件，说明mid小了，调大一点
        else           R = mid-1;  //不满足条件，说明mid大了，调小一点

    }
    if(!check(L)) L -= 1;
    printf("%d\n",L);
    return 0;
}
