/*
 * @Author: Outsider
 * @Date: 2021-11-21 16:39:27
 * @LastEditors: Outsider
 * @LastEditTime: 2021-11-27 20:13:31
 * @Description: In User Settings Edit
 * @FilePath: \DataStructureTest\test2\ThreadBinaryTree.cpp
 */
#include<iostream>
using namespace std;

struct ThreadBinaryTree
{
    char data;                //节点数据
    ThreadBinaryTree* left;   //左孩子
    ThreadBinaryTree* right;  //右孩子
    ThreadBinaryTree* next;   //作为栈节点时的指针域
    int ltag,rtag;            //标记指向前驱后继还是左右孩子

    ThreadBinaryTree(){      //构造函数初始化
        this->left=nullptr;
        this->right=nullptr;
        this->next=nullptr;
        this->rtag=0;
        this->ltag=0;
    }
};

/**
 * @description: 入栈函数
 * @param {ThreadBinaryTree*} &stack 栈头指针
 * @param {ThreadBinaryTree*} &tree  指向树头结点的指针
 * @return {*}
 */
void push_stack(ThreadBinaryTree* &stack,ThreadBinaryTree* &tree)
{
    tree->next=stack;
    stack=tree;
}

/**
 * @description: 获取栈顶元素
 * @param {ThreadBinaryTree*} &stack //栈的头指针
 * @return {*}  树节点的引用
 */
ThreadBinaryTree* & get_top(ThreadBinaryTree* &stack)
{
    return stack;
}

/**
 * @description: 栈顶元素出栈，出栈不回收内存 
 * @param {ThreadBinaryTree*} &stack 栈头指针
 * @return {*}
 */
void pop_stack(ThreadBinaryTree* &stack)
{
    if(stack)
    {
        stack=stack->next;//不释放节点
    }
}

/**
 * @description: 创建二叉树
 * @param {ThreadBinaryTree*} &threadbinarytree
 * @param {ThreadBinaryTree*} &stack
 * @param {string} s
 * @return {*}
 */
void CreatBinaryTree(ThreadBinaryTree* &threadbinarytree,ThreadBinaryTree* &stack,string s)
{
    threadbinarytree=nullptr;
    ThreadBinaryTree *n=new ThreadBinaryTree();
    int flag=0;
    for(int i=0;i<s.length();i++)
    {
        switch (s[i])
        {
        case ')':
            pop_stack(stack);
            break;
        case '(':
            push_stack(stack,n);
            flag=1;
            break;
        case ',':
            flag=2;
            break;
        default:
            n=new ThreadBinaryTree();
            n->data=s[i];
            if(!threadbinarytree)
            {
                threadbinarytree=n;
            }
            else
            {
                switch (flag)
                {
                case 1:
                    get_top(stack)->left=n;
                    break;
                case 2:
                    get_top(stack)->right=n;
                    break;
                
                default:
                    break;
                }
            }
            break;
        }
    }
}

void recursion_pre_traverse(ThreadBinaryTree* threadbinarytree)
{
    if(!threadbinarytree)
        return;
    else
    {
        recursion_pre_traverse(threadbinarytree->left);
        cout<<threadbinarytree->data<<" ";
        recursion_pre_traverse(threadbinarytree->right);
    }
}

ThreadBinaryTree* pre=nullptr;
void med_threadbinarytree(ThreadBinaryTree* threadbinarytree)
{
    if(!threadbinarytree)
        return;
    else{
        med_threadbinarytree(threadbinarytree->left);
        if(!threadbinarytree->left){
            threadbinarytree->left=pre;
            threadbinarytree->ltag=1;
        }
        else
            threadbinarytree->ltag=0;
        if(pre&&!pre->right){
            pre->right=threadbinarytree;
            pre->rtag=1;
        }
        else{
            pre->rtag=0;
        }
        pre=threadbinarytree;
        med_threadbinarytree(threadbinarytree->right);
    }
}

void traversethreadtree(ThreadBinaryTree* head)
{
    ThreadBinaryTree* threadbinarytree=head->left;
    if(!threadbinarytree)
        return ;
    else{
        while(threadbinarytree!=head){
            while(threadbinarytree->ltag==0){
                threadbinarytree=threadbinarytree->left;
            }
            cout<<threadbinarytree->data<<' ';
            while(threadbinarytree->rtag==1&&threadbinarytree->right!=head){
                threadbinarytree=threadbinarytree->right;
                cout<<threadbinarytree->data<<" ";
            }
            threadbinarytree=threadbinarytree->right;
        }
    }
}

int main()
{
    string str="A(B(D,E(H(J,K(L,M(,N))),)),C(F,G(,I)))";
    ThreadBinaryTree* threadbinarytree=nullptr;
    ThreadBinaryTree* stack=nullptr;
    CreatBinaryTree(threadbinarytree,stack,str);
    recursion_pre_traverse(threadbinarytree);
    cout<<endl;

    //创建头节点
    ThreadBinaryTree* head=new ThreadBinaryTree();
    head->rtag=1;
    head->ltag=0;
    head->right=threadbinarytree;
    if(!threadbinarytree)//空的二叉树
        head->left=head;
    else{
        head->left=threadbinarytree;
        pre=head;
        med_threadbinarytree(threadbinarytree);
        pre->right=head;
        pre->rtag=1;
        head->right=pre;
    }
    traversethreadtree(head);
    
    system("pause");
}