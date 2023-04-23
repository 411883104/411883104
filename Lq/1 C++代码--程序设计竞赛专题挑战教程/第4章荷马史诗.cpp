//荷马史诗 https://www.lanqiao.cn/problems/1167/learning/

#include<bits/stdc++.h>
using namespace std;
#define int long long
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
int w[100005];
signed main(){
	int n,k; cin >> n >> k;                   //读n个单词，用k进制构造哈夫曼树
	for(int i = 1; i <= n; i++)	cin >> w[i];  //读每个单词的出现频次
	while((n - 1) % (k - 1) != 0) n++;        //补齐虚拟结点
	for(int i = 1; i <= n; i++)
        pq.push(make_pair(w[i], 0));          //队首是最小值
	int ans = 0,x=0;
	while(pq.size() != 1){                    //模拟构造k叉树。pq=1，表示队列中只剩下根结点
		int s = 0 ;
		for(int i = 1; i <= k; i++){          //k叉树，取出队列的k个最小数
			s += pq.top().first;              //对这棵子树的频次求和
			x = max(x, pq.top().second);      //x是树的最大深度，也是最长的那个单词的编码长度
			pq.pop();
		}
		ans += s;                             //累加这一层的总频次
		pq.push(make_pair(s, x + 1));
	}
	cout << ans << '\n' << x + 1;             //x+1是从根到最深结点的深度，也是最长编码长度
}
