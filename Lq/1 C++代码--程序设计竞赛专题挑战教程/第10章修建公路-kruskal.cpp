//修建公路1  https://www.lanqiao.cn/problems/1124/learning/

#include<bits/stdc++.h>
using namespace std;
const int N = 100005,M = 300006;
int n,m;
int s[N];//并查集
struct Edge{ int from,to,dis;}e[M];     //用最简单且最省空间的结构体数组存边
bool cmp(Edge a,Edge b){  //从小到大排序
	return (a.dis<b.dis);
}
int find(int x)  { //查询并查集，返回x的根
	if(x!=s[x]) s[x]=find(s[x]);//路径压缩
	return s[x];
}
void union_set(int x,int y)   {   //合并
	s[find(y)]=find(x);
}
void kruskal(){
    long long ans=0;
    int cnt=0;
	sort(e+1,e+m+1,cmp);                //对边做排序
	for(int i=1;i<=n;++i)  s[i]=i;    //并查集初始化
	for(int i=1;i<=m;++i){            //贪心：逐一加入每个边
		if(find(e[i].from)!=find(e[i].to)){ //边的端点属于同一个集吗
			ans+=e[i].dis; //计算MST
			union_set(e[i].from,e[i].to);//合并
			++cnt;                 //统计MST中的点数
		}
		if(cnt==n-1) break;
	}
	if(cnt!=n-1)     cout<<"-1";
	else             cout<<ans;
	return;

}

int main(){
	cin>>n>>m;
	for(int i=1;i<=m;++i)  cin>>e[i].from>>e[i].to>>e[i].dis;
    kruskal();
	return 0;
}
