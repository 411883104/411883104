#include<iostream>
#include<algorithm>
using namespace std;
int arr6[8];
int arr9[8];
int main() {
	int cnt=0,vis=0;
	for(int i=6; i<=100000; i*=6) {
		arr6[cnt++]=i;
	}
	for(int i=9; i<=100000; i*=9) {
		arr9[vis++]=i;
	}
	int n;
	cin>>n;
	int minn=100000;

	cout<<vis<<" "<<cnt<<endl;


}
