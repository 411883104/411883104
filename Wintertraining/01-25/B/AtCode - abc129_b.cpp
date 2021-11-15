#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int c=110;
int arr[c];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int minn=200;
	for(int i=0;i<n;i++)
	{
		int s1=0,s2=0;
		for(int j=0;j<n;j++)
		{
			if(j<i)
			{
				s1+=arr[j];
			}
			else
			{
				s2+=arr[j];
			}
		}
		minn=min(minn,abs(s2-s1));
	}
	cout<<minn<<endl;
	return 0;
}
