#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int *arr=new int[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	sort(arr,arr+n);
	int m=unique(arr,arr+n)-arr;
	cout<<m<<endl;
	for(int i=0;i<m;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
} 
