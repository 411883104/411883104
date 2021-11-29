/*
 * @Author: Outsider
 * @Date: 2021-11-21 16:39:27
 * @LastEditors: Outsider
 * @LastEditTime: 2021-11-28 21:37:04
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

//递归遍历二叉树
void recursion_med_traverse(ThreadBinaryTree* threadbinarytree)
{
    if(!threadbinarytree)
        return;
    else
    {
        recursion_med_traverse(threadbinarytree->left);
        cout<<threadbinarytree->data<<" ";
        recursion_med_traverse(threadbinarytree->right);
    }
}


ThreadBinaryTree* pre=nullptr;//记录刚访问过的节点
/**
 * @description: 中序线索化二叉树
 * @param {ThreadBinaryTree*} threadbinarytree
 * @return {*}
 */
void med_threadbinarytree(ThreadBinaryTree* &threadbinarytree)
{
    if(!threadbinarytree)//空树
        return;
    else{
        med_threadbinarytree(threadbinarytree->left);//左子树线索化
        if(!threadbinarytree->left){//为空则建立前驱线索
            threadbinarytree->left=pre;
            threadbinarytree->ltag=1;
        }
        else
            threadbinarytree->ltag=0;//非空指向左孩子节点
        if(pre&&!pre->right){        //建立后继线索
            pre->right=threadbinarytree;
            pre->rtag=1;
        }
        else{
            pre->rtag=0;      //非空则指向右孩子节点
        }
        pre=threadbinarytree;//记录访问过的节点
        med_threadbinarytree(threadbinarytree->right);//线索化右子树
    }
}

/**
 * @description:  中序线索化输出二叉树
 * @param {ThreadBinaryTree*} head 线索二叉树头节点
 * @return {*}
 */
void traversethreadtree(ThreadBinaryTree* head)
{
    cout<<"traversethreadtree: ";
    ThreadBinaryTree* threadbinarytree=head->left;//根节点
    if(!threadbinarytree)//空树
        return ;
    else{
        while(threadbinarytree!=head){//回到根节点遍历完成
            while(threadbinarytree->ltag==0){//查找开始遍历的节点
                threadbinarytree=threadbinarytree->left;
            }
            cout<<threadbinarytree->data<<' ';//输出开始节点
            while(threadbinarytree->rtag==1&&threadbinarytree->right!=head){//右线索遍历
                threadbinarytree=threadbinarytree->right;
                cout<<threadbinarytree->data<<" ";
            }
            threadbinarytree=threadbinarytree->right;//遍历右子树
        }
    }
}


/**
 * @description: 查找节点的前驱
 * @param {ThreadBinaryTree*} threadbinarytree 要查找前驱的节点
 * @return {*}
 */
void find_pioneer(ThreadBinaryTree* threadbinarytree){
    if(threadbinarytree->ltag==1)//如果有前驱线索，则节点左孩子指针所指为该节点前驱
        cout<<"pioneer: "<<threadbinarytree->left->data<<endl;
    else{  //没有前驱线索则该节点的前驱是该节点的左子树上中序的最后一个节点。
        threadbinarytree=threadbinarytree->left;//进入左子树查找
        while(threadbinarytree->rtag==0)
            threadbinarytree=threadbinarytree->right;
        cout<<"pioneer: "<<threadbinarytree->data<<endl;
    }
}

/**
 * @description:  查找节点的后继
 * @param {ThreadBinaryTree*} threadbinarytree 要查找后继的节点
 * @return {*}
 */
void find_succeed(ThreadBinaryTree* threadbinarytree){
    if(threadbinarytree->rtag==0)//如果该节点有后继线索，则节点的后继为该节点右孩子。
        cout<<"succeed: "<<threadbinarytree->right->data<<endl;
    else{ //如果没有后继线索，则该节点的后继为该节点右子树上中序的最后一个节点。
        threadbinarytree=threadbinarytree->right;
        while(threadbinarytree->ltag==0)
            threadbinarytree=threadbinarytree->left;
        cout<<"succeed: "<<threadbinarytree->data<<endl;
    }
}

int main()
{
    string str="A(B(D,E(H(J,K(L,M(,N))),)),C(F,G(,I)))";
    ThreadBinaryTree* threadbinarytree=nullptr;
    ThreadBinaryTree* stack=nullptr;
    CreatBinaryTree(threadbinarytree,stack,str);
    cout<<"recursion_med_traverse: ";
    recursion_med_traverse(threadbinarytree);
    cout<<endl;

    //创建头节点
    ThreadBinaryTree* head=new ThreadBinaryTree();
    head->rtag=1;
    head->ltag=0;
    head->right=threadbinarytree;
    if(!threadbinarytree)//空的二叉树
        head->left=head;
    else{
        head->left=threadbinarytree;//左孩子指向二叉树
        pre=head;
        med_threadbinarytree(threadbinarytree);//中序线索化二叉树
        pre->right=head;//中序线索化最后节点的右指针指向头节点
        pre->rtag=1;//中序线索化最后节点的右标记为指向后继节点
        head->right=pre;//头指针右孩子指向中序线索化最后一个节点
    }
    traversethreadtree(head);
    cout<<endl;
    
    find_pioneer(threadbinarytree);//查找根节点前驱

    find_succeed(threadbinarytree);//查找根节点后继
    //find_pioneer(threadbinarytree->left);//查找threadbinarytree->left前驱
    //find_succeed(threadbinarytree->left);//查找threadbinarytree->left后继
    system("pause");
}