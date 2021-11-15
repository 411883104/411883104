//#include<iostream>
//#include<cstring>
//using namespace std;
//const int c=200005;
//int arr[c];
//int tree[c];
//int lowbit(int x)
//{
//	return x&(-x);
//}
//void set(int index,int x,int len)
//{
//	for(int i=index;i<=len;i+=lowbit(i))
//	{
//		tree[i]+=x;
//	}
//}
//int getsum(int x)
//{
//	int sum=0;
//	for(int i=x;i>0;i-=lowbit(i))
//	{
//		sum+=tree[i];
//	}
//	return sum;
//}
//int main()
//{
//	int n,m;
//	cin>>n>>m;
//	for(int i=1;i<=n;i++)
//	{
//		cin>>arr[i];
//		set(i,arr[i],n);
//	}
//	while(m--)
//	{
//		int x,y;
//		cin>>x>>y;
//		int ans=getsum(y)-getsum(x-1);
//		if(ans==0)
//		{
//			cout<<1<<endl;
//		}
//		else
//		{
//			cout<<0<<endl;
//		}
//	}
// } 

#include<iostream>
#include<algorithm>
using namespace std;
const int c=200005;
int arr[c];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int sum1=0,sum2=0;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		if(arr[i]==1)
		{
			sum1++;
		}
		else
		{
			sum2++;
		}
		
	}
	int ans=min(sum1,sum2);
	while(m--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int vis=y-x+1;
		if(!(vis%2)&&(vis/2<=ans))
		{
			cout<<1<<endl;
		}
		else
		{
			cout<<0<<endl;
		}
	}
	return 0;
}
