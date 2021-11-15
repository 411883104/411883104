#include<iostream>
#include<algorithm> 
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	for(int i=1;i<=3;i++)
	{
		if((a*b*i)%2==1)
		{
			cout<<"Yes"<<endl;
			return 0; 
		}
	}
	cout<<"No"<<endl;
	return 0;
}
