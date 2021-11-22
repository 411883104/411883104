/*
 * @Author: Outsider
 * @Date: 2021-11-15 13:59:39
 * @LastEditors: Outsider
 * @LastEditTime: 2021-11-20 16:43:34
 * @Description: In User Settings Edit
 * @FilePath: \DataStructureTest\test2\BinaryTree.cpp
 */
#include<iostream>
#include<stack>
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
        stack=stack->next;//不释放节点
    }
}

void pre_traverse(BinaryTree* binarytree)
{
    if(!binarytree)
        return;
    else
    {
        cout<<binarytree->data<<" ";
        pre_traverse(binarytree->left);
        pre_traverse(binarytree->right);
    }
}

void mid_traverse(BinaryTree* binarytree)
{
    if(!binarytree)
        return;
    else
    {
        mid_traverse(binarytree->left);
        cout<<binarytree->data<<" ";
        mid_traverse(binarytree->right);
    }
}

void pos_traverse(BinaryTree* binarytree)
{
    if(!binarytree)
        return;
    else
    {
        pos_traverse(binarytree->left);
        pos_traverse(binarytree->right);
        cout<<binarytree->data<<" ";
    }
}

void find_node(BinaryTree* binarytree,char c)
{
    if(!binarytree||binarytree->data==c)
    {
        if(!binarytree)
            return;
        if(binarytree->left)
            cout<<binarytree->left->data<<endl;
        if(binarytree->right)
            cout<<binarytree->right->data<<endl;
        return;
    }
    else
    {
        find_node(binarytree->left,c);
        find_node(binarytree->right,c);
    } 
}

int count_node(BinaryTree* binarytree)
{
    if(!binarytree)
        return 0;
    else
    {
        int left=count_node(binarytree->left);
        int right=count_node(binarytree->right);
        return left+right+1;
    }
}

int count_leaf(BinaryTree* binarytree)
{
    if(!binarytree)
        return 0;
    if(!binarytree->left&&!binarytree->right)
        return 1;
    else{
        int left=count_leaf(binarytree->left);
        int right=count_leaf(binarytree->right);
        return left+right;
    }
}

int hight(BinaryTree* binarytree)
{
    if(!binarytree)
        return 0;
    else
    {
        int left=hight(binarytree->left);
        int right=hight(binarytree->right);
        return [&left,&right]()->int{return (left>right?left:right)+1;}();
    }
}

// void printtree(BinaryTree* binarytree,int level)
// {
//     if(!binarytree)
//         return;
//     printtree(binarytree->left,level+1);
//     for(int i=0;i<level;i++)
//         cout<<" ";
//     cout<<binarytree->data<<endl;
//     printtree(binarytree->right,level+1);
// }

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
    pre_traverse(binarytree);
    cout<<endl;
    mid_traverse(binarytree);
    cout<<endl;
    pos_traverse(binarytree);
    cout<<endl;
    find_node(binarytree,'H');
    //printtree(binarytree,1);
    cout<<count_node(binarytree)<<endl;
    cout<<count_leaf(binarytree)<<endl;
    cout<<hight(binarytree)<<endl;
    system("pause");
}