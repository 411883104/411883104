//方阵幂次   https://www.lanqiao.cn/problems/1551/learning/
#include<bits/stdc++.h>
using namespace std;
const int N=40;
struct matrix{ int m[N][N]; };  //定义矩阵
matrix A,B;
matrix operator * (const matrix& a, const matrix& b){ //重载*为矩阵乘法。注意const
    matrix c;
    memset(c.m, 0, sizeof(c.m));                     //清零
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            for(int k = 0; k<N; k++)
              c.m[i][j] += a.m[i][k] * b.m[k][j];    //不取模
    return c;
}
matrix pow_matrix(matrix a, int n){                  //矩阵快速幂
    matrix ans;
    memset(ans.m,0,sizeof(ans.m));
    for(int i=0;i<N;i++)
        ans.m[i][i] = 1;
    while(n) {
        if(n&1) ans = ans * a;
        a = a * a;
        n>>=1;
    }
    return ans;
}
int main(){
   int s,q; cin >>s>>q;      //s行s列，q次幂
   for(int i=1;i<=s;i++)
        for(int j=1;j<=s;j++)
            cin >> A.m[i][j];
    B = pow_matrix(A,q);
    for(int i=1;i<=s;i++){
        for(int j=1;j<=s;j++)  cout << B.m[i][j] << " ";
        cout << endl;
    }
	return 0;
}
