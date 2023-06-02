#include<iostream>
#include<deque>
using namespace std;

int vis[1005];
int prime[1005];
int n,k;
int cnt=0;
int main()
{
	int t;
	cin>>t;
	for(int i=2; i<=1000; i++) {
		if(vis[i]==0) {
			prime[cnt++]=i;
		}
		for(int j=0; j<cnt&&prime[j]*i<=1000; j++) {
			vis[prime[j]*i]=1;
			if(i%prime[j]==0) {
				break;
			}
		}
	}

	while(t--) {
		cin>>n>>k;
		int ans=0;
		for(int j=0; j<=cnt&&prime[j]<=n; j++) {
			for(int i=1; i<cnt-1&&prime[i]<=n; i++) {
				if(prime[i-1]+prime[i]==prime[j]-1) {
					ans++;
				}
			}
		}
		if(ans>=k) {
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}
	}

}
