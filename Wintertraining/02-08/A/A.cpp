#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int c=200005;
int ro[c];
int ra[c];
int find1(int x)
{
	if(ro[x]==x)
		return x;
	else
		return ro[x]=finds(ro[x]);
}
int find2(int x)
{
	if(ra[x]==x)
		return x;
	else
		return ra[x]=finds(ra[x]);
}
int main()
{
	int n,k,l;
	cin>>n>>k>>l;
	for(int i=1;i<=n;i++)
	{
		ro[i]=i;
		ra[i]=i;
	}
	for(int i=1;i<=k;i++)
	{
		int x,y;
		cin>>x>>y;
		int tx=find1(x);
		int ty=find1(y);
	}
 } 
