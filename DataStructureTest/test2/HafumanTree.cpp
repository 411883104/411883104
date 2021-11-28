/*
 * @Author: Outsider
 * @Date: 2021-11-22 14:43:22
 * @LastEditors: Outsider
 * @LastEditTime: 2021-11-27 19:54:08
 * @Description: In User Settings Edit
 * @FilePath: \DataStructureTest\test2\HafumanTree.cpp
 */

#include<iostream>
using namespace std;

struct HafumanTree{
    int weight;         //权值
    char c;             //代表的字符
    int parent;         //父节点
    int left;           //左孩子
    int right;          //右孩子
};

//简单实现map映射
struct Map{             //采用链式存储，方便插入
    int sum;            //字符出现的次数
    char data;          //字符
    Map* next;          //指针域
};

struct HafumanCode{     
    char* cd;           //存储0和1字符数组
    int start;          //编码在cd数组中的开始位置
};

/**
 * @description:  初始化map
 * @param {Map*} &list map头指针
 * @return {*}
 */
void initMap(Map* &list){
    list=new Map();
    list->next=nullptr;
    list->data=0;
    list->sum=0;
}

/**
 * @description:  向map中插入数据 
 * @param {Map*} &list  map的头指针
 * @param {char} c  要插入map中的字符
 * @return {*}
 */
void addMap(Map* &list,char c){
    Map* pre=list;
    while(pre->next){
        //map中存在相同字符时将字符出现次数加1
        if(pre->next->data==c){
            (pre->next->sum)++;
            return;
        }
        pre=pre->next;
    }
    //map中没有相同字符时则将字符插入map
    Map* n=new Map();
    n->data=c;
    n->sum=1;
    n->next=list->next;
    list->next=n; 
    list->sum++;   //头节点记录不同字符个数
}

/**
 * @description: 查看map中的数据
 * @param {Map*} list map的头指针
 * @return {*}
 */
void traveMap(Map* list){
    while(list->next){
        cout<<"char: "<<list->next->data<<" count: "<<list->next->sum<<endl;
        list=list->next;
    }
}

/**
 * @description: 创建哈夫曼树
 * @param {HafumanTree} ht 存储哈夫曼树的数组
 * @param {int} n  叶子节点数目
 * @return {*}
 */
void createHafumanTree(HafumanTree ht[],int n){//n为叶子节点
    for(int i=0;i<2*n-1;i++)    //初始化
        ht[i].parent=ht[i].left=ht[i].right=-1;
    for(int i=n;i<2*n-1;i++)    //构造哈夫曼树
    {
        int left=-1,right=-1;
        int min1=0xffff,min2=0xffff;
        for(int j=0;j<=i-1;j++)//寻找两个较小的权值
        {
            if(ht[j].parent==-1) //只处理没有父节点的节点
            {
                if(ht[j].weight<min1){
                    min2=min1; //先把min1值赋给min2在更新min1
                    right=left;
                    min1=ht[j].weight;
                    left=j;  //循环到最后left为最小
                }
                else if(ht[j].weight<min2){
                    min2=ht[j].weight;
                    right=j; //循环到最后right为次小
                }
            }
        }
        ht[left].parent=i;//left节点的父节点为i
        ht[right].parent=i;//right节点的父节点为i
        ht[i].weight=ht[left].weight+ht[right].weight;//更新权值
        ht[i].left=left;//i节点的左孩子为left
        ht[i].right=right;//i的右孩子为right
    }
}

/**
 * @description: 根据map中的数据创建树节点，并将其存进哈夫曼树数组中 
 * @param {HafumanTree} ht  哈夫曼树数组
 * @param {Map*} list map头指针
 * @return {*}
 */
void createTreeNode(HafumanTree ht[],Map* list)
{
    int i=0;
    while(list->next){
        ht[i].c=list->next->data;//将map中的字符赋给树节点
        ht[i].weight=list->next->sum;//将map中字符出现次数赋给树节点
        list=list->next;
        i++;
    }
}

/**
 * @description: 构造哈夫曼编码
 * @param {HafumanTree} ht 存储哈夫曼树的数组
 * @param {HafumanCode} code 与哈夫曼树节点相对应的哈夫曼编码数组
 * @param {int} n 叶子节点的个数
 * @return {*}
 */
void createHafumanCode(HafumanTree ht[],HafumanCode code[],int n){
    for(int i=0;i<n;i++){       //前n个为叶子节点，为每个叶子节点编码
        code[i].start=n;        //code中cd数组存储的01编码的最后位置
        int j=ht[i].parent;     //记录当前叶子节点的父节点
        int c=i;                //记录下当前节点，用于判断当前节点是左还是右节点
        while(j!=-1){           //走到根节点
            if(ht[j].left==c){  //如果父节点的左孩子是c编码为0
                code[i].cd[--code[i].start]='0';
            }
            else{               //右节点编码为1
                code[i].cd[--code[i].start]='1';
            }
            c=j;                //记录节点，用于下一步判断节点是左还是右节点
            j=ht[j].parent;     //从叶节点向上走，更新父节点
        }
    }
}
//code[i].start++;        //把start指向编码开始位置
int main()
{
    string str="The Chinese official said he viewed the Trump Presidency not as an aberration but as the product of a failing political system. This jibes with other accounts. The Chinese leadership believes that the United States,  and  Western  democracies in  general,  haven't  risen  to  the challenge of a globalized economy, which necessitates big changes in production patterns, as well as major upgrades in education and public infrastructure. In Trump and Trumpism, the Chinese see an inevitable backlash to this failure.";
    //string str="chinese";
    
    Map* mapList=nullptr;
    initMap(mapList);
    for(int i=str.size()-1;i>=0;i--){
        addMap(mapList,str[i]);
    }
    traveMap(mapList);//输出map数据

    HafumanTree* ht=new HafumanTree[2*(mapList->sum)];
    createTreeNode(ht,mapList);
    // for(int i=0;i<(mapList->sum);i++)
    //     cout<<ht[i].c<<" "<<ht[i].weight<<endl;
    createHafumanTree(ht,mapList->sum);
    cout<<endl;

    //输出哈夫曼树每个节点的权值和左右孩子
    for(int i=0;i<2*(mapList->sum)-1;i++)
    {
        cout<<i<<" weight:"<<ht[i].weight<<" parent:"<<ht[i].parent<<" left:"<<ht[i].left<<" right:"<<ht[i].right<<endl;
    }

    //构造哈夫曼编码
    HafumanCode* code=new HafumanCode[2*(mapList->sum)];
    for(int i=0;i<2*(mapList->sum);i++){
        //编码长度不会超过哈夫曼树的最大高度n-1
        code[i].cd=new char[mapList->sum];//编码长度
    }
    createHafumanCode(ht,code,mapList->sum);

    cout<<endl<<"code: "<<endl;
    //遍历每一个字符的哈夫曼编码
    for(int i=0;i<mapList->sum;i++){
        cout<<ht[i].c<<":";
        for(int j=code[i].start;j<mapList->sum;j++)//从编码的开始位输出
            cout<<code[i].cd[j];
        cout<<endl;
    }
    system("pause");
}