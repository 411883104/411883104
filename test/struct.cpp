/*
 * @Author: Outsider
 * @Date: 2022-01-11 19:40:08
 * @LastEditors: Outsider
 * @LastEditTime: 2022-01-11 20:46:47
 * @Description: In User Settings Edit
 * @FilePath: \C++\test\struct.cpp
 */

#include<iostream>

using namespace std;

typedef struct LNode{
    int data;
    LNode* next;
}* LinkList;

int main()
{
    LinkList p=new LNode();
    cout<<p->data<<endl;

    system("pause");
}