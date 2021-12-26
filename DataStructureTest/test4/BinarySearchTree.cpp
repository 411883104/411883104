/*
 * @Author: Outsider
 * @Date: 2021-12-24 20:31:42
 * @LastEditors: Outsider
 * @LastEditTime: 2021-12-25 23:48:15
 * @Description: 二叉查找树创建，查找和删除节点的实现
 * @FilePath: \DataStructureTest\test4\BinarySearchTree.cpp
 */
#include<iostream>
using namespace std;

typedef struct BinaryTreeNode{  //二叉树的节点
    char c;                     //节点数据
    BinaryTreeNode* left;       //左孩子
    BinaryTreeNode* right;      //右孩子
}BinaryTree;

/**
 * @description: 通过添加节点创建二叉查找树
 * 如果数据比当前节点的数据小则往左子树查找
 * 如果数据比当前节点的数据大则往右子树查找
 * @param {BinaryTree* &} binarytree 二叉树头指针
 * @param {char} c 节点数据
 * @return {*}
 */
void CreateBST(BinaryTree* & binarytree,char c){
    if(!binarytree){   //为空时则插入节点
        BinaryTree* node=new BinaryTree();
        node->c=c;
        node->left=nullptr;
        node->right=nullptr;
        binarytree=node;
    }
    else{
        if(c<binarytree->c){
            CreateBST(binarytree->left,c);
        }
        if(c>binarytree->c){
            CreateBST(binarytree->right,c);
        }
    }
}


/**
 * @description: 递归中序遍历二叉树
 * @param {BinaryTree*} binarytree 二叉树头指针
 * @return {*}
 */
void Traverse(BinaryTree* binarytree){
    if(!binarytree){
        return;
    }
    else{
        Traverse(binarytree->left);
        cout<<binarytree->c<<" ";
        Traverse(binarytree->right);
    }
}

/**
 * @description: 
 * @param {BinaryTree*} binarytree
 * @param {char} c
 * @return {*}
 */
BinaryTreeNode* Serach(BinaryTree* binarytree,char c){
    if(!binarytree){
        return binarytree;
    }
    else{
        if(binarytree->c=c){
            return binarytree;
        }
        else{
            if(binarytree->c>c){
                Serach(binarytree->left,c);
            }
            if(binarytree->c<c){
                Serach(binarytree->right,c);
            }
        }
    }
}

/**
 * @description: 查找节点后删除该节点
 * 1、如果要删除的节点的左子树为空，则用右子树代替删除的节点
 * 2、如果要删除的节点的右子树为空，则用左子树代替删除的节点
 * 3、如果要删除的节点的左右子树非空，则可以将要删除的节点的直接前驱或直接后继代替
 * @param {BinaryTree*} &binarytree 查找二叉树的头指针
 * @param {char} c 要查找的节点树
 * @return {*}
 */
void DeleteNode(BinaryTree* &binarytree,char c){
    BinaryTree* p=binarytree;//p用于记录待删除的节点
    BinaryTree* parent=nullptr;//待删除节点的父节点
    BinaryTree* q=nullptr;//待删除节点的直接前驱的父节点
    BinaryTree* s=nullptr;//用于记录待删除节点的直接前驱
    if(!p){             //空树返回
        return;
    }
    while(p){           //查找节点
        if(p->c==c){
            break;
        }
        parent=p;       //parent为p节点的双亲
        if(p->c>c){     //比当前节点的数据小则往左子树查找
            p=p->left;
        }
        else{           //比当前节点的数据大则往右子树查找
            p=p->right;
        }
    }
    if(!p){             //没有找到要删除的节点则返回
        return;
    }
    else{               //找到节点则删除
        if((p->left)&&(p->right)){  //要删除节点的左右孩子非空
            q=p;        //初始化q
            s=q->left;  //初始化s
            while(s->right){    //寻找待删节点的直接前驱
                q=s;            //q为s节点的父节点
                //待删节点的直接前驱为其左子树的最右节点，每一次都往右寻找，直至非空
                s=s->right;     
            }
            p->c=s->c;          //将直接前驱的节点数据赋值至待删节点
            if(q!=p){           //将直接前驱的左子树悬挂到其父节点上
                q->right=s->left;
            }
            else{               //将直接前驱的左子树悬挂到其父节点上
                q->left=s->left;
            }
            delete s;
        }
        else{
            if(p->left==nullptr){
                q=p;
                p=p->right;
            }
            else{
                q=p;
                p=p->left;
            }
            if(!parent)       //删除的节点为根节点
            {
                binarytree=p; //将根节点改为
            }
            else{
                if(q==parent->left){
                    parent->left=p;
                }
                else{
                    parent->right=p;
                }
            }
            delete q;
        }
    }
}

int main(){
    BinaryTree* binarytree=nullptr;
    char data;
    for(int i=0;i<10;i++){
        cin>>data;
        CreateBST(binarytree,data);
    }
    Traverse(binarytree);

    cin>>data;
    DeleteNode(binarytree,data);
    Traverse(binarytree);
    system("pause");
}