//带分数 https://www.lanqiao.cn/problems/208/learning

#include<bits/stdc++.h>
using namespace std;
int num[9]={1,2,3,4,5,6,7,8,9};
int check(int L,int R){       //计算数字
    int res=0;
    for(int i=L;i<=R;i++)   res=res*10+num[i];
    return res;
}
int main(){
    int n; cin>>n;
    int cnt=0;
    while(next_permutation(num,num+9)){
        for(int i=0;i<7;i++){
            for(int j=i+1;j<8;j++){
                int a = check(0,i);
                int b = check(i+1,j);
                int c = check(j+1,8);
                if(a*c+b == c*n)  cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
