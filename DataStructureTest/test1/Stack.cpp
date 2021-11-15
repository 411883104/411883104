/*
 * @Author: Outsider
 * @Date: 2021-11-07 20:36:41
 * @LastEditors: Outsider
 * @LastEditTime: 2021-11-14 14:52:04
 * @Description: In User Settings Edit
 * @FilePath: \DataStructureTest\test1\Stack.cpp
 */
#include<iostream>
#include<ctime>
#include<stdlib.h>
using namespace std;

struct Stack{
    int data;
    Stack* next;
};

bool init_stack(Stack* &stack)//初始化栈
{
    stack=nullptr;
    return true;
}

//入栈
bool push_stack(Stack* &stack,int num)
{
    Stack* n=new Stack();
    n->data=num;
    n->next=stack;
    stack=n;
    return true;
}

//出栈
bool pop_stack(Stack* &stack)
{
    Stack* d=nullptr;
    if(stack)
    {
        d=stack;
        stack=stack->next;
        delete d;
        return true;
    }
    return false;
}

//获取栈顶元素
int get_top(Stack* stack)
{
    if(stack)
        return stack->data;
}

int main()
{
    time_t t;
    srand((unsigned)time(&t));

    Stack* stack=nullptr;
    if(init_stack(stack))
    {
        for(int i=0;i<10;i++)
            push_stack(stack,rand()%899+100);
        while(stack)
        {
            cout<<get_top(stack)<<" ";
            pop_stack(stack);
        }
        cout<<endl;
    }
    system("pause");
}