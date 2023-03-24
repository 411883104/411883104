#include<iostream>
using namespace std;

int a0,a1,b0,b1;

int gcd(int a,int b)
{
	if(b==0) {
		return a;
	}
	return gcd(b,a%b);
}


int main()
{
	int tt;
	cin>>tt;
	while(tt--) {

		int ans=0;
		cin>>a0>>a1>>b0>>b1;
		int ll=a1,rr=b1;
		for(int i=a1;i<=b1; i++) {
			if(gcd(i,a0)==a1) {
				int t=gcd(i,b0);
				if(i*b0/t==b1) {
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
}
