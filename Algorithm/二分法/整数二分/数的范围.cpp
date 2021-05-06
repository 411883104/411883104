#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int c=100010;
int arr[c];
int main()
{
	int n,q,k;
	cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	while(q--)
	{
		scanf("%d",&k);
		int l=0,r=n-1;
		while(r>l)
		{
			int mid=l+r>>1;
			if(arr[mid]>=k)
				r=mid;
			else
				l=mid+1;
		}
		if(arr[l]!=k)
			cout<<"-1"<<' '<<"-1"<<endl;
		else
		{
			cout<<l<<' ';
			int l=0,r=n-1;
			while(r>l)
			{
				int mid=r+l+1>>1;
				if(arr[mid]<=k)
					l=mid;
				else
					r=mid-1;
			}
			cout<<l<<endl;
		}
	}
	return 0;
} 
