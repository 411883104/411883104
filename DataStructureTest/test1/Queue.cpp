/*
 * @Author: Outsider
 * @Date: 2021-11-08 14:30:50
 * @LastEditors: Outsider
 * @LastEditTime: 2021-11-14 16:02:01
 * @Description: In User Settings Edit
 * @FilePath: \DataStructureTest\test1\Queue.cpp
 */

#include<iostream>
#include<ctime>
#include<stdlib.h>

using namespace std;

struct Node{
    int data;
    Node* next;
};

struct Queue
{
    Node* head;
    Node* tail;
};

//初始化队列
bool init_quene(Queue* &queue)
{
    queue->head=queue->tail=new Node();//创建头节点
    queue->tail->next=nullptr;
    return true;
}

void push_queue(Queue* &queue,Node* &node)
{
    node->next=nullptr;
    queue->tail->next=node;
    queue->tail=node;
}

void pop_queue(Queue* queue)
{
    Node* d=nullptr;
    if(queue->head!=queue->tail)
    {
        d=queue->head->next;
        queue->head->next=queue->head->next->next;
        if(d==queue->tail)//如果是最后一个节点出队，改变尾指针的指向
            queue->tail=queue->head;
        delete d;
    }
}

//获取对头元素
int get_head(Queue* queue)
{
    if(queue->head!=queue->tail)
    {
        return queue->head->next->data;
    }
    else
        return 0;//队列为空时返回0
}

//遍历队列
void traverse_quene(Queue* queue)
{
    Node*pre=queue->head->next;
    while(pre)
    {
        cout<<pre->data<<" ";
        pre=pre->next;
    }
    cout<<endl;
}

//反转队列
void reverse_queue(Queue* &queue)
{
    queue->tail=queue->head->next;//尾指针指向首元节点
    queue->head->next=nullptr;
    while(queue->tail)//对尾指针后的节点采用前插法插入头节点后
    {
        Node* p=queue->tail->next;
        queue->tail->next=queue->head->next;
        queue->head->next=queue->tail;
        queue->tail=p;
    }
    Node* cur=queue->head;
    while(cur->next)//将尾指针指向尾节点
        cur=cur->next;
    queue->tail=cur;
}

int main()
{
    time_t t;
    srand((unsigned)time(&t));
    Queue* queue=new Queue();
    if(init_quene(queue))
    {
        for(int i=0;i<10;i++)
        {
            Node* n=new Node();
            n->data=rand()%899+100;
            push_queue(queue,n);
        }
        cout<<"traverse_queue: ";
        traverse_quene(queue);
        cout<<"resverse_queue: ";
        reverse_queue(queue);
        while(queue->head!=queue->tail)
        {
            cout<<get_head(queue)<<' ';
            pop_queue(queue);
        }
        cout<<endl;
    }
    system("pause");
}