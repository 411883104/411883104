//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//vector<int>v;
//int main()
//{
//	int n;
//	scanf("%d",&n);
//	vector<int>::iterator it;
//	for(int i=0;i<n;i++)
//	{
//		int x;
//		scanf("%d",&x);
//		if(count(v.begin(),v.end(),x))
//			v.erase(find(v.begin(),v.end(),x));
//		else
//			v.push_back(x);
//	}
//	printf("%d\n",v.size());
//	return 0;
//}

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
map<int,int>m;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		m[x]++;
	}
	int ans=0;
	for(auto it:m)
	{
		if(it.second%2==1)
			ans++;
	}
	printf("%d",ans);
	return 0;
}
