//平面切分 2020年第十一届省赛  https://www.lanqiao.cn/problems/503/learning/

#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
double A[N], B[N];
int main(){
	int n;	cin>>n;
	pair<double, double> p;
	set<pair<double, double>> s;  //利用set自动去重功能筛选掉重边
	for(int i = 0; i < n; i++){
		cin >> p.first >> p.second ;
		s.insert(p);
	}
	int i = 0;  //将去重后的直线数据放回A,B数组
	set<pair<double, double> >::iterator it = s.begin();
	while(it != s.end()){
		A[i] = it -> first;
		B[i] = it -> second;
		it++, i++;
	}
	long long ans = 2;  //初始情况当只有一条直线时，有两个平面
	for(int i = 1; i < s.size(); i++){    //从下标1开始，也就是第二条直线
		set<pair< double,  double> > pos;  //记录第i条直线与先前的交点
		for(int j = 0; j <= i-1; j++){
			double a1 = A[i], b1 = B[i];
			double a2 = A[j], b2 = B[j];
			if(a1 == a2) continue;    //平行线无交点，跳出
			p.first = (b2-b1)/(a1-a2);  //交点的x坐标
			p.second = a1*(b2-b1)/(a1-a2) + b1; //交点的y坐标
			pos.insert(p);
		}
		ans += pos.size() + 1;  //与先前直线的交点数+1
	}
	printf("%d\n", ans);
	return 0;
}
