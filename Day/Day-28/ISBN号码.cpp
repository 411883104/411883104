#include<iostream>
#include<cstring>
using namespace std;
int main() {
	string str;
	cin>>str;
	int sum=0;
	int vis=1;
	for(int i=0; i<str.size()-2; i++) {

		if(str[i]!='-') {
			sum+=(str[i]-48)*(vis++);
		}
	}
	if(str[str.size()-1]!='X') {

		if((str[str.size()-1]-48)==sum%11) {
			cout<<"Right"<<endl;
		} else {
			if(sum%11==10) {
				for(int i=0; i<str.size()-1; i++)
					cout<<str[i];
				cout<<'X'<<endl;
			} else {

				for(int i=0; i<str.size()-1; i++)
					cout<<str[i];
				cout<<sum%11<<endl;
			}
		}
	} else {
		if(sum%11==10) {
			cout<<"Right"<<endl;
		} else {
			for(int i=0; i<str.size()-1; i++)
				cout<<str[i];
			cout<<sum%11<<endl;
		}
	}
	return 0;
}
