//正则问题 2017年第八届省赛C/C++A组
//https://www.lanqiao.cn/problems/106/learning

#include<bits/stdc++.h>
using namespace std;
string s;
int pos = 0;       //当前的位置
int dfs(){
	int tmp = 0, ans = 0;
	int len = s.size();
	while(pos < len){
		if     (s[pos] == '('){ pos++; tmp += dfs();} //左括号，继续递归。相当于进栈
		else if(s[pos] == ')'){	pos++; break;}        //右括号，递归返回。相等于出栈
		else if(s[pos] == '|'){	pos++; ans = max(ans, tmp);tmp = 0;}  //检查或
        else if(s[pos] == 'x'){ pos++; tmp++;}       //检查X，并统计X的个数
	}
	ans = max(ans, tmp);
	return ans;
}
int main(){
	cin >> s;
	cout << dfs();
	return 0;
}
