#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	string str;
	cin>>str;
	for(int i=0;i<n;i++)
	{
		if(i+1==k)
		{
			str[i]+=32;
		}
	}
	cout<<str<<endl;
	return 0;
 } 
