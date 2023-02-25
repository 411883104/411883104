#include<iostream>
using namespace std;

int main(){
	string s;
	int ans=0;
	for(int i=0;i<5;i++){
		cin>>s;
		if(s[0]==s[2]&&s[1]+1==s[3]){
			ans++;
		}
	}
	cout<<ans<<endl;
} 
