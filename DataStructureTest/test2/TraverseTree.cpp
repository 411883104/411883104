/*
 * @Author: Outsider
 * @Date: 2021-11-20 16:44:42
 * @LastEditors: Outsider
 * @LastEditTime: 2021-11-21 16:36:53
 * @Description: In User Settings Edit
 * @FilePath: \DataStructureTest\test2\Traversetree.cpp
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

void CreatBinaryTree(BinaryTree* &binarytree,BinaryTree* &stack,string s)
{
    binarytree=nullptr;
    BinaryTree *n=new BinaryTree();
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
            n=new BinaryTree();
            n->data=s[i];
            if(!binarytree)
            {
                binarytree=n;
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