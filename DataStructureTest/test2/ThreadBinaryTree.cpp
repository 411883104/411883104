/*
 * @Author: Outsider
 * @Date: 2021-11-21 16:39:27
 * @LastEditors: Outsider
 * @LastEditTime: 2021-11-22 14:41:10
 * @Description: In User Settings Edit
 * @FilePath: \DataStructureTest\test2\ThreadBinaryTree.cpp
 */
#include<iostream>
using namespace std;

struct ThreadBinaryTree
{
    char data;
    ThreadBinaryTree* left,*right;
    ThreadBinaryTree* next;
    int ltag,rtag;

    ThreadBinaryTree(){
        this->left=nullptr;
        this->right=nullptr;
        this->next=nullptr;
    }
};


void push_stack(ThreadBinaryTree* &stack,ThreadBinaryTree* &tree)
{
    tree->next=stack;
    stack=tree;
}

ThreadBinaryTree* & get_top(ThreadBinaryTree* &stack)
{
    return stack;
}

void pop_stack(ThreadBinaryTree* &stack)
{
    if(stack)
    {
        stack=stack->next;//不释放节点
    }
}

void med_thread(ThreadBinaryTree* &threadbinarytree)
{
    
}
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

void med_threadbinarytree(ThreadBinaryTree* threadbinarytree)
{
    ThreadBinaryTree* pre=new ThreadBinaryTree();
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
        if(!pre->right){
            pre->right=pre;
            pre->rtag=1;
        }
        else
            pre->rtag=0;
        pre=threadbinarytree;
        med_threadbinarytree(threadbinarytree->right);
    }
}

void traversethreadtree(ThreadBinaryTree* threadbinarytreee)
{
    if(!threadbinarytreee)
        return ;
    else{
        while(threadbinarytreee->ltag==0){
            threadbinarytreee=threadbinarytreee->left;
        }
        cout<<threadbinarytreee->data<<' ';
        while(threadbinarytreee->rtag==1){
            threadbinarytreee=threadbinarytreee->right;
        }
        cout<<threadbinarytreee->data<<' ';
        threadbinarytreee=threadbinarytreee->right;
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
    med_threadbinarytree(threadbinarytree);
    traversethreadtree(threadbinarytree);
}