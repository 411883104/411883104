#include<iostream>
using namespace std;
int main()
{
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		int x;
		cin>>x;
		if(x==2)
			cout<<2<<endl;
		else
			if(x%2==0)
				cout<<0<<endl;
			else
				cout<<1<<endl;
	}
	return 0;
 } 
