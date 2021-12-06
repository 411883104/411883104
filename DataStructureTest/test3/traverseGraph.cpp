/*
 * @Author: Outsider
 * @Date: 2021-12-02 19:29:05
 * @LastEditors: Outsider
 * @LastEditTime: 2021-12-06 14:47:27
 * @Description: In User Settings Edit
 * @FilePath: \DataStructureTest\test3\traverseGraph.cpp
 */
#include<iostream>
using namespace std;


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


int vis[7]={0,0,0,0,0,0,0};  //标记是否访问过该节点
/**
 * @description: 深度优先搜索遍历图
 * @param {AdjacecyListGraph} adjacecylistgraph 图的邻接表
 * @param {int} v 起始节点
 * @return {*}
 */
void dfs(AdjacecyListGraph adjacecylistgraph,int v){
    EdgeNode* p=adjacecylistgraph.AdjacecyList[v].edge;
    cout<<v<<" ";
    vis[v]=1;
    while(p){
        if(vis[p->v]==0){
            dfs(adjacecylistgraph,p->v);
        }
        p=p->next;
    }
}

//队列节点
struct Node{
    int v;      //节点数据
    Node* next; //指针域
};


struct Queue{   //队列
    Node* head; //头指针
    Node* tail; //尾指针
};

void init(Queue* &queue){      //初始化队列
    queue->head=queue->tail=new Node();
    queue->tail->next=nullptr;
}

void push(Queue* &queue,int v){ //入队
    Node* node=new Node();
    node->v=v;
    node->next=queue->tail->next;
    queue->tail->next=node;
    queue->tail=node;
}

int front(Queue* queue){         //获取队列的首元节点
    return queue->head->next->v; //返回顶点
}

void pop(Queue* &queue){       //出队
    if(queue->head->next==queue->tail)
        queue->tail=queue->head;
    else    
        queue->head->next=queue->head->next->next;
}

/**
 * @description: 广度优先搜索遍历图
 * @param {AdjacecyListGraph} adjacecylistgraph 图的邻接表
 * @param {int} v 遍历的起始节点
 * @return {*}
 */
void bfs(AdjacecyListGraph adjacecylistgraph,int v){
    for(int i=0;i<adjacecylistgraph.n;i++){
        vis[i]=0;                               //初始化标记数组
    }
    Queue* queue=new Queue();                 
    init(queue);                                //初始化队列
    EdgeNode* q=nullptr;
    q=adjacecylistgraph.AdjacecyList[v].edge;   //q指向第一个节点的相邻节点
    cout<<v<<" ";                   //输出第一个顶点
    push(queue,v);                  //第一个顶点入队
    vis[v]=1;                       //标记顶点
    while(queue->head!=queue->tail){//队列非空则取出顶点
        q=adjacecylistgraph.AdjacecyList[front(queue)].edge; //q指向队首元素顶点的相邻节点
        while(q){                   //遍历与队首元素相邻的所有节点
            if(vis[q->v]==0){
                cout<<q->v<<" ";
                push(queue,q->v);   //与队首元素相邻的节点入队
                vis[q->v]=1;        //入队后标记为已访问
            }
            q=q->next;
        }
        pop(queue);//队首元素出队
    }
}

int main()
{
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
    int m,w;
    //邻接表
    AdjacecyListGraph adjcecylistgraph;
    adjcecylistgraph.AdjacecyList=new VertexNode[7];
    adjcecylistgraph.n=7;
    adjcecylistgraph.e=0;
    for(int i=0;i<adjcecylistgraph.n;i++){
        adjcecylistgraph.AdjacecyList[i].edge=nullptr;
        adjcecylistgraph.AdjacecyList[i].data='0'+i;
    }
    //初始化邻接表
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
    //输出邻接表
    for(int i=0;i<adjcecylistgraph.n;i++){
        p=adjcecylistgraph.AdjacecyList[i].edge;
        cout<<adjcecylistgraph.AdjacecyList[i].data<<": ";
        while(p){
            cout<<p->v<<" ";
            p=p->next;
        }
        cout<<endl;
    }

    cout<<"dfs: ";
    dfs(adjcecylistgraph,0); //从0顶点开始深度优先搜索
    cout<<endl;

    cout<<"bfs: ";
    bfs(adjcecylistgraph,0);//从0顶点开始广度优先搜索
    cout<<endl;

    system("pause");
}