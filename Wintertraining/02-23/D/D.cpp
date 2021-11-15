#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int c=1010;
int dp[c][c];
int main() {
	for(int i=1; i<=1000; i++) {
		for(int j=1; j<=1000; j++) {
			dp[i][j]=max(dp[i-1][j],dp[i][j-1])+(__gcd(i,j)==1);
		}
	}
	int t;
	scanf("%d",&t);
	while(t--) {
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",dp[a][b]);
	}
	return 0;
}
