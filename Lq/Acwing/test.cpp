#include<iostream>
#include<map>
#include<list>

using namespace std;

int main(){
	list<int>l;
	l.push_back(5);
	l.push_back(3);
	l.push_back(2);
	l.push_back(8);
	l.push_back(0);
	l.push_back(7);l.push_back(5);l.push_back(5);
	for(auto n:l){
		cout<<n<<" ";
	}
	cout<<endl;
	l.remove(5);
	for(auto n:l){
		cout<<n<<" ";
	}
	cout<<endl;
} 
