#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int n;
	cin>>n;
	int ans=0;
	for(int i=1;i<n;i++){
		if(((i*i)%n)*2<n){
			ans++;
		}
	}
	cout<<ans<<endl;
}
