//过河卒 https://www.lanqiao.cn/problems/755/learning/
#include<bits/stdc++.h>
using namespace std;
long long dp[40][40];
bool s[40][40];         //标记马的9个控制点
int main(){
    int bx, by, mx, my;
    scanf("%d%d%d%d", &bx, &by, &mx, &my);
    bx += 2; by += 2; mx += 2; my += 2;   //小技巧：坐标点加2，防止越界，因为马能向上向左跳2格
    dp[2][1] = 1;        //初始化
    s[mx][my]=1;          //标记马的控制点
	s[mx-2][my-1]=1;   	s[mx-2][my+1]=1;
	s[mx+2][my-1]=1;	s[mx+2][my+1]=1;
	s[mx-1][my+2]=1;	s[mx-1][my-2]=1;
	s[mx+1][my+2]=1;	s[mx+1][my-2]=1;

    for(int i = 2; i <= bx; i++)
        for(int j = 2; j <= by; j++){
            if(s[i][j])  dp[i][j]=0;   //这个点是控制点，不能走
            else         dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    printf("%lld\n", dp[bx][by]);  //结果是个极大的数字
    return 0;
}
