//自行车停放 https://www.lanqiao.cn/problems/1518/learning/

#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
struct node{                          //双向链表
    //int id;                         //结点编号，没用到
    int data;                         //数据
    int preid;                        //指向前一个结点
    int nextid;                       //指向后一个结点
}nodes[N];
int now;            //链表的当前结点
int locate[N];      //locate(x) = now; 值为x的结点位置在nodes[now]
void init() {       //初始化
    nodes[0].nextid = 1;
    nodes[1].preid  = 0;
    now = 2;
}
void insert(int k, int x) {  //插入一个nodes[now]，插到nodes[k]的右面
    nodes[now].data = x;
    locate[x] = now;         //记录值为x的结点的位置
    nodes[now].nextid = nodes[k].nextid;
    nodes[now].preid = k;
    nodes[nodes[k].nextid].preid = now;
    nodes[k].nextid = now;
    now++;
}
int main() {
    int n,a;  cin>>n>>a;//a是第一辆车编号
    init();
    insert(0, a);
    n--;
    while (n--) {
        int x,y,z; cin>>x>>y>>z;
        int temp = locate[y];
        if (z==0)    //把x插到y的左边
            insert(nodes[temp].preid, x); //用locate[]快速定位
        else           //把x插到y的右边
            insert(temp, x);
    }
    for (int i = nodes[0].nextid; i != 1; i = nodes[i].nextid)
        cout << nodes[i].data << " ";
    return 0;
}
