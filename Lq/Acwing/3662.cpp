#include<iostream>
#include<algorithm>
using namespace std;

int a[100005];
int b[100005];

long long tt[100005];
int n;
int lowbit(int x)
{
	return x&(-x);
}

void add(int x,long long val)
{
	for(int i=x; i<=n; i+=lowbit(i)) {
		tt[i]=max(tt[i],val);
	}
}

int query(int x)
{
	long long ans=0;
	for(int i=x; i>0; i-=lowbit(i)) {
		ans=max(tt[i],ans);
	}
	return ans;
}

int main()
{
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+n+1);

	int s=unique(b+1,b+n+1)-b-1;

	long long res=0;
	for(int i=1; i<=n; i++) {
		int x=lower_bound(b+1,b+s+1,a[i])-b;
		long long ans=a[i]+query(x-1);
		
		res=max(ans,res);add(x,ans);
		
	}
	cout<<res<<endl;
}
