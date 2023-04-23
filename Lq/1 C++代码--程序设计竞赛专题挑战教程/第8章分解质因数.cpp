//分解质因数  https://www.lanqiao.cn/problems/1559/learning/


#include<bits/stdc++.h>
using namespace std;
int p[20];  //p[]记录因子，p[1]是最小因子。一个int数的质因子最多有10几个
int c[40];  //c[i]记录第i个因子的个数。一个因子的个数最多有30几个
int factor(int n){
    int m = 0;
    for(int i = 2; i <= sqrt(n); i++)
        if(n%i == 0){
           p[++m] = i, c[m] = 0;
           while(n%i == 0)            //把n中重复的因子去掉
              n/=i, c[m]++;
        }
    if(n>1)                           //没有被除尽，是素数
       p[++m] = n, c[m] = 1;
    return m;                         //共m个因子
}
int main(){
    int a,b;   cin>>a>>b;
    for(int i=a;i<=b;i++){
        int m = factor(i);
        cout<<i<<"=";
        for(int j=1;j<=m;j++){ //第j个因子
            for(int k=1;k<=c[j];k++){    //第j个因子的个数
                cout <<p[j];
                if(k<c[j]) cout <<"*";
            }
            if(j<m) cout <<"*";
        }
        cout<<endl;
    }
    return 0;
}
