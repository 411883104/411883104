// 双向排序 2021年第十二届省赛C/C++大学B组、研究生组，Java大学A组、B组、C组、研究生组
// https://www.lanqiao.cn/problems/1458/learning/

#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
const int N = 100010;
int ans[N];
pair<int, int> stk[N];
int main() {
    int n, m;  cin>>n>>m;
    int top = 0;    // 栈顶
    while (m--){    //读操作，并且合并
        int p,q; scanf("%d%d", &p, &q);        //这里不用cin，慢
        if (p==0)  {                           //操作0：降序
            while(top && stk[top].x == 0)      //合并连续的0操作，取最大
                q = max(q, stk[top--].y);
            while(top >= 2 && stk[top-1].y <= q) //0、1交替
            //如果当前的操作0比上一次的操作0范围大，将上一次操作0和操作1删除
                top -= 2;
            stk[++top] = {0, q};   //存本次最佳操作
        }
        else if (top) {  //操作1 &&且操作0已经进行过（操作1第一个用没效果）
            while (top && stk[top].x == 1)
                q = min(q, stk[top--].y);
            while (top >= 2 && stk[top-1].y >= q)
                top -= 2;
            stk[++top] = {1, q};
        }
    }
    int k=n, L=1, R=n;        //用k处理固定的数字
    for (int i=1; i<=top; i++ ) {
        if (stk[i].x == 0)    //0降序操作，固定右边的数字
            while (R>stk[i].y && L<=R) ans[R--] = k--;
        else                  //1升序操作，固定左边的数字
            while (L<stk[i].y && L<=R) ans[L++] = k--;
        if (L>R) break;
    }
    if (top % 2)             //最后一次操作是0操作，补上中间的数字
        while(L<=R) ans[L++] = k--;
    else                     //最后一次操作是1操作
        while(L<=R) ans[R--] = k--;
    for (int i=1; i<=n; i++)  printf("%d ", ans[i]);
    return 0;
}
