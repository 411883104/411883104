/*
 * @Author: Outsider
 * @Date: 2021-11-15 13:59:39
 * @LastEditors: Outsider
 * @LastEditTime: 2021-11-27 20:58:57
 * @Description: In User Settings Edit
 * @FilePath: \DataStructureTest\test2\BinaryTree.cpp
 */
#include<iostream>
using namespace std;
 
struct BinaryTree       //二叉树节点
{
    char data;          //节点数据
    BinaryTree* left;   //左孩子
    BinaryTree* right;  //右孩子
    BinaryTree* next;   //作为栈节点时的指针域
    BinaryTree(){       //构造函数进行初始化
        this->left=nullptr;
        this->right=nullptr;
        this->next=nullptr;
    }

    // BinaryTree(const BinaryTree& binarytree)
    // {
    //     *this=binarytree;
    // }
};

/**
 * @description:  节点入栈
 * @param {BinaryTree*} &stack  栈头指针
 * @param {BinaryTree*} &tree   树的头指针
 * @return {*}
 */
void push_stack(BinaryTree* &stack,BinaryTree* &tree)
{
    tree->next=stack;
    stack=tree;
}

/**
 * @description:  获取栈顶元素
 * @param {BinaryTree*} &stack 栈的头指针
 * @return {*}  二叉树节点的应用
 */
BinaryTree* & get_top(BinaryTree* &stack)
{
    return stack;
}

/**
 * @description: 栈顶元素出栈，不释放节点的存储空间
 * @param {BinaryTree*} &stack 栈头指针
 * @return {*}
 */
void pop_stack(BinaryTree* &stack)
{
    if(stack)
    {
        stack=stack->next;//不释放节点
    }
}

/**
 * @description: 递归先序遍历二叉树
 * @param {BinaryTree*} binarytree 二叉树的头指针
 * @return {*}
 */
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

/**
 * @description: 递归中序遍历二叉树
 * @param {BinaryTree*} binarytree
 * @return {*}
 */
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

/**
 * @description: 递归后序遍历二叉树
 * @param {BinaryTree*} binarytree
 * @return {*}
 */
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

/**
 * @description: 查找指定值的节点的左右孩子的值
 * @param {BinaryTree*} binarytree
 * @param {char} c 要查找的节点的值
 * @return {*}
 * @output 输出节点左右孩子节点值
 */
void find_node(BinaryTree* binarytree,char c)
{
    if(!binarytree||binarytree->data==c)//如果存在匹配的节点或结点为空进入判断
    {
        if(!binarytree)
            return;
        if(binarytree->left)//有左节点则输出
            cout<<binarytree->left->data<<endl;
        if(binarytree->right)//有右节点则输出
            cout<<binarytree->right->data<<endl;
        return;
    }
    else//未找到或非空节点则递归查找
    {
        find_node(binarytree->left,c);
        find_node(binarytree->right,c);
    } 
}

/**
 * @description: 计算二叉树节点数
 * @param {BinaryTree*} binarytree 二叉树头指针
 * @return {*}  二叉树节点数
 */
int count_node(BinaryTree* binarytree)
{
    if(!binarytree)//节点为空则返回0
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