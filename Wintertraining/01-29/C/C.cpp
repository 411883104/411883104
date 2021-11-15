#include<iostream>
#include<algorithm>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
int t[15];
struct student {
	string str;
	int num;
	int arr[15];
	int sum;
};
bool cmp(student a,student b) {
	if(a.sum!=b.sum) {
		return a.sum>b.sum;
	} else {
		return a.str<b.str;
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,g;
	student stu[1010];
	while(cin>>n&&n!=0) {
		cin>>m>>g;
		for(int i=1; i<=m; i++) {
			cin>>t[i];
		}
		for(int i=1; i<=n; i++) {
			stu[i].sum=0;
			cin>>stu[i].str>>stu[i].num;
			for(int j=1; j<=stu[i].num; j++) {
				cin>>stu[i].arr[j];
				stu[i].sum+=t[stu[i].arr[j]];
			}
		}
		sort(stu+1,stu+n+1,cmp);
		int s=0;
		for(int i=1; i<=n; i++) {
			if(stu[i].sum>=g) {
				s++;
			}
		}
		cout<<s<<endl;
		for(int i=1; i<=s; i++) {
			cout<<stu[i].str<<" "<<stu[i].sum<<endl;
		}
	}
	return 0;
}
