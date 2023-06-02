#include<iostream>
#include<algorithm>
//#include<string>
using namespace std;

struct T {
	int s,a,e;
	int t;
};

T tol[1005];

bool cmp(T a,T b)
{
	return a.t<b.t;
}

int main()
{
	int n;
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>tol[i].s>>tol[i].a>>tol[i].e;
		tol[i].t=tol[i].s+tol[i].a+tol[i].e;
	}

	sort(tol,tol+n,cmp);

	int ans=0;
	int it=0;
	for(int i=0; i<n; i++) {
		ans+=(it+tol[i].s+tol[i].a);
		it+= tol[i].t;
	}
	cout<<ans<<endl;
	return 0;
}
