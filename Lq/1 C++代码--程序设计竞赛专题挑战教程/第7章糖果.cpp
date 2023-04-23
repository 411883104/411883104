//糖果 2019年第十届省赛  https://www.lanqiao.cn/problems/186/learning/


#include<bits/stdc++.h>
using namespace std;
int dp[1<<20]; //dp[v]:得到口味为v时需要的最少糖果包数量
int kw[100];   //kw[i]：第i包糖果的口味
int main() {
    int n,m,k;    cin>>n>>m>>k;
    int tot = (1<<m)-1;      //tot：二进制是m个1，表示所有m种口味
    memset(dp, -1, sizeof dp);
    for (int i=0; i<n; i++){
        int tmp=0;
        for (int j=0; j<k; j++){  //输入一包糖果中k种口味
            int x;  cin>>x;
            tmp|=(1<<x-1);  //状态压缩：把这包糖果种k种口味用tmp表示
        }
        kw[i]=tmp;   //kw[i]：第i包糖果的口味
        dp[tmp]=1;   //dp[v]:得到口味为v时需要的最少糖果包数量
    }
    for (int i=0; i<=tot; i++)  //遍历所有口味组合
        if (dp[i]!=-1)          //已存在得到口味i的最少糖果包数量
            for (int j=0; j<n; j++)  {  //检查给定的n包糖果
                int tmp = kw[j];
                if (dp[i|tmp]==-1 || dp[i|tmp]>dp[i]+1) dp[i|tmp] = dp[i]+1; //状态转移
            }
    cout << dp[tot];  //得到所有口味tot的最少糖果包数量
    return 0;
}
