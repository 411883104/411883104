#include<iostream>
#include<algorithm>
using namespace std;
const int c=1010;
int arr[c];

int main()
{
	int n;
	cin>>n;//����ɽ������ 
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];//����ɽ�ĸ߶� 
	}
	int maxx=1e8;
	for(int i=0;i+17<=100;i++)
	{
		int cast=0,l=i,r=i+17;
		for(int j=1;j<=n;j++)
		{
			if(arr[j]<l||arr[j]>r)
			{
				if(arr[j]>r)
				{
					cast+=(arr[j]-r)*(arr[j]-r);
				}
				if(arr[j]<l)
				{
					cast+=(l-arr[j])*(l-arr[j]);
				}
			}
		}
		maxx=min(cast,maxx);//ÿһ�ζ�ȡ��Сֵ 
	}
	cout<<maxx<<endl;
	return 0;
} 
