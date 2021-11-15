#include<iostream>
#include<algorithm>
using namespace std;
const int c=10005;
int arr[c];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(int i=0;i<m;i++)
	{
		//next_permutation算法获取下一个排列 
		next_permutation(arr,arr+n);//使用algorithm中的算法进行排序 
	}
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}
