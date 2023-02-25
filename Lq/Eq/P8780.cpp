#include<iostream>

using namespace std;

int main(){
	long long a,b,n;
	cin>>a>>b>>n;
	long long tol=a*5+b*2;
	long long ans=n/tol;
	long long remnant=n%tol;
	if(remnant==0){
		cout<<ans*7<<endl;
	}else{
		ans*=7;
		for(int i=1;i<=5;i++){
			if(remnant<=a*i){
				ans+=i;
				cout<<ans<<endl;
				return 0;
			}
		}
		remnant-=5*a;
		ans+=5;
		for(int i=1;i<=2;i++){
			if(remnant<=b*i){
				ans+=i;
				cout<<ans<<endl;
				return 0;
			} 
		}
	}
}
