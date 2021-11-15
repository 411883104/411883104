/*
 * @Author: Outsider
 * @Date: 2021-11-12 18:25:05
 * @LastEditors: Outsider
 * @LastEditTime: 2021-11-14 19:08:20
 * @Description: In User Settings Edit
 * @FilePath: \DataStructureTest\test1\Split_List.cpp
 */
#include<iostream>
#include<ctime>
#include<stdlib.h>
using namespace std;

struct List{
    int data;
    List* next;
};

bool init_list(List* &list)
{
    list=new List();
    if(list)
    {
        list->next=nullptr;
        return true;
    }
    return false;
}

//插入节点
void push(List* &list,int num)
{
    List* n=new List();
    n->data=num;
    n->next=list->next;
    list->next=n;
}

//遍历链表
void traverse(List* list)
{
    while(list->next)
    {
        cout<<list->next->data<<' ';
        list=list->next;
    }
    cout<<endl;
}

//将小于输入值的节点往前插
void split(List* &list,int num)
{
    /*
    首元节点不做处理，首元节点无论大于还是小于输入的值都不影响结果
    因为首元节点如果大于输入的值，则后面小于输入值的节点会往前插
    首元节点如果小于输入的值，则首元节点必满足条件
    从而避免首元节点插到首元节点前而（自己指向自己）造成的死循环
    */
    List* pre=list->next;
    List* p=pre->next;

    while(p)
    {
        if(p->data<num)
        {
            pre->next=pre->next->next;
            p->next=list->next;
            list->next=p;
            p=pre->next;
        }
        else
        {
            pre=p;
            p=p->next;
        }
    }
}

int main()
{
    time_t t;
    srand(unsigned(time(&t)));
    List* list=nullptr;
    if(init_list(list))
    {
        for(int i=0;i<10;i++)
        {
            push(list,rand()%899+100);
        }
        traverse(list);

        int num=0;
        cout<<"input num: "; 
        cin>>num;
        split(list,num);
        traverse(list);
    }
    system("pause");
}