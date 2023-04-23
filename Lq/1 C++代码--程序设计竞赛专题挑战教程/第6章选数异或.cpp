//选数异或  2022年第十三届蓝桥杯省赛 C/C++大学A组、C组、研究生组，Java大学C组
//http://oj.ecustacm.cn/problem.php?id=2024
#include<bits/stdc++.h>
using namespace std;
const int N = 100010 ;
int Left[N], pos[(1 << 20) + 10];
int a[N] ;
int tree[4*N];
int ls(int p){ return p<<1;  }     //左儿子
int rs(int p){ return p<<1|1;}     //右儿子
void push_up(int p){               //从下往上传递区间值
    tree[p] = max(tree[ls(p)], tree[rs(p)]);    //区间最大值
}
void build(int p, int pl, int pr) {
    if(pl == pr){
        tree[p] = Left[pl];
        return;
    }
    int mid = (pl + pr) >> 1;
    build(ls(p), pl, mid);
    build(rs(p), mid + 1, pr);
    push_up(p);
}
int query(int p, int pl, int pr, int L, int R){
    if(L <= pl && pr <= R)return tree[p];
    int mid = (pl + pr) >> 1;
    int res = 0;
    if(L <= mid) res = max(res, query(ls(p), pl, mid, L, R));
    if(R > mid)  res = max(res, query(rs(p), mid + 1, pr, L, R));
    return res;
}
int main(){
    int n, m, x;  cin >> n >> m >> x;
    for(int i = 1; i <= n; i++) {      //预处理Left数组
        scanf("%d",a+i);
        Left[i] = pos[a[i] ^ x];
        pos[a[i]] = i;
    }
    build(1, 1, n);
    while(m--){
        int L,R; scanf("%d%d",&L,&R);
        if(query(1, 1, n, L, R) >= L)  printf("yes\n");
        else                              printf("no\n");
    }
    return 0;
}
