#include<iostream>
#include<algorithm>
using namespace std;
const int c=1005;
int bag[c][c];//二维表示 
int main()
{
	int num,cap;//num为物品数量，cap为背包的体积 。 
	cin>>num>>cap;
	//数组从一开始遍历。 
	for(int i=1;i<=num;i++)
	{
		int vol,val;//vol和val分别为第i件物品的体积和价值。 
		cin>>vol>>val;//也可以用数组表示物品的体积和价值。 
		for(int j=1;j<=cap;j++)
		{
			//bag[i][j]表示只看前i个物品，总体积是j的情况下总价值最大是多少。
			if(j>=vol)
			{
				bag[i][j]=max(bag[i-1][j],bag[i-1][j-vol]+val);//能装下该物品。
			}
			else
				bag[i][j]=bag[i-1][j];//不能装下该物品。 
		}
	}
	cout<<bag[num][cap]<<endl;//输出最大值。 
	return 0; 
}
