/*
 * @Author: Outsider
 * @Date: 2021-12-05 15:03:31
 * @LastEditors: Outsider
 * @LastEditTime: 2021-12-05 18:49:44
 * @Description: In User Settings Edit
 * @FilePath: \DataStructureTest\test3\ShortestPath.cpp
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
    }
};


void Dijkstra(MatrixGraph graph,int v){
    int* dist=new int[graph.n];
    int* pre=new int[graph.n];
    int* flag=new int[graph.n];
    
    for(int i=0;i<graph.n;i++){
        dist[i]=graph.matrix[v][i];
        flag[i]=0;
        if(dist[i]==0xfffffff)
            pre[i]=-1;
        else{
            pre[i]=v;
        }
    }
    dist[v]=0;
    flag[v]=1;

    for(int i=0;i<graph.n;i++){
        int minn=0xfffffff;
        int cur=v;
        for(int j=0;j<graph.n;j++){
            if((minn>dist[j])&&flag[j]==0){
                cur=j;
                minn=dist[j];
            }    
        }

        flag[cur]=1;
        for(int j=0;j<graph.n;j++){
            if((dist[j]>(dist[cur]+graph.matrix[cur][j]))&&flag[j]==0){
                dist[j]=dist[cur]+graph.matrix[cur][j];
                pre[j]=cur;
            }
        }

    }
    for(int i=0;i<graph.n;i++){
        cout<<dist[i]<<" "<<pre[i]<<endl;
    }
}

void Floyd(MatrixGraph graph,int v){
    int** dist=new int*[graph.n];//记录距离
    int** pre=new int*[graph.n];//记录前驱
    for(int i=0;i<graph.n;i++){
        dist[i]=new int[graph.n];
        pre[i]=new int[graph.n];
    }

    for(int i=0;i<graph.n;i++)
    {
        for(int j=0;j<graph.n;j++){
            dist[i][j]=graph.matrix[i][j];
            pre[i][j]=i;
            if(i==j){
                dist[i][j]=0;
                pre[i][j]=-1;
            }
        }
    }

    for(int k=0;k<graph.n;k++){
        for(int i=0;i<graph.n;i++){
            for(int j=0;j<graph.n;j++){
                if(dist[i][j]>(dist[i][k]+dist[k][j])){
                    dist[i][j]=dist[i][k]+dist[k][j];
                    pre[i][j]=pre[k][j];
                }
            }
        }
    }
    for(int i=0;i<graph.n;i++){
        for(int j=0;j<graph.n;j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<graph.n;i++){
        for(int j=0;j<graph.n;j++){
            cout<<pre[i][j]<<" ";
        }
        cout<<endl;
    }

}



int main(){
    //邻接矩阵
    MatrixGraph graph(7);
    for(int i=0;i<graph.n;i++){
        for(int j=0;j<graph.n;j++)
            graph.matrix[i][j]=0xfffffff;
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

    Dijkstra(graph,5);
    Floyd(graph,1);

    system("pause");
}