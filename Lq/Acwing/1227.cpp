#include<iostream>
using namespace std;
pair<int,int> c[100005];
int n,k;
bool check(int mm)
{
	int ans=0;
	for(int i=0; i<n; i++) {
		int x=c[i].first/mm;
		int y=c[i].second/mm;
		ans+=x*y;
	}
	return ans>=k;
}
int main()
{
	cin>>n>>k;
	int maxx=0;
	for(int i=0; i<n; i++) {
		cin>>c[i].first>>c[i].second;
		maxx=max(max(c[i].first,c[i].second),maxx);
	}
	int ll=0,rr=maxx+1;
	while(ll<rr) {
		int mm=ll+((rr-ll)>>1);
		if(check(mm)) {
			ll=mm+1;
		} else {
			rr=mm;
		}
	}
	cout<<ll-1<<endl;
}
