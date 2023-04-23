//跳蚱蜢  https://www.lanqiao.cn/problems/642/learning/

#include<bits/stdc++.h>
using namespace std;
struct node{
	node(){}
	node(string ss, int tt){s = ss, t = tt;}
	string s;
	int t;
};
int cnt = 0; //统计计算了多少次
map<string, bool> mp;
queue<node> q;
void solve(){
	while(!q.empty()){
		node now = q.front();
		q.pop();
		string s = now.s;
		int step = now.t;
		if(s == "087654321"){        //到目标了
			cout << step << endl;    //输出跳跃步数
			cout << cnt << endl;     //计算了 1451452 次
			break;
		}
		int i;
		for(i = 0 ; i < 10 ; i++)    //找到盘子的位置
			if(s[i] == '0')
                break;
		for(int j = i - 2 ; j <= i + 2 ; j++){  //4种跳法
			int k = (j + 9) % 9;
			if(k == i)	continue;               //这是当前状态，不用检查
			string news = s;
			char tmp = news[i];
            news[i] = news[k];
            news[k] = tmp;  //跳到一种情况
            cnt ++;
			if(!mp[news]){         //判重：这个情况没有出现过
				mp[news] = true;
				q.push(node(news, step + 1));
			}
		}
	}
}
int main(){
	string s = "012345678";
	q.push(node(s, 0));
	mp[s] = true;
	solve();
	return 0;
}
