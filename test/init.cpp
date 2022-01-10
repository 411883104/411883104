#include<iostream>
using namespace std;

struct Node{
int date;
Node* next;
};

void use(Node node){
node.next=new Node();
}

int main(){
Node node;
use(node);
return 0;
}
