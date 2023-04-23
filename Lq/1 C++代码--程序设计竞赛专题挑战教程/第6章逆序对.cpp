//逆序对 https://www.lanqiao.cn/problems/1506/learning/

#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
int tree[N],Rank[N],n;         //注：rank是C++的保留字，这里用Rank
#define lowbit(x)  ((x) & - (x))
void update(int x, int d) {
    while(x <= N) {
        tree[x] += d;
        x += lowbit(x);
    }
}
int sum(int x) {
    int ans = 0;
    while(x > 0){
        ans += tree[x];
        x -= lowbit(x);
    }
    return ans;
}
struct point{ int num,val;} a[N];
bool cmp(point x,point y){
    if(x.val == y.val)   return x.num < y.num;
    return x.val < y.val;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
		scanf("%d",&a[i].val);
		a[i].num = i;         //记录顺序，用于离散化
	}
    sort(a+1,a+1+n,cmp);      //排序
    for(int i=1;i<=n;i++)     //离散化，得到新的数字序列rank[]
		Rank[a[i].num]=i;

	long long ans=0;
	for(int i=n;i>0;--i){     //倒序处理
        update(Rank[i],1);
        ans += sum(Rank[i]-1);
    }
    printf("%lld",ans);
    return 0;
}
