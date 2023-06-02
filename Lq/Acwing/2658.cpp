#include<iostream>
using namespace std;

const int p=1e9+7;

int a[1000005];
int b[1000005];

int main()
{
	long long ans=0;
	int n;
	cin>>n;
	int ma;
	cin>>ma;
	for(int i=ma; i>0; i--) {
		cin>>a[i];
	}
	int mb;
	cin>>mb;
	for(int i=mb; i>0; i--) {
		cin>>b[i];
	}
	int d=0;
	for(int i=max(ma,mb); i>0; i--) {
		d=max(2,max(a[i],b[i])+1);
		ans=(ans*d+(a[i]-b[i]));
		ans%=p;
	}
	cout<<(ans+p)%p<<endl;
	return 0;
}
