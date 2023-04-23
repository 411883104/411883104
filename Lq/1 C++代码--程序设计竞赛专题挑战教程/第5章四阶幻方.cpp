//四阶幻方 2015年第六届决赛  https://www.lanqiao.cn/problems/689/learning
#include <bits/stdc++.h>
using namespace std;
int vis[17];
int m[5][5];
int cnt = 0;
bool judge() {
    for (int i = 0; i < 4; i ++ ) { //四行四列的和
        if (m[i][0] + m[i][1] + m[i][2] + m[i][3] != 34) return 0;
        if (m[0][i] + m[1][i] + m[2][i] + m[3][i] != 34) return 0;
    }
    if (m[0][0] + m[1][1] + m[2][2] + m[3][3] != 34) return 0;//对角线
    if (m[0][3] + m[1][2] + m[2][1] + m[3][0] != 34) return 0;
    return 1;
}
void dfs(int n) {
    if (n == 16) {
        if (judge())  cnt ++;
        return;
    }
    if (n%4 == 0)       //简单剪枝：检查第一行的和是不是34
      if (m[n/4 - 1][0] + m[n/4 - 1][1] + m[n/4 - 1][2] + m[n/4 - 1][3] != 34)
         return;

    for (int i = 2; i <= 16; i ++ ) {
        if (vis[i] == 0) {
            m[n/4][n%4] = i;
            vis[i] = 1;
            dfs(n + 1);
            vis[i] = 0;
        }
    }
}
int main() {
     m[0][0] = 1;
     dfs(1);
     cout << cnt;
    return 0;
}
