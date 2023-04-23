//最长不下降子序列   2022年第十三届蓝桥杯省赛 C/C++大学A组，Java大学C组，Python大学A组、B组

//http://oj.ecustacm.cn/problem.php?id=2027


#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N], b[N], n, k, tree[4*N], dp[N];
int ls(int p){ return p<<1;  }     //左儿子
int rs(int p){ return p<<1|1;}     //右儿子
void push_up(int p){ tree[p] = max(tree[ls(p)], tree[rs(p)]);}
void build(int p, int pl, int pr){
    tree[p]=0;
    if (pl==pr)   return;
    int mid=(pl+pr)/2;
    build(ls(p), pl, mid);
    build(rs(p), mid+1, pr);
}
void update(int p, int pl, int pr, int x, int v){   //把第x个叶子结点的值更新为v
    if (pl==pr){
        tree[p]=max(tree[p], v);        //如果v更大，更新为v
        return;
    }
    int mid=(pl+pr)/2;
    if (x<=mid)  update(ls(p), pl,    mid, x, v);
    else         update(rs(p), mid+1, pr,  x, v);
    push_up(p);
}
int query(int p, int pl, int pr, int L, int R){
    if (L<=pl && pr<=R)     return tree[p];
    int res=0;
    int mid=(pl+pr)/2;
    if (L<=mid)   res=max(res, query(ls(p), pl, mid, L, R));
    if (R > mid)  res=max(res, query(rs(p), mid+1, pr, L, R));
    return res;
}
int main(){
    cin >> n >> k;
    if (n==k){cout << n; return 0;}    //一个特判
    for (int i=1 ; i<=n ; i++){ cin >> a[i];  b[i]=a[i];}
    sort(b+1, b+1+n);                  //离散化。不过本题的a[i]小于10^6，不离散化也行
    for (int i=1 ; i<=n ; i++)         //查找相等的元素的位置，这个位置就是离散化后的新值
       a[i]=(lower_bound(b+1, b+1+n, a[i])-b);
   build(1, 1, N);                   //离散化之后，把N从1e6改为1e5
    for (int i=1 ; i<=n ; i++){        //计算dp[i]:以a[i]为结尾的最长不下降子序列长度
        dp[i] = query(1, 1, N, 1, a[i])+1;    //注意此处是N，不是n
        update(1, 1, N, a[i], dp[i]);
    }   //以上计算出了dp[]
    int ans=0;
    build(1, 1, N);                   //重建线段树
    for (int i=n; i>k; i--){           //从后往前，每次暴力修改k个
        ans = max(ans, dp[i-k]+k-1+query(1, 1, N, a[i-k], N)+1);
        int tmp = query(1, 1, N, a[i], N)+1;
        ans = max(ans, tmp + k);
        update(1, 1, N, a[i], tmp);
    }
    cout << ans;
    return 0;
}
