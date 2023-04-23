//修改数组 2019年第十届省赛  https://www.lanqiao.cn/problems/185/learning/
#include<bits/stdc++.h>
using namespace std;
const int N=1000002;
int A[N];
int s[N];  //并查集
int find_set(int x){            //用“路径压缩”优化的查询
    if(x != s[x])  s[x] = find_set(s[x]);   //路径压缩
    return s[x];
}
int main(){
    for(int i=1;i<N;i++)  s[i]=i; //并查集初始化
    int n;   scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&A[i]);
        int root = find_set(A[i]);    //查询到并查集的根
        A[i] = root;
        s[root] = find_set(root+1);   //加1
    }
    for(int i=1;i<=n;i++)  printf("%d ",A[i]);
    return 0;
}
