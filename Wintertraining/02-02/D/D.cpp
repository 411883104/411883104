#include<iostream>
#include<algorithm>
using namespace std;
const int c=1000005;
int arr[c];
int vis[c];
int main()
{
	int s;
	cin>>s;
	arr[1]=s;
	vis[s]=1;
	for(int i=2;i<c;i++)
	{
		if(arr[i-1]%2==0)
		{
			arr[i]=arr[i-1]/2;
			
		}
		else
		{
			arr[i]=3*arr[i-1]+1;				
		}
		if(vis[arr[i]]==1)
		{
			cout<<i<<endl;
			break;
		}
		else
		{
			vis[arr[i]]=1;
		}
	}
	return 0;
 } 
