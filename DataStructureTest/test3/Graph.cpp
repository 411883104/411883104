/*
 * @Author: Outsider
 * @Date: 2021-11-29 14:27:17
 * @LastEditors: Outsider
 * @LastEditTime: 2021-12-13 13:54:21
 * @Description: In User Settings Edit
 * @FilePath: \DataStructureTest\test3\Graph.cpp
 */

#include<iostream>

using namespace std;

//图的邻接矩阵存储方式
struct MatrixGraph{ 
    int** matrix;   //邻接矩阵
    int n;          //顶点数
    int e;          //边数

    //初始化图
    MatrixGraph(int n){
        this->n=n;
        //动态分配二维数组
        matrix=new int*[n];
        for(int i=0;i<n;i++)
            matrix[i]=new int[n];
        this->e=0;
    }
};

//图的邻接表存储方式
struct EdgeNode{   //邻接表边类型
    int v;         //与该边相邻的节点
    int weight;    //边的权值
    EdgeNode* next;//下一条边
};
struct VertexNode{ //邻接表顶点
    char data;     //顶点的数据类型
    EdgeNode* edge;//与该点相连的边
};
struct AdjacecyListGraph{    //图的邻接表
    VertexNode* AdjacecyList;//节点，数组存储
    int n;                   //节点数
    int e;                   //边数
};

int graphinfo[9][3]={
    0,1,28,
    0,5,10,
    1,2,16,
    1,6,14,
    2,3,12,
    6,3,18,
    3,4,22,
    6,4,24,
    4,5,25};

int main()
{
    //邻接矩阵
    MatrixGraph graph(7);
    for(int i=0;i<graph.n;i++){
        for(int j=0;j<graph.n;j++)
            graph.matrix[i][j]=0xffffffff;//初始化为最大值
    }
    int n,m,w;//节点，节点，边权值

    //通过输入图节点和边构造邻接矩阵
    /*
    0 1 28
    0 5 10
    1 2 16
    1 6 14
    2 3 12
    6 3 18
    3 4 22
    6 4 24
    4 5 25
    0 0 0
    */
    // while(cin>>n>>m>>w&&w!=0){     //输入邻接矩阵的节点和对应边
    //     graph.matrix[n][m]=graph.matrix[m][n]=w;
    // }
    
    //通过graphinfo数组构造邻接矩阵
    for(int i=0;i<9;i++){
        n=graphinfo[i][0];
        m=graphinfo[i][1];
        w=graphinfo[i][2];
        graph.matrix[n][m]=graph.matrix[m][n]=w;
    }
    cout<<"AdjcecyMatrix:"<<endl;
    //输出邻接矩阵
    for(int i=0;i<graph.n;i++){
        for(int j=0;j<graph.n;j++)
            cout<<graph.matrix[i][j]<<" ";
        cout<<endl;
    }

    //邻接表
    AdjacecyListGraph adjacecylistgraph;
    adjacecylistgraph.AdjacecyList=new VertexNode[7];//图的顶点
    adjacecylistgraph.n=7;                           //图顶点个数
    adjacecylistgraph.e=0;                           //边数
    for(int i=0;i<adjacecylistgraph.n;i++){          //初始化邻接表
        adjacecylistgraph.AdjacecyList[i].edge=nullptr;
        adjacecylistgraph.AdjacecyList[i].data='0'+i;//节点信息
    }

    //输入邻接表信息
    /*
    1 28
    5 10
    -1 -1
    2 16
    6 14
    0 28
    -1 -1
    3 12
    1 16
    -1 -1
    6 18
    4 22
    2 12
    -1 -1
    5 25
    3 22
    6 24
    -1 -1
    0 10
    4 25
    -1 -1
    1 14
    3 18
    4 24
    -1 -1
    */
    // for(int i=0;i<adjacecylistgraph.n;i++)
    //     while(cin>>m>>w&&w!=-1){                   //输入邻接表
    //         EdgeNode* n=new EdgeNode();
    //         n->v=m;
    //         n->weight=w;
    //         n->next=adjacecylistgraph.AdjacecyList[i].edge;
    //         adjacecylistgraph.AdjacecyList[i].edge=n;
    //         adjacecylistgraph.e++;
    //     }
    
    //通过graphinfo数组构造邻接表
    EdgeNode* node=nullptr;
    for(int i=0;i<9;i++){
        n=graphinfo[i][0];
        m=graphinfo[i][1];
        w=graphinfo[i][2];
        //输入以n为顶点的节点
        node=new EdgeNode();
        node->v=m;
        node->weight=w;
        //头插法插入节点
        node->next=adjacecylistgraph.AdjacecyList[n].edge;
        adjacecylistgraph.AdjacecyList[n].edge=node;
        //输入以m为顶点的节点
        node=new EdgeNode();
        node->v=n;
        node->weight=w;
        node->next=adjacecylistgraph.AdjacecyList[m].edge;
        adjacecylistgraph.AdjacecyList[m].edge=node;
        
        adjacecylistgraph.e++;//两个顶点间为一条边
    }
    EdgeNode* p;
    cout<<endl<<"AdjacecyList:"<<endl;
    //输出邻接表
    for(int i=0;i<adjacecylistgraph.n;i++){
        p=adjacecylistgraph.AdjacecyList[i].edge;//邻接表顶点对应的第一条边
        cout<<adjacecylistgraph.AdjacecyList[i].data<<": ";//邻接表的顶点
        while(p){
            cout<<p->v<<"("<<p->weight<<")"<<" "; //邻接表与顶点相邻的节点
            p=p->next;
        }
        cout<<endl;
    }

    system("pause");
}