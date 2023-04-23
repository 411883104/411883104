//https://www.lanqiao.cn/problems/1133/learning/
//区间修改、区间求和

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 10;
ll a[N];      //记录数列的元素，从a[1]开始
ll tree[N<<2];//tree[i]：第i个结点的值，表示一个线段区间的值，例如最值、区间和
ll tag[N<<2]; //tag[i]：第i个结点的lazy-tag，统一记录这个区间的修改
ll ls(ll x){ return x<<1;  }     //定位左儿子：x*2
ll rs(ll x){ return x<<1|1;}     //定位右儿子：x*2 + 1
void push_up(ll p){              //从下往上传递区间值
    tree[p] = tree[ls(p)] + tree[rs(p)];
     //本题是区间和。如果求最小值，改为：tree[p] = min(tree[ls(p)], tree[rs(p)]);
}
void build(ll p,ll pl,ll pr){    //建树。p是结点编号，它指向区间[pl, pr]
    tag[p] = 0;                  //lazy-tag标记
    if(pl==pr){tree[p]=a[pl]; return;}  //最底层的叶子，赋值
    ll mid = (pl+pr) >> 1;       //分治：折半
    build(ls(p),pl,mid);         //左儿子
    build(rs(p),mid+1,pr);       //右儿子
    push_up(p);                  //从下往上传递区间值
}
void addtag(ll p,ll pl,ll pr,ll d){   //给结点p打tag标记，并更新tree
    tag[p] += d;                   //打上tag标记
    tree[p] += d*(pr-pl+1);        //计算新的tree
}
void push_down(ll p,ll pl,ll pr){     //不能覆盖时，把tag传给子树
    if(tag[p]){                       //有tag标记，这是以前做区间修改时留下的
        ll mid = (pl+pr)>>1;
        addtag(ls(p),pl,mid,tag[p]);    //把tag标记传给左子树
        addtag(rs(p),mid+1,pr,tag[p]);  //把tag标记传给右子树
        tag[p]=0;                       //p自己的tag被传走了，归0
    }
}
void update(ll L,ll R,ll p,ll pl,ll pr,ll d){  //区间修改：把[L, R]内每个元素加上d
    if(L<=pl && pr<=R){     //完全覆盖，直接返回这个结点，它的子树不用再深入了
        addtag(p, pl, pr,d);   //给结点p打tag标记，下一次区间修改到p这个结点时会用到
        return;
    }
    push_down(p,pl,pr);               //如果不能覆盖，把tag传给子树
    ll mid=(pl+pr)>>1;
    if(L<=mid) update(L,R,ls(p),pl,mid,d);    //递归左子树
    if(R>mid)  update(L,R,rs(p),mid+1,pr,d);  //递归右子树
    push_up(p);                               //更新
}
ll query(ll L,ll R,ll p,ll pl,ll pr){
   //查询区间[L,R]；p是当前结点（线段）的编号，[pl,pr]是结点p表示的线段区间
    if(pl>=L && R >= pr) return tree[p];       //完全覆盖，直接返回
    push_down(p,pl,pr);                        //不能覆盖，递归子树
    ll res=0;
    ll mid = (pl+pr)>>1;
    if(L<=mid) res+=query(L,R,ls(p),pl,mid);   //左子结点有重叠
    if(R>mid)  res+=query(L,R,rs(p),mid+1,pr); //右子结点有重叠
    return res;
}
int main(){
    ll n, m; scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++)  scanf("%lld",&a[i]);
    build(1,1,n);                   //建树
    while(m--){
        ll q,L,R,d;
        scanf("%lld",&q);
        if (q==1){                   //区间修改：把[L,R]的每个元素加上d
           scanf("%lld%lld%lld",&L,&R,&d);
           update(L,R,1,1,n,d);
        }
        else {                        //区间询问：[L,R]的区间和
           scanf("%lld%lld",&L,&R);
           printf("%lld\n",query(L,R,1,1,n));
        }
    }
    return 0;
}
