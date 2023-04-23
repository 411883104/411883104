//队列操作  https://www.lanqiao.cn/problems/1519/learning/

#include <bits/stdc++.h>
using namespace std;
#define MAXQSIZE 100003        //自定义队列大小
struct myqueue{
    int data[MAXQSIZE];        //分配静态空间
    int head;                  //队头，指向队头的元素
    int rear;                  //队尾，指向下一个可以放元素的空位置
    bool init(){               //初始化
        head = rear = 0;
        return true;
    }
    int size(){ return (rear - head + MAXQSIZE) % MAXQSIZE;}//返回队列长度
    bool empty(){             //判断队列是否为空
        if(size()==0) return true;
        else          return false;
    }
    bool push(int e){        //队尾插入新元素。新的rear指向下一个空的位置
         if((rear + 1) % MAXQSIZE == head ) return false; //队列满
         data[rear] = e;
         rear = (rear + 1) % MAXQSIZE;
         return true;
    }
    bool pop(int &e){        //删除队头元素，并返回它
         if(head == rear) return false;   //队列空
         e = data[head];
         head = (head + 1) % MAXQSIZE;
         return true;
    }
    int front(){ return data[head];}   //返回队首，但是不删除
}Q;
int main(){
	Q.init();                    //初始化队列
	int n;  cin>>n;
	for(int i=0;i<n;i++)	{
		int num;  cin>>num;
		switch(num){
			case 1:
				int element;  cin>>element;
                Q.push(element);
				break;
			case 2:
                if(!Q.empty()){
					cout<<Q.front()<<endl;
					int tmp;
					Q.pop(tmp);
				}
				else{ cout<<"no"<<endl;	return 0;}
				break;
			case 3:
			    cout<<Q.size()<<endl;
				break;
		}
	}
	return 0;
}
