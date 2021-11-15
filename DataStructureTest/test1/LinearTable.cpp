/*
 * @Author: Outsider
 * @Date: 2021-11-01 14:08:55
 * @LastEditors: Outsider
 * @LastEditTime: 2021-11-14 16:07:25
 * @Description: In User Settings Edit
 * @FilePath: \DataStructureTest\test1\LinearTable.cpp
 */
#include <iostream>
#include <ctime>    //定义了time的头文件
#include <stdlib.h> //定义了rand()和srand()的头文件
using namespace std;

struct List//定义链表节点
{
    int data;//数据域
    List *next;//指针域
};

//初始化链表
bool init(List* &list)//传入引用参数，函数体内直接修改指针
{
    list = new List();//创建头节点
    list->data = 0;//用头节点数据域存储链表长度
    list->next = nullptr;
    if (list)
        return true;
    else
        return false;
}

//头插法插入节点
bool push(List *&list, int num)
{
    List *n = new List();
    n->next = list->next;
    n->data = num;
    list->next=n;
    list->data++;
    return true;
}

void insert(List *&list, int num, int index)
{
    if (index > list->data+1)//判断位置是否合理
    {
        cout<<"index error!"<<endl;
    }
    else
    {
        List *pre = list;
        int cur = 0;
        while (pre->next)
        {
            if (cur == index - 1)//处于插入的位置则跳出循环
                break;
            else//否则指针后移
            {
                pre = pre->next;
                cur++;
            }
        }
        //插入节点
        List *n = new List();
        n->next = pre->next;
        n->data = num;
        pre->next = n;
        list->data++;
        cout<<"insert succeeded!"<<endl;
    }
}

//遍历链表
void traverse(List *list)
{
    list = list->next; //跳过头节点
    while (list)
    {
        cout << list->data << " ";
        list = list->next;
    }
    cout << endl;
}


void find(List *list, int num)
{
    List *pre = list->next;//从首元节点开始
    int index = 1;
    cout << "index: ";
    while (pre)
    {
        if (num == pre->data)//如果值相同则输出下标位置
            cout<< index << " ";//多个相同值则输出多个位置
        pre = pre->next;
        index++;
    }
    cout << endl;
}

//反转链表
void reverse(List* &list)
{
    List *p=list->next,*q=nullptr;
    list->next=nullptr;
    while(p)
    {
        q=p->next;
        p->next=list->next;
        list->next=p;//头插法插入节点
        p=q;
    }
}

//删除节点
void delete_node(List* &list,int num)
{
    List* pre=list->next;
    List* d=nullptr;
    int list_long=list->data;//记录表长，用于判断是否删除成功
    while(pre->next)//不处理最后一个节点，最后一个节点另作处理
    {
        if(pre->data==num)
        {
            pre->data=pre->next->data;//后一个节点的值赋给前一个节点的数据域
            d=pre->next;//删除后一个节点
            pre->next=pre->next->next;//把要删除的节点移出链表
            delete d;
            list->data--;
            //pre指针不后移，避免在两个相同的数相邻的情况下只删除一个
        }
        else
            pre=pre->next;
    }
    List *q=list;
    if(pre->data==num)//处理最后一个节点
    {
        while(q->next->next)
            q=q->next;
        q->next=nullptr;
        delete pre;
        list->data--;
    }
    if(list_long!=list->data)
        cout<<"delete succeeded！"<<endl;
    else
        cout<<"delete failed！"<<endl;
}

int main()
{
    time_t t;
    srand((unsigned)time(&t));
    List *head = NULL;
    if (init(head))
    {
        for (int i = 0; i < 10; i++)
            push(head,rand()%899+100); //生成100~999的随机数,头插法插入
        cout<<"quit:0   traverse:1   find:2   insert:3   delete:4  reverse:5"<<endl;
        int op=0;
        cout<<"op=";
        while(cin>>op&&op!=0)
        {
            int num=0,index=0;
            switch (op)
            {
            case 0:
            return 0;
                break;
            case 1:
                cout<<"traverse list: ";
                traverse(head);
                break;
            case 2:
                cout<<"find num: ";
                cin>>num;
                find(head,num);
                break;
            case 3:
                cout<<"insert num: ";
                cin>>num;
                cout<<"insert index: ";
                cin>>index;
                insert(head,num,index);
                break;
            case 4:
                cout<<"delete num: ";
                cin>>num;
                delete_node(head,num);
                break;
            case 5:
                cout<<"reverse list: ";
                reverse(head);
                traverse(head);
                break;
            default:
                break;
            }
            cout<<"op=";
        }
    }
    
    system("pause");
}
