//˳���ȡ��Ҫ����߽� 
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#include<climits> 
//using namespace std;
//const int c=510;
//int arr[c][c];
//int maxx[c][c];
//int main()
//{
//	int n;
//	cin>>n;
//	//Ҫ�Ƚ��߽�ֵ��Ϊ��С 
//	for(int i=0;i<=n+1;i++)
//	{
//		for(int j=0;j<=n+1;j++)
//		{
//			arr[i][j]=INT_MIN;
//			maxx[i][j]=INT_MIN;
//		}
//	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=i;j++)
//		{
//			cin>>arr[i][j]; 
//		}
//	}
//	maxx[1][1]=arr[1][1];//����ʼֵ���ڵ�һ���� 
//	for(int i=2;i<=n;i++)//ע��i��2��ʼ 
//	{
//		for(int j=1;j<=i;j++)
//		{
//			//���ֵ�����Ϸ������Ϸ����ֵ��� 
//			maxx[i][j]=max(maxx[i-1][j],maxx[i-1][j-1])+arr[i][j];
//		}
//	}
//	int res=-1e9;
//	for(int i=1;i<=n;i++)
//	{
//		//������ݴ�������һ���У������һ�л�� 
//		res=max(res,maxx[n][i]);
//	}
//	cout<<res<<endl;
//	return 0; 
//} 


//�����ȡ�����ô���߽� 
#include<iostream>
#include<algorithm>
#include<cstring>
#include<climits> 
using namespace std;
const int c=510;
int arr[c][c];
int maxx[c][c];
int main()
{
	int n;
	cin>>n;
//	//Ҫ�Ƚ��߽�ֵ��Ϊ��С 
//	for(int i=0;i<=n+1;i++)
//	{
//		for(int j=0;j<=n+1;j++)
//		{
//			arr[i][j]=INT_MIN;
//			maxx[i][j]=INT_MIN;
//		}
//	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			cin>>arr[i][j]; 
		}
	}
//	maxx[1][1]=arr[1][1];//����ʼֵ���ڵ�һ���� 
	for(int i=n;i>0;i--)//ע��i��2��ʼ 
	{
		for(int j=1;j<=i;j++)
		{
			//���ֵ�����Ϸ������Ϸ����ֵ��� 
			maxx[i][j]=max(maxx[i+1][j],maxx[i+1][j+1])+arr[i][j];
		}
	}
//	int res=-1e9;
//	for(int i=1;i<=n;i++)
//	{
//		//������ݴ�������һ���У������һ�л�� 
//		res=max(res,maxx[n][i]);
//	}
//	cout<<res<<endl;
	cout<<maxx[1][1]<<endl;
	return 0; 
} 
