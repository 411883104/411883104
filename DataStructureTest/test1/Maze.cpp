/*
 * @Author: Outsider
 * @Date: 2021-11-13 13:29:10
 * @LastEditors: Outsider
 * @LastEditTime: 2021-12-11 17:57:19
 * @Description: In User Settings Edit
 * @FilePath: \DataStructureTest\test1\Maze.cpp
 */

#include <iostream>
using namespace std;
const int c = 9;
//迷宫地图8*8，1可行0不可行
//行和列从1开始
char map[c][c]={'1','1','1','1','1','1','1','1','1',
                '1','1','1','1','1','0','0','0','1',
                '1','0','1','0','1','0','0','1','1',
                '1','0','1','0','1','1','1','1','0',
                '1','1','1','1','1','1','0','0','0',
                '1','1','0','0','1','0','1','1','1',
                '1','1','1','0','0','1','1','0','1',
                '1','0','1','1','1','1','0','1','1',
                '1','0','0','0','1','0','0','0','1',
                };
int flag[c][c]; //标记是否遍历过

int dx[4] = {0, 1, 0, -1}; //表示x方向的位移
int dy[4] = {1, 0, -1, 0}; //表示y方向的位移

struct Node
{ //定义节点表示坐标
    int x;
    int y;
    Node* pre;  //记录该节点的上一个节点
    Node *next;  //作为队列时节点指针域
};


struct Queue
{ //定义队列
    Node *head;
    Node *tail;
};

bool init(Queue* &queue)//初始化队列
{
    queue->head = queue->tail = new Node();
    queue->tail->next = nullptr;
    if(queue->head)
        return true;
    return false;
}

void push(Queue *&queue, Node *&node)//入队
{
    queue->tail->next = node;
    queue->tail = node;
}

Node* &front(Queue *queue)//获取队首元素
{
    return queue->head->next;
}

void pop(Queue *&queue)//头节点出队列
{
    if (queue->head != queue->tail)
    {
        if(queue->head->next==queue->tail)
            queue->tail=queue->head;
        queue->head->next = queue->head->next->next;
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
Node *now=new Node();
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
    now->x=x;
    now->y=y;
    now->pre=nullptr;

    push(queue,now);//第一个节点入队

    while (!empty(queue))
    {
        now=front(queue);//取出队首元素分析
        pop(queue);      //队首元素出队
        if((now->x==end_x)&&(now->y==end_y))
        {
            return;//到达终点返回
        }
        for (int i = 0; i < 4; i++)
        {
            //遍历上下左右四个方向
            int ax = now->x + dx[i];
            int ay = now->y + dy[i];
            //判断下一个点是否符合条件
            if (!flag[ax][ay] && (map[ax][ay]=='1') && ax > 0 && ay > 0 && ax <= 8 && ay <= 8)
            {
                Node *next = new Node();
                flag[ax][ay] = 1;   //标记为已遍历
                next->x=ax;
                next->y=ay;
                push(queue, next);  //满足条件入队
                next->pre=now;      //标记前驱节点
            }
        }
    }
}

/**
 * @description: 递归输出路径
 */
void printPath(Node* now){
    if(!now)
        return;
    else{
        printPath(now->pre);
        cout<<now->x<<" "<<now->y<<endl;
    }
}

int main()
{
    cout<<"map:"<<endl;
    for (int i = 1; i <= 8; i++)
    {
        for (int j = 1; j <= 8; j++)
           cout<< map[i][j]<<" ";
        cout<<endl;
    }
    if (init(queue))
    {
        bfs(1, 1,8,8);//寻找(1,1)到(8,8)的最短路径
    }
    
    //输出标记数组
    // for (int i = 1; i <= 8; i++)
    // {
    //     for (int j = 1; j <= 8; j++)
    //         cout << flag[i][j] << ' ';
    //     cout << endl;
    // }
    
    if(now->x!=8&&now->y!=8){//没有到达终点
        cout<<"Not Found!"<<endl;
    }
    else{
        cout<<"Path:"<<endl;
        printPath(now);
    }
    system("pause");
}