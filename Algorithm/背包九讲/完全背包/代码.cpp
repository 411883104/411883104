#include<iostream>
#include<algorithm>
using namespace std;
const int c=1005;
int bag[c];//一维表示 
int main()
{
	int num,cap;//num为物品数量，cap为背包的体积 。 
	cin>>num>>cap;
	//数组从一开始遍历 ，行列为零时值为零。 
	for(int i=1;i<=num;i++)
	{
		int vol,val;//vol和val分别为第i件物品的体积和价值。 
		cin>>vol>>val;//也可以用数组表示物品的体积和价值。
		for(int j=vol;j<=cap;j++)//从vol开始到cap包含了多个vol的情况。 
		{
			//bag[i]表示总体积是i时最大价值是多少。 
			bag[j]=max(bag[j],bag[j-vol]+val);
		}
	}
	cout<<bag[cap]<<endl;//输出最大值。 
	return 0; 
}
