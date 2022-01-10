#include<iostream>
#include<iomanip>
#include<vector> 
#include<stack>
#include<queue> 
#include<cstdio>
using namespace std;

int main()
{
	int x=91,y=100;
	int count=0;
	while(y>0){
		if(x>100){
			x-=10;
			y--;
			count++;
		}
		else{
			x++;
		}
	} 
	cout<<"count: "<<count<<endl;
	
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
