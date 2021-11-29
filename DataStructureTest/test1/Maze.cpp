/*
 * @Author: Outsider
 * @Date: 2021-11-13 13:29:10
 * @LastEditors: Outsider
 * @LastEditTime: 2021-11-29 14:39:10
 * @Description: In User Settings Edit
 * @FilePath: \DataStructureTest\test1\Maze.cpp
 */

#include <iostream>
using namespace std;
const int c = 300;
char map[c][c]; //迷宫地图，1可行0不可行
int flag[c][c]; //标记是否遍历过

int n, m; //地图的大下

int dx[4] = {0, 1, 0, -1}; //表示x反向的位移
int dy[4] = {1, 0, -1, 0}; //表示y方向的位移

struct Node
{ //定义节点表示坐标
    int x;
    int y;
    Node *next;  //作为队列时节点指针域
};

Node* res[c][c];

struct Queue
{ //定义队列
    Node *head;
    Node *tail;
};

bool init(Queue* &queue)
{
    queue->head = queue->tail = new Node();
    queue->tail->next = nullptr;
}

void push(Queue *&queue, Node *&node)
{
    queue->tail->next = node;
    queue->tail = node;
}

Node* &front(Queue *queue)
{
    return queue->head->next;
}

void pop(Queue *&queue)//头节点出队列
{
    Node *d=nullptr;
    if (queue->head != queue->tail)
    {
        d = queue->head->next;
        queue->head->next = queue->head->next->next;
        if(d==queue->tail)
            queue->tail=queue->head;
        delete d;
    }
}

//判断队列是否为空
bool empty(Queue *queue)
{
    if (queue->head == queue->tail)
        return true;
    return false;
}

Queue *queue = new Queue();
/**
 * @description: 广度优先搜索
 * @param {int} x 起始点x坐标
 * @param {int} y 起始点y坐标
 * @param {int} end_x 终点x坐标
 * @param {int} end_y 终点y坐标
 * @return {*}
 */
void bfs(int x, int y,int end_x,int end_y)
{
    Node* first = new Node();//创建起始节点
    first->x = x;
    first->y = y;
    flag[first->x][first->y]=1;

    Node* trck=new Node();//记录路径节点
    trck->x=first->x;
    trck->y=first->y;
    res[first->x][first->y]=trck;

    push(queue, first);
    while (!empty(queue))
    {
        Node *now=front(queue);
        if((now->x==end_x)&&(now->y==end_y))
        {
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            Node *next = new Node();
            next->x = now->x + dx[i];
            next->y = now->y + dy[i];
            if (!flag[next->x][next->y] && (map[next->x][next->y]=='1') && next->x > 0 && next->y > 0 && next->x <= n && next->y <= n)
            {
                push(queue, next);
                flag[next->x][next->y] = 1;
                trck=new Node();
                trck->x=next->x;
                trck->y=next->y;
                res[next->x][next->y]=trck;
            }
            else
                delete next;
        }
        pop(queue);
        now=nullptr;
    }
}

void track()
{
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(res[i][j])
                cout<<res[i][j]->x<<" "<<res[i][j]->y<<endl;
        }
    }
}

int main()
{

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> map[i][j];
    }

    if (init(queue))
    {
        bfs(1, 1,4,4);
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << flag[i][j] << ' ';
        cout << endl;
    }
    track();
    system("pause");
}