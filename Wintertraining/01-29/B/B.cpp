#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<map>
using namespace std;
map<string,int>test;
int main() {

	string str;
	while(getline(cin,str)) {
		if(str=="")
			break;
		else
			for(int i=str.length(); i>=0; i--) {
				string cop;
				cop=str.substr(0,i);
				test[cop]++;
			}
	}
//	for(auto i : test) {
//		cout<<i.first<<" "<<i.second<<endl;
//	}
	while(cin>>str) {
		cout<<test[str]<<endl;
	}
	return 0;
}
