//д��1�� 
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
		res+=abs(arr[i]-arr[n/2]);//��λ����������ѡַ 
	}
	cout<<res<<endl;
	return 0;
}

//д��2 
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
//		res+=arr[i]-arr[i/2];//�����i/2��n/2������Ľ��һ�� 
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
//	//һһö�� 
//	for(int i=0;i<=40000;i++)
//	{
//		int res=0;
//		for(int j=0;j<n;j++)
//		{
//			res+=abs(arr[j]-i);//������� 
//		}
//		minn=min(res,minn);//ÿһ�ζ�ȡ��Сֵ 
//	}
//	printf("%d",minn);
//	return 0;
//} 
