//写法1： 
#include<iostream>
#include<algorithm>
#include<cmath> 
using namespace std;
typedef long long ll; 
const int c=100010;
int arr[c];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	ll res=0;
	for(int i=0;i<n;i++)
	{
		res+=abs(arr[i]-arr[n/2]);//中位数就是最优选址 
	}
	cout<<res<<endl;
	return 0;
}

//写法2 
//#include<iostream>
//#include<algorithm>
//#include<cmath> 
//using namespace std;
//const int c=10005;
//int arr[c];
//int main()
//{
//	int n;
//	cin>>n;
//	for(int i=0;i<n;i++)
//	{
//		cin>>arr[i];
//	}
//	sort(arr,arr+n);
//	int res=0;
//	for(int i=0;i<n;i++)
//	{
//		res+=arr[i]-arr[i/2];//这里的i/2与n/2算出来的结果一样 
//	}
//	cout<<res<<endl;
//	return 0;
//}

//Time Limit Exceeded
//#include<iostream>
//#include<algorithm>
//#include<cmath>
//using namespace std;
//const int c=100005;
//int arr[c];
//int main()
//{
//	int n;
//	scanf("%d",&n);
//	for(int i=0;i<n;i++)
//	{
//		scanf("%d",&arr[i]); 
//	}
//	int minn=1e9;
//	//一一枚举 
//	for(int i=0;i<=40000;i++)
//	{
//		int res=0;
//		for(int j=0;j<n;j++)
//		{
//			res+=abs(arr[j]-i);//计算距离 
//		}
//		minn=min(res,minn);//每一次都取最小值 
//	}
//	printf("%d",minn);
//	return 0;
//} 
