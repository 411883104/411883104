#include<iostream>
#include<iomanip>
#include<vector> 
#include<stack>
#include<queue> 
#include<cstdio>
using namespace std;

int main()
{
	priority_queue<int>t;
	t.push(5);
	t.push(9);
	t.push(1);
	t.push(4);
	cout<<t.size()<<endl;
//	cout<<t.front()<<endl;
//	cout<<t.back()<<endl;
//	t.pop();
	cout<<t.top()<<endl;
	return 0;
}
