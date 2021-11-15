//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//typedef long long ll;
//const int c=200005;
//ll s1[c];
//ll s2[c];
//int main()
//{
//	int n;
//	scanf("%d",&n);
//	for(int i=1;i<=n;i++)
//		scanf("%d",&s1[i]);
//	for(int i=1;i<=n;i++)
//		scanf("%d",&s2[i]);
//	int sum=0;
//	for(int i=1;i<n;i++)
//	{
//		for(int j=i+1;j<=n;j++)
//		{
//			if(s1[i]+s1[j]>s2[i]+s2[j])
//				sum++;
//		}
//	}
//	printf("%d\n",sum);
//	return 0;
//}


#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int c=200010;
ll arr[c];
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",&arr[i]);
	for(int i=1; i<=n; i++) {
		int x;
		scanf("%d",&x);
		arr[i]-=x;
	}
	sort(arr,arr+n);
	ll sum=0;
	for(int i=1; i<n; i++) {
		int cnt=upper_bound(arr+1,arr+n+1,-arr[i])-arr;
		sum+=(n-cnt+1);
		if(arr[i]>0)
			sum--;
	}
	printf("%lld\n",sum/2);
	return 0;
}
