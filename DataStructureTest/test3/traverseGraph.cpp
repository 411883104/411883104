/*
 * @Author: Outsider
 * @Date: 2021-12-02 19:29:05
 * @LastEditors: Outsider
 * @LastEditTime: 2021-12-05 17:17:00
 * @Description: In User Settings Edit
 * @FilePath: \DataStructureTest\test3\traverseGraph.cpp
 */
#include<iostream>
using namespace std;


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

int vis[7]={0,0,0,0,0,0,0};
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
    int v;//节点数据
    Node* next;
};

//队列
struct Queue{
    Node* head;
    Node* tail;
};

void init(Queue* &queue){
    queue->head=queue->tail=new Node();
    queue->tail->next=nullptr;
}

void push(Queue* &queue,int v){
    Node* node=new Node();
    node->v=v;
    node->next=queue->tail->next;
    queue->tail->next=node;
    queue->tail=node;
}

int front(Queue* queue){
    return queue->head->next->v;
}

void pop(Queue* &queue){
    if(queue->head->next==queue->tail)
        queue->tail=queue->head;
    else    
        queue->head->next=queue->head->next->next;
}


void bfs(AdjacecyListGraph adjacecylistgraph){
    for(int i=0;i<adjacecylistgraph.n;i++){
        vis[i]=0;
    }
    Queue* queue=new Queue();
    init(queue);
    EdgeNode* q=nullptr;
    q=adjacecylistgraph.AdjacecyList[0].edge;
    vis[0]=1;
    cout<<0<<" ";
    push(queue,0);
    while(queue->head!=queue->tail){
        q=adjacecylistgraph.AdjacecyList[front(queue)].edge;
        while(q){
            if(vis[q->v]==0){
                cout<<q->v<<" ";
                push(queue,q->v);
                vis[q->v]=1;
            }
            q=q->next;
        }
        pop(queue);
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

    cout<<"dfs: ";
    dfs(adjcecylistgraph,0);

    cout<<endl;
    cout<<"bfs: ";
    bfs(adjcecylistgraph);

    system("pause");
}