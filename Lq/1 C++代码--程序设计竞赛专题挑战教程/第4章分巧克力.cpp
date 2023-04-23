//分巧克力 2017年第八届蓝桥杯省赛C/C++大学A组     https://www.lanqiao.cn/problems/99/learning


#include<bits/stdc++.h>
using namespace std;
int n,k;
const int N=100010;
int h[N],w[N];
bool check(int d){
    int num=0;
    for(int i=0;i<n;i++)  num += (h[i]/d)*(w[i]/d);
    if(num>=k) return true;      //够分
    else       return false;     //不够分
}
int main(){
    cin >> n >> k;
    for(int i=0;i<n;i++)   cin>>h[i]>>w[i];
    int L=1, R=N;                //D的初值是R=100010
//第一种写法：
    while(L<R) {
        int mid=(L+R+1)>>1;      //除2，向右取整
        if(check(mid))  L=mid;   //新的搜索区间是右半部分，R不变，调整L=mid
        else            R=mid-1; //新的搜索区间是左半部分，L不变，调整R=mid–1
    }
    cout << L;
//第二种写法：
/*  while(L<R) {
        int mid=(L+R)>>1;        //除2，向左取整
        if(check(mid)) L=mid+1;  //新的搜索区间是右半部分，R不变，更新L=mid+1
        else           R=mid;    //新的搜索区间是左半部分，L不变，更新R=mid
    }
    cout << L-1;    */
    return 0;
}
