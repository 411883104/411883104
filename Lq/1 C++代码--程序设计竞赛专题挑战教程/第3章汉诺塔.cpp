//汉诺塔 https://www.lanqiao.cn/problems/1512/learning/

#include<bits/stdc++.h>
using namespace std;
int sum = 0, m;
void hanoi(char a,char b,char c,int n){ //递归函数
    if(n==1) {
        sum++;
        if(sum==m) cout<<"#"<<n<<": "<<a<<"->"<<c<<endl;
    }
    else {                              //把n层递归到n-1层
        hanoi(a,c,b,n-1);               //
        sum++;
        if(sum==m) cout<<"#"<<n<<": "<<a<<"->"<<c<<endl;
        hanoi(b,a,c,n-1);
    }
}
int main(){
    int n;    cin>>n>>m;
    hanoi('A','B','C',n);
    cout<<sum<<endl;
    return 0;
}
