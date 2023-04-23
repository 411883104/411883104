//自行车停放 https://www.lanqiao.cn/problems/1518/learning/

#include <bits/stdc++.h>
using namespace std;
list<int>::iterator locate[100003];    //小技巧
int main(){
   int n,a; cin>>n>>a;
   list<int> L;                        //链表
   L.push_back(a);                     //插入第一个编号
   locate[a] = L.begin();              //迭代器地址存入数组
   n--;
   while(n--){
        int x,y,z; cin>>x>>y>>z;
        list<int>::iterator temp = locate[y];
        if(z==0){                     //把x插到y的左边
            L.insert(temp,x);
            locate[x] = --temp; //将新插入的元素地址记录到数组中
		}
   	    else{
            L.insert(++temp,x);
            locate[x] = --temp;
        }
	}
    for(list<int>::iterator it=L.begin();it!=L.end();it++)
	    cout << *it <<" ";
    return 0;
}
