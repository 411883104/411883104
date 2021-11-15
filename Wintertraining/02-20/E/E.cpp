#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int q;
	cin>>q;
	for(int i=0; i<q; i++) {
		string s,t;
		cin>>s>>t;

		if(s.size()<=1) {
			cout<<"NO"<<endl;
			continue;
		} else {
			int vis=0;
			for(int i=0; i<s.size()-1; i++) {
				if(s[i]==t[i]||s[i+1]==t[i+1]||s[i]==t[i+1]||s[i+1]==t[i]||i+2!=s.size()) {
					continue;
				} else {
					if(i+2==s.size()) {
						cout<<"NO"<<endl;
						vis=1;
						break;
					} else {
						if(s[i+2]==t[i+2]||s[i+1]==t[i+1]||s[i+2]==t[i+1]||s[i+1]==t[i+2])
							continue;
						else {
							cout<<"NO"<<endl;
							vis=1;
							break;
						}
					}
				}
			}
			if(vis==0)
				cout<<"YES"<<endl;
		}
	}
	return 0;
}
