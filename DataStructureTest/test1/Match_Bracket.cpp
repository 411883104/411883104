/*
 * @Author: Outsider
 * @Date: 2021-11-12 19:10:25
 * @LastEditors: Outsider
 * @LastEditTime: 2021-11-14 16:37:06
 * @Description: In User Settings Edit
 * @FilePath: \DataStructureTest\test1\Match_Bracket.cpp
 */
#include<iostream>
using namespace std;
struct Stack{
    char data;
    Stack* next;
};

bool init(Stack* &stack)
{
    stack=nullptr;
    return true;
}
void push(Stack* &stack,char c)
{
    Stack* n=new Stack();
    n->data=c;
    n->next=stack;
    stack=n;
}
char top(Stack* stack)
{
    if(stack)
        return stack->data;
}

void pop(Stack* &stack)
{
    Stack* d=new Stack();
    if(stack)
    {
        d=stack;
        stack=stack->next;
    }
    delete d;
}

void clear(Stack* &stack)
{
    while(stack)
    {
        Stack* d=nullptr;
        stack=stack->next;
        delete d;
    }
}

bool match(Stack* &stack,string s)
{
    clear(stack);
    for(int i=0;i<s.length();i++)
    {
        if(!stack)
            push(stack,s[i]);
        else{
            //判断括号是否匹配
            if((top(stack)=='('&&s[i]==')')||(top(stack)=='{'&&s[i]=='}')||(top(stack)=='['&&s[i]==']'))
                pop(stack);//匹配则出栈
            else
                push(stack,s[i]);//不匹配则入栈
        }
    }
    if(stack)
        return false;
    else    
        return true;
}

int main()
{
    string s;
    Stack* stack=nullptr;
    init(stack);
    while(cin>>s&&s!="q")
        cout<<"result: "<<match(stack, s) << endl;
}