//区间最大值 https://www.lanqiao.cn/problems/1205/learning


#include <bits/stdc++.h>
using namespace std;
const int N = 500001;
int n,m;
int a[N],dp[N][40];     //dp_min[N][40];
void st_init(){
    for(int i=1;i<=n;i++)  dp[i][0] = a[i];  //初始化区间长度为1时的值
    int p = (int)(log(double(n)) / log(2.0));    //int p=log2(n);  //两种写法
	for(int k=1;k<=p;k++)                        //用dp递推计算区间
        for(int s=1;s+(1<<k)<=n+1;s++)
            dp[s][k]=max(dp[s][k-1], dp[s+(1<<(k-1))][k-1]); //最大值
}
int st_query(int L,int R){
    int k = (int)(log(double(R-L+1)) / log(2.0));   // int k = log2(R-L+1); //2种方法求k
    return max(dp[L][k],dp[R-(1<<k)+1][k]); //最大值
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)  scanf("%d",&a[i]);
    st_init();
	for(int i=1;i<=m;i++){
		int L,R; scanf("%d%d",&L,&R);
		printf("%d\n",st_query(L,R));
	}
	return 0;
}
