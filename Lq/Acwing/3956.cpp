#include<iostream>
using namespace std;
int a[100005];

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=a[i-1]+a[i];
	}
	long long ans=0;
	if(a[n]%3==0){
		int res=a[n]/3;
		int cnt=0;
		for(int i=1;i<n-1;i++){
			if(a[i]==res)
				cnt++;
			if(a[n]-a[i+1]==res){
				ans+=cnt;
			}
		}
	}
	cout<<ans<<endl;
}
