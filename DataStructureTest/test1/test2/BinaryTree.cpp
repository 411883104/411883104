/*
 * @Author: Outsider
 * @Date: 2021-11-15 13:59:39
 * @LastEditors: Outsider
 * @LastEditTime: 2021-11-15 14:54:08
 * @Description: In User Settings Edit
 * @FilePath: \DataStructureTest\test1\test2\BinaryTree.cpp
 */
#include<iostream>
#include<stack>
using namespace std;
 
struct BinaryTree
{
    int data;
    BinaryTree* left;
    BinaryTree* right;
};

struct Stack{
    char data;
    Stack* next;
};

void push(Stack* &stack,char c)
{
    Stack* n=new Stack();
    n->data=c;
    n->next=stack;
    stack=n;
}

char get_top(Stack* stack)
{
    if(stack)
        return stack->data;
}

void pop(Stack* &stack)
{
    if(stack)
    {
        Stack* d= new Stack();
        stack->next=stack->next->next;
        delete d;
    }
}

bool CreatBinaryTree(BinaryTree* binarytree,char c)
{

}

int main()
{
    string str="A(B(D,E(H(J,K(L,M(,N))),)),C(F,G(,I)))";
    BinaryTree* binarytree=nullptr;
    for(int i=0;i<str.length();i++)
    {
        
    }
}