#include<iostream>
using namespace std;

int s[100005];
// 0 Í¬Àà 1 ³Ô 2±»³Ô
int v[100005];

int find(int x)
{
	if(x==s[x]) {
		return x;
	}
	int t=s[x];
	s[x]=find(s[x]);
	v[x]=(v[x]+v[t])%3;
	return s[x];
}
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		s[i]=i;
	}
	int op,x,y;
	int ans=0;
	for(int i=1; i<=k; i++) {
		cin>>op>>x>>y;
		if(x>n||y>n) {
			ans++;
		} else {
			int xx=find(x);
			int yy=find(y);
			if(xx==yy) {
				if()
			}
			if(xx==yy) {
				ans++;
			}
		}
	}
}
cout<<ans<<endl;
}
