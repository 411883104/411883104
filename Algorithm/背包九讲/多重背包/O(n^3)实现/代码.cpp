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
		int vol,val,sum;//vol和val分别为第i件物品的体积和价值，sum表示该物品有多少件。 
		cin>>vol>>val>>sum;//也可以用数组表示物品的体积、价值和数量。
		for(int j=cap;j>=0;j--) 
		{
			for(int k=1;k<=sum;k++)//逐件物品增加。 
			{
				if(j>=k*vol)
				{
					//状态转移方程： 
					bag[j]=max(bag[j],bag[j-k*vol]+k*val);
				}
			}
		}
	}
	cout<<bag[cap]<<endl;//输出最大值。 
	return 0; 
}
