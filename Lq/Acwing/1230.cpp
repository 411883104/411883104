#include<iostream>
using namespace std;

int b[100005];
long long res[100005];
int main(){
	int n,k;
	cin>>n>>k;
	int x;
	for(int i=1;i<=n;i++){
		cin>>x;
		b[i]=(b[i-1]+x)%k;
	}
	long long ans=0;
	for(int i=0;i<=n;i++){
		ans+=res[b[i]];
		res[b[i]]++;
	}
	cout<<ans<<endl;
}
