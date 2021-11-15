#include<iostream>
#include<algorithm> 
#include<vector>
using namespace std;
int main()
{
	vector<int>v;
	int x;
	while(cin>>x&&x!=0)
		v.push_back(x);
	int ans=0;
	int vis=1;
	if(v[0]==1)
		ans++;
	else
	{
		ans+=2;
		vis++;
	}	
	for(int i=1;i<v.size();i++)
	{
		if(v[i-1]==1)
		{
			if(v[i]==1)
			{
				ans++;
				vis=1;
			}
			else
			{
				ans+=2;
				vis++;
			}
		}
		else
		{
			if(v[i]==2)
			{
				ans=ans+vis*2;
				vis++;
			}
			if(v[i]==1)
			{
				ans++;
				vis=1;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
