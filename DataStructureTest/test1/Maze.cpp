/*
 * @Author: Outsider
 * @Date: 2021-11-13 13:29:10
 * @LastEditors: Outsider
 * @LastEditTime: 2021-11-15 15:13:24
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
    Node *next;
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

void pop(Queue *&queue)
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
bool empty(Queue *queue)
{
    if (queue->head == queue->tail)
        return true;
    return false;
}

Queue *queue = new Queue();
void bfs(int x, int y,int end_x,int end_y)
{
    Node* first = new Node();
    first->x = x;
    first->y = y;
    flag[first->x][first->y]=1;

    Node* trck=new Node();
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

void track(Node**res)
{
    
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
        bfs(1, 1,3,3);
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << flag[i][j] << ' ';
        cout << endl;
    }
    system("pause");
}