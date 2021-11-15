#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n,a,b;
	while(cin>>n>>a>>b) {
		int lcm=1;
		for(int i=0; i<n; i++) {
			int x;
			cin>>x;
			lcm=x*lcm/__gcd(lcm,x);
		}
		if(lcm==1) {
			cout<<b-a+1<<endl;
		} else {

			int ans=0;
			for(int i=lcm; i<=b; i=i+lcm) {
				ans++;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
