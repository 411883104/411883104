//点和线段关系  https://www.lanqiao.cn/problems/1242/learning/
#include<bits/stdc++.h>
using namespace std;
const double eps = 1e-8;        //偏差值
int sgn(double x){  //判断x是否等于0
    if(fabs(x) < eps)  return 0;
    else return x<0?-1:1;
}
struct Point{
    double x, y;
    void input(){ scanf("%lf%lf", &x, &y); }
    Point(){}
    Point(double x,double y):x(x),y(y){}
    Point operator + (Point B){return Point(x+B.x,y+B.y);}
    Point operator - (Point B){return Point(x-B.x,y-B.y);}
};
typedef Point Vector;                    //定义向量
double Cross(Point A,Point B){return A.x*B.y - A.y*B.x;} //叉积
double Dot(Vector A,Vector B){return A.x*B.x + A.y*B.y;} //点积
struct Line{
    Point p1,p2;       //线上的两个点
    Line(){}
    Line(Point p1,Point p2):p1(p1),p2(p2){}
};
bool Point_on_seg(Point p, Line v){ //点和线段：0 点不在线段v上；1 点在线段v上
    return sgn(Cross(p-v.p1, v.p2-v.p1)) == 0 && sgn(Dot(p - v.p1, p- v.p2)) <= 0;
}
int main(){
    int t;  cin >> t;
    while(t--){
        Point a, b, c;
        a.input(); b.input(); c.input();
        Line v;
        v=Line(a,b);
        int pos=Point_on_seg(c, v);
        if(pos==0) cout<<"No"<<endl;
        if(pos==1) cout<<"Yes"<<endl;
    }
    return 0;
}
