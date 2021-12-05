/*
 * @Author: Outsider
 * @Date: 2021-11-29 14:27:17
 * @LastEditors: Outsider
 * @LastEditTime: 2021-12-05 17:14:43
 * @Description: In User Settings Edit
 * @FilePath: \DataStructureTest\test3\Graph.cpp
 */

#include<iostream>

using namespace std;

struct MatrixGraph{
    int** matrix;//邻接矩阵
    int n;//顶点数
    int e;//边数

    MatrixGraph(int n){
        this->n=n;
        matrix=new int*[n];
        for(int i=0;i<n;i++)
            matrix[i]=new int[n];
        this->e=0;
    }
};

struct EdgeNode{//邻接表边类型
    int v;//节点
    int weight;
    EdgeNode* next;//下一条边
};
struct VertexNode{//邻接表顶点
    char data;
    EdgeNode* edge;
};
struct AdjacecyListGraph{
    VertexNode* AdjacecyList;
    int n;
    int e;
};



int main()
{

    //邻接矩阵
    MatrixGraph graph(7);
    for(int i=0;i<graph.n;i++){
        for(int j=0;j<graph.n;j++)
            graph.matrix[i][j]=0xffffffff;
    }
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
    int n,m,w;
    while(cin>>n>>m>>w&&w!=0){
        graph.matrix[n][m]=graph.matrix[m][n]=w;
    }
    for(int i=0;i<graph.n;i++){
        for(int j=0;j<graph.n;j++)
            cout<<graph.matrix[i][j]<<" ";
        cout<<endl;
    }

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

    //邻接表
    AdjacecyListGraph adjcecylistgraph;
    adjcecylistgraph.AdjacecyList=new VertexNode[7];
    adjcecylistgraph.n=7;
    adjcecylistgraph.e=0;
    for(int i=0;i<adjcecylistgraph.n;i++){
        adjcecylistgraph.AdjacecyList[i].edge=nullptr;
        adjcecylistgraph.AdjacecyList[i].data='0'+i;
    }
    for(int i=0;i<adjcecylistgraph.n;i++)
        while(cin>>m>>w&&w!=-1){
            EdgeNode* n=new EdgeNode();
            n->v=m;
            n->weight=w;
            n->next=adjcecylistgraph.AdjacecyList[i].edge;
            adjcecylistgraph.AdjacecyList[i].edge=n;
            adjcecylistgraph.e++;
        }
    EdgeNode* p;
    for(int i=0;i<adjcecylistgraph.n;i++){
        p=adjcecylistgraph.AdjacecyList[i].edge;
        cout<<adjcecylistgraph.AdjacecyList[i].data<<": ";
        while(p){
            cout<<p->v<<" ";
            p=p->next;
        }
        cout<<endl;
    }
    

    system("pause");
}