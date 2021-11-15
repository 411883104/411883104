#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
int main()
{
	int n;
	cin>>n;
	char arr[]={'0'};
	map<string,int>m;
	bool vis=true;
	string str;
	cin>>str;
	m[str]++;
	arr[0]=str[str.size()-1];
	for(int i=1;i<n;i++)
	{
		cin>>str;
		m[str]++;
		if(arr[0]!=str[0])
			vis=false;
		arr[0]=str[str.size()-1];
		if(m[str]>1)
			vis=false;
	}
	if(vis)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0;
}
