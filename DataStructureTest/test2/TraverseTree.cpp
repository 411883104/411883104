/*
 * @Author: Outsider
 * @Date: 2021-11-20 16:44:42
 * @LastEditors: Outsider
 * @LastEditTime: 2021-11-28 16:22:09
 * @Description: In User Settings Edit
 * @FilePath: \DataStructureTest\test2\TraverseTree.cpp
 */

#include<iostream>
using namespace std;
struct BinaryTree
{
    char data;
    BinaryTree* left;
    BinaryTree* right;
    BinaryTree* next;
    BinaryTree(){
        this->left=nullptr;
        this->right=nullptr;
        this->next=nullptr;
    }

    BinaryTree(const BinaryTree& binarytree)
    {
        *this=binarytree;
    }
};


void push_stack(BinaryTree* &stack,BinaryTree* &tree)
{
    tree->next=stack;
    stack=tree;
}

BinaryTree* & get_top(BinaryTree* &stack)
{
    return stack;
}

void pop_stack(BinaryTree* &stack)
{
    if(stack)
    {
        BinaryTree* n=stack;
        stack=stack->next;//不释放节点
        n->next=nullptr;//将树节点的next置为空
    }
}

bool empty(BinaryTree* stack)
{
    if(!stack)
        return true;
    return true;
}

//递归前序遍历
void recursion_pre_traverse(BinaryTree* binarytree)
{
    if(!binarytree)
        return;
    else
    {
        cout<<binarytree->data<<" ";
        recursion_pre_traverse(binarytree->left);
        recursion_pre_traverse(binarytree->right);
    }
}

//递归中序遍历
void recursion_mid_traverse(BinaryTree* binarytree)
{
    if(!binarytree)
        return;
    else
    {
        recursion_mid_traverse(binarytree->left);
        cout<<binarytree->data<<" ";
        recursion_mid_traverse(binarytree->right);
    }
}

//递归后序遍历
void recursion_pos_traverse(BinaryTree* binarytree)
{
    if(!binarytree)
        return;
    else
    {
        recursion_pos_traverse(binarytree->left);
        recursion_pos_traverse(binarytree->right);
        cout<<binarytree->data<<" ";
    }
}

//非递归前序遍历
void pre_traverse(BinaryTree* binarytree,BinaryTree* &stack)
{
    if(!binarytree)
        return;
    else{
        push_stack(stack,binarytree);
        while(stack){
            BinaryTree* top=get_top(stack);
            pop_stack(stack);
            cout<<top->data<<' ';
            if(top->right){
                push_stack(stack,top->right);
            }
            if(top->left){
                push_stack(stack,top->left);
            }
        }
    }
    cout<<endl;
}
//非递归中序遍历
void med_traverse(BinaryTree* binarytree,BinaryTree* &stack)
{
    BinaryTree* top=binarytree;
    while(stack||top){
        if(top){
            push_stack(stack,top);
            top=top->left;
        }
        else{
            top=get_top(stack);
            cout<<top->data<<' ';
            pop_stack(stack);
            top=top->right;
        }
    }
    cout<<endl;
}

//非递归后序遍历
void pos_traverse(BinaryTree* binarytree,BinaryTree* stack)
{
    BinaryTree* top=binarytree;
    BinaryTree* flag=nullptr;
    if(!binarytree)
        return;
    else{
        while(top){
            push_stack(stack,top);
            top=top->left;
        }
        while(stack){
            if(stack){
                top=get_top(stack);
                pop_stack(stack);
                if(flag==top->right||!top->right){
                    cout<<top->data<<' ';
                    flag=top;
                }
                else{
                    push_stack(stack,top);
                    top=top->right;
                    while(top){
                    push_stack(stack,top);
                    top=top->left;
                    }
                }
            }
        }
        cout<<endl;
    }
}

/**
 * @description: 创建二叉树
 * @param {BinaryTree*} &binarytree 二叉树头指针
 * @param {BinaryTree*} &stack 栈头指针
 * @param {string} s 要处理的字符串
 * @return {*}
 */
void CreatBinaryTree(BinaryTree* &binarytree,BinaryTree* &stack,string s)
{
    binarytree=nullptr;             //初始化二叉树头指针 
    BinaryTree *n=new BinaryTree(); //要添加的树节点
    int flag=0;                     //标志，1为左孩子，2为右孩子
    for(int i=0;i<s.length();i++)   //处理每一个字符
    {
        switch (s[i])
        {
        case ')':
            pop_stack(stack);
            break;
        case '(':                  //后面可能为左孩子或,
            push_stack(stack,n);   //将当前节点压入栈
            flag=1;                //标志置为左孩子标志
            break;
        case ',':                  //后面可能有右孩子或)
            flag=2;                //标志为右孩子标志
            break;
        default:
            n=new BinaryTree();    //如果字符为字母则将字母加入树中
            n->data=s[i];
            if(!binarytree)        //处理为树的根节点
            {
                binarytree=n;
            }
            else
            {
                switch (flag)
                {
                case 1:
                    get_top(stack)->left=n;//左孩子
                    break;
                case 2:
                    get_top(stack)->right=n;//右孩子
                    break;
                
                default:
                    break;
                }
            }
            break;
        }
    }
}

int main()
{
    string str="A(B(D,E(H(J,K(L,M(,N))),)),C(F,G(,I)))";
    BinaryTree* binarytree=nullptr;
    BinaryTree* stack=nullptr;
    CreatBinaryTree(binarytree,stack,str);
    recursion_pre_traverse(binarytree);
    cout<<endl;
    recursion_mid_traverse(binarytree);
    cout<<endl;
    recursion_pos_traverse(binarytree);
    cout<<endl;
    pre_traverse(binarytree,stack);
    med_traverse(binarytree,stack);
    pos_traverse(binarytree,stack);
    system("pause");
}