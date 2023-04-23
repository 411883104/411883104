//汉诺塔 https://www.lanqiao.cn/problems/1512/learning/

#include<bits/stdc++.h>
using namespace std;
const int N = 30;
int sum = 0, m;
stack<int> st[4];
void move(int x, int y,int n){ //移动圆盘
	int element = st[x].top();  //从杆子x上取出顶部的圆盘放到杆子y上
	st[x].pop();
	st[y].push(element);
	sum++;
	char a,b;  //用于打印
	if(x==1)  a='A';  if(x==2)  a='B';  if(x==3)  a='C';
	if(y==1)  b='A';  if(y==2)  b='B';	if(y==3)  b='C';
	if(sum == m) cout<<"#"<<n<<": "<<a<<"->"<<b<<endl;
}
void hanoi(int n, int x, int y, int z){
	if(n==1) move(x,z,n);
	else{
	     hanoi(n-1, x, z, y);
	     move(x,z,n);
	     hanoi(n-1, y, x, z);
	}
}
int main(){
	int n;    cin>>n>>m;
	for(int i=n;i>=1;i--)
	    st[1].push(i);
	hanoi(n,1,2,3);
    cout<<sum<<endl;
	return 0;
}
