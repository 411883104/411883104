/*
 * @Author: Outsider
 * @Date: 2021-12-05 15:03:31
 * @LastEditors: Outsider
 * @LastEditTime: 2021-12-11 17:25:59
 * @Description: In User Settings Edit
 * @FilePath: \DataStructureTest\test3\ShortestPath.cpp
 */
#include<iostream>
using namespace std;


struct MatrixGraph{
    int** matrix;//邻接矩阵
    int n;  //顶点数
    int e;  //边数

    MatrixGraph(int n){
        this->n=n;
        this->e=0;
        matrix=new int*[n];
        for(int i=0;i<n;i++)
            matrix[i]=new int[n];
    }
};

/**
 * @description: 递归打印路径
 * @param {int} *pre 前驱数组
 * @param {int} n 终点
 * @return {*}
 */
void printPath(int *pre,int n){
    if(pre[n]==-1) //递归返回
        return;
    else{
        printPath(pre,pre[n]);
        cout<<pre[n]<<"->";
    }
}

/**
 * @description: Dijkstra算法求最短路径
 * @param {MatrixGraph} graph 邻接矩阵表示的图
 * @param {int} v 起点
 * @return {*}
 */
void Dijkstra(MatrixGraph graph,int v){
    int* dist=new int[graph.n]; //距离数组，dist[k]为起点到k的最小距离
    int* pre=new int[graph.n];  //前驱数组，pre[k]为k的前驱
    int* flag=new int[graph.n]; //标记数组，flag[k]表示起点到k的距离是否已是最短
    
    //初始化数组
    for(int i=0;i<graph.n;i++){
        dist[i]=graph.matrix[v][i];//初始化起点到其他各点的距离
        flag[i]=0;  
        if(dist[i]==0xfffffff)
            pre[i]=-1; //起点和起点到其他节点距离为无穷远的节点的前驱为-1
        else{
            pre[i]=v;  //开始时其他点前驱节点为起点
        }
    }
    dist[v]=0;  //起点到起点的距离为0
    flag[v]=1;  //节点到节点的距离已是最短

    for(int i=0;i<graph.n;i++){
        //寻找起点到每一个顶点的最短路径
        int minn=0xfffffff;
        int cur=v;
        for(int j=0;j<graph.n;j++){
            //在已经可达的节点中寻找距离起点最近的点
            if((minn>dist[j])&&flag[j]==0){
                cur=j;
                minn=dist[j];
            }    
        }

        flag[cur]=1;//cur到起点的距离已是最短
        for(int j=0;j<graph.n;j++){
            //更新距离矩阵
            if((dist[j]>(dist[cur]+graph.matrix[cur][j]))&&flag[j]==0){
                dist[j]=dist[cur]+graph.matrix[cur][j];
                pre[j]=cur; //表示cur到pre[j]的距离比原来更短，将pre[j]前驱改为cur
            }
        }
    }

    // //输出起点到各个节点的最短路径
    // cout<<"DijkstraDist:(dist,prenode)"<<endl;
    // for(int i=0;i<graph.n;i++){
    //     cout<<dist[i]<<" "<<pre[i]<<endl;
    // }

    //输出起点到终点的最短路径
    cout<<"DijkstraPath:"<<endl;
    for(int i=0;i<graph.n;i++){
        //v为起点，i为终点
        cout<<v<<"->"<<i<<" Dist:"<<dist[i]<<" Path: ";
        printPath(pre,i);
        cout<<i<<endl;
    }

}

/**
 * @description: Floyd算法求最短路径
 * @param {MatrixGraph} graph 邻接矩阵表示的图
 * @return {*}
 */
void Floyd(MatrixGraph graph){
    int** dist=new int*[graph.n];//dist[i][j]记录i到j的最短距离
    int** pre=new int*[graph.n];//pre[i][j]记录以i为起点j为终点的路径中j的前驱
    //动态分配二维数组
    for(int i=0;i<graph.n;i++){
        dist[i]=new int[graph.n];
        pre[i]=new int[graph.n];
    }

    for(int i=0;i<graph.n;i++)
    {
        for(int j=0;j<graph.n;j++){
            dist[i][j]=graph.matrix[i][j];//初始化i到j的距离
            pre[i][j]=i;                  //初始化j的前驱为i
            if(i==j){
                dist[i][j]=0;             //自己到自己的距离为0
                pre[i][j]=-1;             //起点前驱为-1
            }
        }
    }

    for(int k=0;k<graph.n;k++){
        for(int i=0;i<graph.n;i++){
            for(int j=0;j<graph.n;j++){
                //从i到j的路径中是否存在k使得经过k使路径变短
                if(dist[i][j]>(dist[i][k]+dist[k][j])){
                    dist[i][j]=dist[i][k]+dist[k][j];//更新路径
                    pre[i][j]=pre[k][j]; //i到j路径中j的前驱改为k到j路径中j的前驱
                }
            }
        }
    }

    // //输出Floyd算法距离矩阵
    // cout<<"FloydDist:"<<endl;
    // for(int i=0;i<graph.n;i++){
    //     for(int j=0;j<graph.n;j++){
    //         cout<<dist[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    //输出前驱矩阵
    // for(int i=0;i<graph.n;i++){
    //     for(int j=0;j<graph.n;j++){
    //         cout<<pre[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    //输出最短路径
    cout<<"FloydPath:"<<endl;
    for(int i=0;i<graph.n;i++){
        //pre[i][j]表示i为起点到j的最短距离为pre[i][j]
        //即pre[i]相当于Dijkstra中的pre数组
        for(int j=0;j<graph.n;j++){
            cout<<i<<"->"<<j<<" Dist:"<<dist[i][j]<<" Path: ";
            printPath(pre[i],j); //递归输出路径
            cout<<j<<endl;
        }
    }
}

//图的节点和边的数据
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

int main(){
    //邻接矩阵
    MatrixGraph graph(7);
    for(int i=0;i<graph.n;i++){
        for(int j=0;j<graph.n;j++)
            graph.matrix[i][j]=0xfffffff;
    }
    //通过graphinfo数组构造邻接矩阵
    int n,m,w;
    for(int i=0;i<9;i++){
        n=graphinfo[i][0];
        m=graphinfo[i][1];
        w=graphinfo[i][2];
        graph.matrix[n][m]=graph.matrix[m][n]=w;
        graph.e++;
    }
    //输出邻接矩阵
    // for(int i=0;i<graph.n;i++){
    //     for(int j=0;j<graph.n;j++)
    //         cout<<graph.matrix[i][j]<<" ";
    //     cout<<endl;
    // }

    Dijkstra(graph,3);//Dijkstra算法求节点3到其他节点的最短路径
    
    cout<<endl;

    Floyd(graph);     //Floyd算法求多源最短路径

    system("pause");
}