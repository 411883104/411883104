#include<iostream>
using namespace std;

int prime[200000];
int vis[2400000];

int main()
{
	int cnt=0;
	for(int i=2; i<=2333333; i++) {
		if(vis[i]==0) {
			prime[cnt++]=i;
		}
		for(int j=0; j<cnt&&i*prime[j]<=2333333; j++) {
			vis[i*prime[j]]=1;
			if(i%prime[j]==0) {
				break;
			}
		}
	}

	int ans=0;
	for(int i=2333333; i<=23333333; i++) {
		int a=i;
		int c=0;
		for(int j=0; j<cnt&&prime[j]*prime[j]<=a; j++) {
			while(a%prime[j]==0) {
				c++;
				a/=prime[j];
			}
		}
		if(a>1) {
			c++;
		}
		if(c==12) {
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
