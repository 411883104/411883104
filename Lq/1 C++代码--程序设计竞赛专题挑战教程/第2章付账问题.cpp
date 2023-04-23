//付账问题 2018年第九届蓝桥杯C/C++大学A组，Java大学A组
//题目链接： https://www.lanqiao.cn/problems/174/learning

#include <bits/stdc++.h>
using namespace std;
const int M = 5e5;
long long a[M];
int main(){
    int n;  long long s;
    scanf("%d %ld",&n,&s);
    for(int i=1;i<=n;i++)  scanf("%ld",&a[i]);
    sort(a+1,a+n+1);       //排序，从小到大
    double avg = 1.0*s/n;  //平均值
    double sum = 0.0;
    for(int i=1;i<=n;i++){
        if(a[i]*(n+1-i) < s){
//需要把钱全拿出的人：（1）钱不够平均数的，（2）钱够平均数，但也不是很多的
            sum += (a[i]-avg)*(a[i]-avg);
            s -= a[i];            //更新剩余钱数
        }
        else{       //不用把钱全拿出的人：非常有钱，不管怎么平均都够
            double cur_avg = 1.0*s/(n+1-i);    //更新平均出钱数
            sum += (cur_avg-avg)*(cur_avg-avg)*(n+1-i);
            break;
        }
    }
    printf("%.4f",sqrt(sum/n));
    return 0;
}
