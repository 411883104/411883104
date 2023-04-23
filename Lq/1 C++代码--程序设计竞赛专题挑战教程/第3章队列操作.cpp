//¶ÓÁÐ²Ù×÷  https://www.lanqiao.cn/problems/1519/learning/

#include <bits/stdc++.h>
using namespace std;
int main(){
	queue<int> q;
	int n;  cin>>n;
    while(n--){
		int num;  cin>>num;
		switch(num){
			case 1:
				int element; 	cin>>element;
                q.push(element);
				break;
			case 2:
                if(q.empty()==0){ cout<<q.front()<<endl; q.pop();}
				else{			  cout<<"no"<<endl;		return 0;}
				break;
			case 3:
			    cout<<q.size()<<endl;
				break;
		}
	}
	return 0;
}
