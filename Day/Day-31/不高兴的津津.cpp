#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int arr[8];
	for(int i=1;i<=7;i++)
	{
		int x,y;
		cin>>x>>y;
		arr[i]=x+y;
	}
	int index=0,maxx=0;
	for(int i=1;i<=7;i++)
	{
		if(arr[i]>maxx)
		{
			maxx=arr[i];
			index=i;
		}
	}
	if(maxx<=8)
		cout<<0<<endl;
	else
		cout<<index<<endl;
	return 0;
 } 
