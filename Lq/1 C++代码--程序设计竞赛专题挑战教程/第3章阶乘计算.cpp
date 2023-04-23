//阶乘计算  https://www.lanqiao.cn/problems/1515/learning/
#include <bits/stdc++.h>
using namespace std;
const int N = 10000;
int a[N] = {0};                    //存结果，注意大静态数组要定义在全局
int main(){
    int n;   cin >> n;
    a[0] = 1;
    for(int i=1;i<= n;i++){        //模拟计算n!
        int carry = 0;             //进位
        for(int j=0;j< N;j++){     //两个数相乘
            a[j] = a[j] * i + carry;
            carry = a[j] / 10;
            a[j] = a[j] % 10;
        }
    }
    int last;                      //找最高位，就是第一个不等于0的最高位
    for(int i=N-1;i>=0;i--){
        if (a[i] != 0){
            last = i;
            break;
        }
    }
    for(int i=last; i>=0;i--) cout << a[i];     //从最高位开始打印
    return 0;
}
