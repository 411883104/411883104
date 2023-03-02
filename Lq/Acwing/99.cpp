#include<iostream>
using namespace std;

int mm[5005][5005];

int main()
{
	int n,r;
	cin>>n>>r;
	int x,y,w;

	int mx=0,my=0;
	for(int i=0; i<n; i++) {
		cin>>x>>y>>w;
		mm[x+1][y+1]+=w;
		mx=max(mx,x+1);
		my=max(my,y+1);
	}
	for(int i=1; i<=mx; i++) {
		for(int j=1; j<=my; j++) {
			mm[i][j]=(mm[i][j-1]+mm[i-1][j]-mm[i-1][j-1]+mm[i][j]);
		}
	}

	if(r>=mx&&r>=my) {
		cout<<mm[mx][my]<<endl;
		return 0;
	}

	int maxx=0;
	if(r>=my&&r<mx) {
		for(int i=r; i<=mx; i++) {
			maxx=max(maxx,mm[i][my]-mm[i-r][my]);
		}
		cout<<maxx<<endl;
		return 0;
	}
	if(r>=mx&&r<my) {
		for(int i=r; i<=my; i++) {
			maxx=max(maxx,mm[mx][i]-mm[mx][i-r]);
		}
		cout<<maxx<<endl;
		return 0;
	}

	for(int i=r; i<=mx; i++) {
		for(int j=r; j<=my; j++) {
			maxx=max(maxx,mm[i][j]-mm[i-r][j]-mm[i][j-r]+mm[i-r][j-r]);
		}
	}
	cout<<maxx<<endl;
	return 0;
}
