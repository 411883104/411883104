#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main() {
	int n;
	cin>>n;
	while(n--) {
		string str;
		cin>>str;
		int s0=0,s1=0;
		for(int i=0; i<str.size(); i++) {
			if(str[i]=='0')
				s0++;
			else
				s1++;
		}
		int minn=min(s1,s0);
		if(minn%2==1)
			cout<<"DA"<<endl;
		else
			cout<<"NET"<<endl;
	}
	return 0;
}
