//砍竹子 2022年第十三届省赛C/C++大学B组
//https://www.dotcpp.com/oj/problem2663.html

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200010,M = 10;       //一棵竹子砍到1，最多6次,这里设M=10次
ll f[N][M];                       //f[i][j]：第i棵竹子被砍后的高度，f[i][0]是砍最后一刀后高度
ll stk[M];
int main(){
    int n; scanf("%d",&n);
    int ans = 0;
    for(int i = 0;i < n;i++){
        ll x;    scanf("%lld",&x);
        int top = 0;
        while(x > 1){             //第i棵竹子要砍几次？砍top次
            stk[++top] = x;//记录高度
            x = sqrt(x / 2 + 1); //砍后更新高度
        }
        ans += top;               //每棵竹子单独砍，总共砍多top刀
        for(int j = 0,k = top;k;j++,k--)
            f[i][j] = stk[k];    //第i棵竹子
    }
    for(int j = 0;j < M;j++)
        for(int i = 1;i < n;i++)
            if(f[i][j] && f[i][j] == f[i - 1][j]) //如果与相邻的竹子等高，就可以一起砍，少砍了一刀
                ans--;
    printf("%d\n",ans);
    return 0;
}
