#include<iostream>
#include<algorithm> 
#include<climits>
using namespace std;
const int c=10005;
int arr[c];
int main()
{
	int l,m;
	cin>>l>>m;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		fill(arr+x,arr+y+1,1);
	}
	int k=count(arr,arr+10005,1);
	cout<<l-k+1<<endl;
	return 0;
}
