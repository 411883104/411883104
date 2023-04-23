//七段码：2020年第十一届省赛   https://www.lanqiao.cn/problems/595/learning/

#include<bits/stdc++.h>
using namespace std;
int e[10][10] = {0};
int s[8] = {0}, vis[8] = {0};
int ans = 0;
void init() {
    for (int i = 1; i <= 7; i++)  s[i] = i;
}
int find_set(int x){            //用“路径压缩”优化的查询
    if(x != s[x])  s[x] = find_set(s[x]);    //路径压缩
    return s[x];
}
void merge_set(int x, int y){    //合并
    x = find_set(x);  y = find_set(y);
    if(x != y) s[x] = s[y];      //y成为x的父亲，x的集是y
}

void check(){
    init();
    for (int i = 1; i <= 7; i++)
         for(int j=1;j<=7;j++)
             if (e[i][j] && vis[i] && vis[j])
                    merge_set(i, j);
    int flag = 0;
    for (int j = 1; j <= 7; j++)
         if (vis[j] && s[j] == j)
             flag++;
    if (flag == 1) ans++;
}

void dfs(int k) {   //深搜到第k个灯
    if (k == 8)  check();     //检查连通性
    else {
        vis[k] = 1;  //点亮这个灯
        dfs(k + 1);  //继续搜下一个灯
        vis[k] = 0;  //关闭这个灯
        dfs(k + 1);  //继续搜下一个灯
    }
}
int main() {
//a b c d e f g
//1 2 3 4 5 6 7
    e[1][2] = e[1][6] = 1;
    e[2][1] = e[2][3] = e[2][7] = 1;
    e[3][2] = e[3][4] = e[3][7] = 1;
    e[4][3] = e[4][5] = 1;
    e[5][4] = e[5][6] = e[5][7] = 1;
    e[6][1] = e[6][5] = e[6][7] = 1;
    e[7][2] = e[7][3] = e[7][5] = e[7][6] = 1;
    dfs(1); //从第一个灯开始深搜
    cout << ans ;
    return 0;
}
