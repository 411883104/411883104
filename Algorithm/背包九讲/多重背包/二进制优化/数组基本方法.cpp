#include<iostream>
#include<algorithm>
using namespace std;
const int c=20050;
int bag[c];//一维表示
int vol[c],val[c];//vol和val分别为第i件物品的体积和价值，sum表示该物品有多少件。 
int main()
{
	int num,cap,cnt=0;//num为物品数量，cap为背包的体积，cnt记录将物品分开的组数。 
	cin>>num>>cap;
	int vo,va,sum;//vo为物品体积，va为物品价值，sum为物品数量。 
	//将物品分开 
	for(int i=1;i<=num;i++)
	{
		cin>>vo>>va>>sum;
		//记录分开后的体积和价值。 
		for(int j=1;j<=sum;j*=2)
		{
			vol[++cnt]=j*vo;
			val[cnt]=j*va;
			sum-=j;
		}
		if(sum>0)
		{
			vol[++cnt]=sum*vo;
			val[cnt]=sum*va; 
		}
	}
	//转化为01背包问题 
	for(int i=1;i<=cnt;i++)
	{
		for(int j=cap;j>=vol[i];j--)
		{
			bag[j]=max(bag[j],bag[j-vol[i]]+val[i]);
		}
	}
	cout<<bag[cap]<<endl;//输出最大值。 
	return 0; 
}
