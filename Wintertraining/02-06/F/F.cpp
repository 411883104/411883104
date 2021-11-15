#include<iostream>
#include<algorithm>
using namespace std;
int vis[12];
int main() {
	int l,r;
	scanf("%d%d",&l,&r);
	for(int i=l; i<=r; i++) {
		int x=i;
		for(int i=0; i<12; i++) {
			vis[i]=0;
		}
		while(x) {
			vis[x%10]++;
			if(vis[x%10]>1)
				break;
			x/=10;
		}
		if(x==0) {
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<"-1"<<endl;
	return 0;
}
