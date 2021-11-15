#include<iostream>
#include<cstring>
#include<map>
using namespace std;
map<int,int>v;
int main() 
{
	int n,m;
	cin>>n>>m;
	int sum=1;
	
	for(int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int index=sum;
		sum+=(x*y);
		for(int j=index;j<sum;j++)
		{
			v[j]=i;
		}
	}
	while(m--)
	{
		int q;
		scanf("%d",&q);
		cout<<v[q]<<endl;
	}
	return 0;
}
