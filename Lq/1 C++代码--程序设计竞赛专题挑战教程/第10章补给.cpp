//补给 https://www.lanqiao.cn/problems/1050/learning/

#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
double x[20],y[20];
double dis(int a,int b){
    return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}
int n;
double w[20][20],D;
int dp[1<<20][20];  //先用int，比用double省空间
void floyd(){
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                w[i][j]=min(w[i][j],w[i][k]+w[k][j]);
}
int main(){
    cin>>n>>D;
    for(int i=0;i<n;i++)   cin>>x[i]>>y[i];
    for(int i=0;i<n;i++)        //初始化2个村庄之间的距离
        for(int j=i+1;j<n;j++){
            w[i][j]=w[j][i]=dis(i,j);
            if(w[i][j]>D) w[i][j]=w[j][i]=INF; //距离大于D
        }
    floyd();
    memset(dp,0x3f,sizeof(dp));    //初始化最大值
    dp[1][0]=0;               //开始：集合中只有点0，起点和终点都是0
    for(int S=0;S<(1<<n);S++)//从小集合扩展到大集合，集合用S的二进制表示
        for(int j=0;j<n;j++) //枚举点j
             if((S>>j&1))
                for(int k=0;k<n;k++) //枚举到达j的点k，k属于集合S-j
                     if(((S^(1<<j))>>k&1))
                        dp[S][j]=min(dp[S][j],dp[S^(1<<j)][k]+int(5000*w[k][j])) ;
    int ans=INF;    //最后找到所有路径中最短的
    for(int i=1;i<n;i++)
        ans=min(ans,int(w[i][0]*5000)+dp[(1<<n)-1][i]); //加上回到起点的长度
    printf("%.2f",ans/5000.0);
}
