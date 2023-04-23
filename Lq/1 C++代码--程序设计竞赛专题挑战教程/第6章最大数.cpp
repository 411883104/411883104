//最大数  https://www.lanqiao.cn/problems/826/learning/
#include<bits/stdc++.h>
using namespace std;
const int N = 200001;
const int INF = 0X7FFFFFFF;
int ls(int p){ return p<<1;  }     //左儿子，编号是 p*2
int rs(int p){ return p<<1|1;}     //右儿子，编号是 p*2+1
int tree[N<<2];                    //4倍空间
void push_up(int p){                            //从下往上传递区间值
    //tree[p] = tree[ls(p)] + tree[rs(p)];      //区间和
    tree[p] = max(tree[ls(p)], tree[rs(p)]);    //区间最大值
}
void build(int p,int pl,int pr){      //结点编号p指向区间[pl, pr]
    if(pl==pr){                       //到达最底层的叶子，存叶子的值
        tree[p] = -INF;
        return;
    }
    int mid = (pl+pr) >> 1;                //分治：折半
    build(ls(p),pl,mid);                   //递归左儿子
    build(rs(p),mid+1,pr);                 //递归右儿子
    push_up(p);                            //从下往上传递区间值
}
void update(int p,int pl,int pr,int L,int R,int d){ //区间修改,更新[L, R]内最大值
    if(L<=pl && pr<=R){            //完全覆盖，直接返回这个结点，它的子树不用再深入了
        tree[p] = d;
        return;
    }
    int mid=(pl+pr)>>1;
    if(L<=mid) update(ls(p),pl,mid,L,R,d);    //递归左子树
    if(R>mid)  update(rs(p),mid+1,pr,L,R,d);  //递归右子树
    push_up(p);                               //更新
    return;
}
int query(int p,int pl,int pr,int L,int R){ //在查询区间[L, R]的最大值
    int res = -INF;
    if (L<=pl && pr<=R)    return tree[p];   //完全覆盖
    int mid=(pl+pr)>>1;
    if (L<=mid) res = max(res, query(ls(p),pl,mid,L,R));    //L与左子结点有重叠
    if (R>mid)  res = max(res, query(rs(p),mid+1,pr,L,R));  //R与右子结点有重叠
    return res;
}
int main (){
    int t=0,cnt=0,m,D;
    scanf ("%d%d",&m,&D);
    build(1,1,N);          //不用build()，这样写也行：update(1,1,N,1,N,-INF);
    for (int b=1;b<=m;++b){
        char c[2];  int x;   scanf ("%s %d",c,&x);
        if (c[0]=='A'){
            cnt++;
            update(1,1,N,cnt,cnt,(x+t)%D);

        }
        else {
            t = query(1,1,N,cnt-x+1,cnt);
            printf ("%d\n",t);
        }
    }
    return 0;
}
