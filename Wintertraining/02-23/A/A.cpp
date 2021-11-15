#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
int main()
{
	int n;
	while(cin>>n&&n!=0)
	{
		if(n<=4)
			cout<<n<<endl;
		else
		{
			ll ans=4;
			ll arr[3]={2,3,4};
			ll vis=0;
			for(ll i=2;i<n-2;i++)
			{
				ans+=arr[vis];
				arr[vis]=ans;
				vis=(vis+1)%3;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
 } 
