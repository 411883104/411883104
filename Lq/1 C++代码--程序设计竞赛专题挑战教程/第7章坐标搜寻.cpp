//坐标搜寻  https://www.lanqiao.cn/problems/1546/learning/
#include <bits/stdc++.h>
using namespace std;
double x[20],y[20],dp[1<<16][21];
double dist(int a,int b) {   //计算两个坐标点之间的距离
    return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}
int main(){
    memset(dp,0x7f,sizeof(dp));    //初始化最大值
    int n; cin>>n;
    x[0]=0; y[0]=0;      //起点是(0,0)
    for(int i=1;i<=n;i++) scanf("%lf%lf",&x[i],&y[i]);   //读n个点
    n = n+1;   //共n+1个点

    dp[1][0]=0;                //开始：集合中只有点0，起点和终点都是0
    for(int S=1; S<(1<<n); S++) //从小集合扩展到大集合，集合用S的二进制表示
        for(int j=0; j<n; j++)     //枚举点j
            for(int k=0; k<n; k++)  //枚举到达j的点k，k属于集合S-j
                if( ((S>>j) & 1) && ((S^(1<<j)) >> k & 1) )
                     dp[S][j] = min(dp[S][j],dp[S^(1<<j)][k] + dist(k,j));

    double ans = dp[(1<<n)-1][0];   //最后找到所有路径中最短的
    for(int i=1;i<n;i++){
        double p = dp[(1<<n)-1][i];
        if(ans>p) ans=p;
    }
    printf("%.2f\n",ans);
    return 0;
}
