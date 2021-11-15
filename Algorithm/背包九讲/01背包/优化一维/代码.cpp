#include<iostream>
#include<algorithm>
using namespace std;
const int c=1005;
int bag[c];//一维表示 
int main()
{
	int num,cap;//num为物品数量，cap为背包的体积 。 
	cin>>num>>cap;
	//数组从一开始遍历。 
	for(int i=1;i<=num;i++)
	{
		int vol,val;//vol和val分别为第i件物品的体积和价值。 
		cin>>vol>>val;//也可以用数组表示物品的体积和价值。
//		for(int j=cap;j>=0;j--) //枚举必须从cap开始。 
//		{
//			//bag[i]表示总体积是i时最大价值是多少。 
//			if(j>=vol)
//			{
//				//状态转移方程： 
//				bag[j]=max(bag[j],bag[j-vol]+val);
//			}
//		}
		for(int j=cap;j>=vol;j--) //枚举必须从cap开始。 
		{
			//bag[i]表示总体积是i时最大价值是多少。 
			//状态转移方程： 
			bag[j]=max(bag[j],bag[j-vol]+val);
		}
	}
	cout<<bag[cap]<<endl;//输出最大值。 
	return 0; 
}
