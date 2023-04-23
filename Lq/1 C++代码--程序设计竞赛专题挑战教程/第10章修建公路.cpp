//修建公路1  https://www.lanqiao.cn/problems/1124/learning/

#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N=100005;
typedef long long ll;
const ll INF=0x3f3f3f3f3f3f;
bool vis[N];     // =ture: 表示点i已经在MST中
ll dis[N];
typedef pair<int,int> pii;
vector<pii> e[N];
priority_queue<pair<int,int>,vector<pii>,greater<pii> > q;  //优先队列
void prim(int s){
	memset(dis,INF,sizeof(dis));
	q.push({0,s});   //从s点开始处理队列
	dis[s]=0;
	ll ans=0;
	while(!q.empty())	{
		int u=q.top().second;   //pop出距集合最近的点u
		q.pop();
		if(vis[u]) continue;    //丢弃已经在MST中的点，有判圈的作用
		vis[u]=1;
		ans+=dis[u];
		for(int i=0;i<e[u].size();i++){ //检查点u的所有邻居
			pii v=e[u][i];          //一个邻居
			if(!vis[v.second])
				if(v.first<dis[v.second]){
					dis[v.second]=v.first;
					q.push(pii(dis[v.second],v.second));//扩展新的邻居，放进优先队列
				}
		}
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			cout<<"-1"<<endl;
			return ;
		}
	cout<<ans<<endl;
}
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
        int u,v,w;	scanf("%d%d%d",&u,&v,&w);
		e[u].push_back({w,v});  //双向边
		e[v].push_back({w,u});
	}
	prim(1);
	return 0;
}
