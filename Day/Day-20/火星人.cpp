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
		//next_permutation�㷨��ȡ��һ������ 
		next_permutation(arr,arr+n);//ʹ��algorithm�е��㷨�������� 
	}
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}
