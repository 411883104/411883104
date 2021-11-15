#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
int arr[100];
int main() {
	string n;
	cin>>n;
	map<int,string>m;
	m[0]="zero";
	m[1]="one";
	m[2]="two";
	m[3]="three";
	m[4]="four";
	m[5]="five";
	m[6]="six";
	m[7]="seven";
	m[8]="eight";
	m[9]="nine";
	int sum=0;
	for(int i=n.size()-1; i>=0; i--) {
		sum+=n[i]-48;
	}
	int cnt=-1;
	if(sum==0)//要注意0的情况 
		cout<<m[0]<<endl;
	else {
		while(sum) {
			arr[++cnt]=sum%10;
			sum/=10;
		}
		for(int i=cnt; i>=0; i--) {
			cout<<m[arr[i]]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
