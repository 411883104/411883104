#include<iostream>
using namespace std;
typedef long long ll; 
int main() {
	ll a,b,p;
	cin>>a>>b>>p;
	ll base=a;
	ll res=1;
	//判断指数是否为0 
	if(b==0) {
		cout<<1%p<<endl;
	} else {

		while(b>0) {
			if(b&1)//如果当前b为奇数，则将b减1，即将当前结果值乘以底。
				res=(res*base)%p;
			base=(base*base)%p;//指数降为原来的一半。
			b>>=1;
		}
		cout<<res<<endl;
	}
	return 0;
}
