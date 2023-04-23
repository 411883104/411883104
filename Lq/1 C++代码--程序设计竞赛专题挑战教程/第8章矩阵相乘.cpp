//æÿ’Ûœ‡≥À https://www.lanqiao.cn/problems/1550/learning/


#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n,m,k;
int A[N][N],B[N][N],C[N][N];
int multi(int  u, int v){
    int sum = 0;
	for (int j=0; j<m; j++)  sum += (A[u][j] * B[j][v]);
	return sum;
}
int main(){
    cin >> n >> m >> k;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> A[i][j];
    for(int i=0;i<m;i++)
        for(int j=0;j<k;j++)
            cin >> B[i][j];
    for(int i=0;i<n;i++)
		for(int j=0;j<k;j++)
            C[i][j] = multi(i, j);
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++)
            cout << C[i][j] << " ";
        cout << endl;
    }
	return 0;
}
