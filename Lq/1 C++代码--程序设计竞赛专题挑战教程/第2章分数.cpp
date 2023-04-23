//https://www.lanqiao.cn/problems/610/learning
//[分数 2018年第九届蓝桥杯C/C++大学A组，Java大学A组 ] 

#include<bits/stdc++.h>
using namespace std;
int main(){
	int a = (1 << 20) - 1; //分子
	int b = (1 << 19);     //分母
	int t = __gcd(a, b);   //除去公约数
	cout << a/t << "/" << b/t;
	return 0;
}