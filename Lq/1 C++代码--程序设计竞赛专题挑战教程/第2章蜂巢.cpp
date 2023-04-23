//蜂巢 2022年第十三届省赛Java大学A组、研究生组，Python大学B组、C组
//https://www.dotcpp.com/oj/problem2685.html
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll xdir[] = {-2,-1,1,2, 1,-1};  //横向
ll ydir[] = { 0, 1,1,0,-1,-1};  //纵向
void walk(ll d, ll q, ll &x, ll &y){
    x += xdir[d] * q;
    y += ydir[d] * q;   //引用传参，返回坐标值(x,y)
}
int main(){
    ll d1,p1,q1,d2,p2,q2;
    cin>>d1>>p1>>q1>>d2>>p2>>q2;
    ll x1 = 0, y1 = 0;           //计算起点坐标(x1, y1)
    walk(d1,p1,x1,y1);           //先走第1个方向
    walk((d1 + 2) % 6, q1,x1,y1); //再走第2个方向
    ll x2 = 0, y2 = 0;           //计算终点坐标(x2, y2)
    walk(d2,p2,x2,y2);
    walk((d2 + 2) % 6, q2,x2,y2);
    ll dx = abs(x1 - x2), dy = abs(y1 - y2);
    if (dx >= dy) cout << (dx+dy)/2;     //先横走，再斜着走
    else          cout << dy;            //一直斜着走就行了
}
