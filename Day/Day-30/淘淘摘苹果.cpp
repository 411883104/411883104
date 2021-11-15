#include<iostream>
using namespace std;
int main()
{
	int arr[11];
	int hight;
	for(int i=0;i<10;i++)
	{
		cin>>arr[i];
		arr[i]-=30;
	}
	cin>>hight;
	int sum=0;
	for(int i=0;i<10;i++)
	{
		if(arr[i]<=hight)
		sum++;
	}
	cout<<sum<<endl;
	return 0;
 } 
