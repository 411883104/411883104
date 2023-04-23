//垒骰子  https://www.lanqiao.cn/problems/132/learning/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7, N = 7;
int p[N] = {0, 4, 5, 6, 1, 2, 3};
struct matrix{ ll m[N][N]; };  //定义矩阵.  注意本题用long long
matrix operator * (const matrix& a, const matrix& b){ //重载*为矩阵乘法。注意const
        matrix c;
        memset(c.m, 0, sizeof(c.m));
        for (int i = 1; i <= 6; i++) {
            for (int j = 1; j <= 6; j++)
                for (int k = 1; k <= 6; k++)
                    c.m[i][j] = (c.m[i][j] + a.m[i][k] * b.m[k][j]) % MOD;//取模
        }
        return c;
}
matrix pow_matrix(matrix a, int n){                  //矩阵快速幂
    matrix ans;
    memset(ans.m,0,sizeof(ans.m));
    for(int i=1;i<7;i++)   ans.m[i][i] = 1;
    while(n) {
        if(n&1) ans = ans * a;
        a = a * a;
        n>>=1;
    }
    return ans;
}
int main() {
    int n, m1; cin >> n >> m1;
    matrix a, x;
    for (int i = 1; i <= 6; i++) {
        x.m[i][1] = 4;
        for (int j = 1; j <= 6; j++) a.m[i][j] = 4;
    }
    for (int i = 0, x, y; i < m1; i++) {
        scanf("%d%d", &x, &y);
        a.m[p[x]][y] = a.m[p[y]][x] = 0;
    }
    matrix b = pow_matrix(a, n - 1) * x;
    int ans = 0;
    for (int i = 1; i <= 6; i++) ans = (ans + b.m[i][1]) % MOD;
    cout << ans << endl;
    return 0;
}
