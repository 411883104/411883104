//汉诺塔 https://www.lanqiao.cn/problems/1512/learning/

#include<bits/stdc++.h>
using namespace std;
const int N = 30;
int sum = 0, m;
struct mystack{
    int a[N];                            //存放栈元素
    int t = -1;                          //栈顶位置
    void push(int x){ a[++t] = x; }      //把x送入栈
    int top()       { return a[t];}      //返回栈顶元素
    void pop()      { t--;        }      //弹出栈顶
    int empty()     { return t==0?1:0;}  //返回1表示空
}st[4];         //定义三个柱子，st[1]、st[2]、st[3]。st[0]不用
void move(int x, int y,int n){           //移动圆盘
	int element = st[x].top();           //从杆子x上取出顶部的圆盘放到杆子y上
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
	for(int i=n;i>=1;i--) //初始状态：在第1个杆子上添加n个圆盘
	    st[1].push(i);
	hanoi(n,1,2,3);
    cout<<sum<<endl;
	return 0;
}
