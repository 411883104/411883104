#include<iostream>
using namespace std;

int dp[1<<21];
int v[200];

int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0; i<(1<<m); i++) {
		dp[i]=-1;
	}
	for(int i=1; i<=n; i++) {
		int x;
		for(int j=1; j<=k; j++) {
			cin>>x;
			v[i]|=(1<<(x-1));
		}
		dp[v[i]]=1;
	}
	for(int i=0; i<(1<<m); i++) {
		if(dp[i]!=-1) {
			for(int j=1; j<=n; j++) {
				if(dp[v[j]|i]==-1||dp[v[j]|i]>dp[i]+1) {
					dp[v[j]|i]=dp[i]+1;
				}
			}
		}
	}
	cout<<dp[(1<<m)-1]<<endl;
	return 0;
}
