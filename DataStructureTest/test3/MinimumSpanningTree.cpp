/*
 * @Author: Outsider
 * @Date: 2021-12-03 15:28:50
 * @LastEditors: Outsider
 * @LastEditTime: 2021-12-05 17:29:04
 * @Description: In User Settings Edit
 * @FilePath: \DataStructureTest\test3\MinimumSpanningTree.cpp
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

struct MinSpanTreeNode{
    int v1,v2;//边的两个顶点
    int weight; 
};

struct MinSpanTree{
    MinSpanTreeNode* edge;
    int n;//节点个数
    int e;
};


void prim(MatrixGraph graph,MinSpanTree &minspantree_prim,int v){

    minspantree_prim.edge=new MinSpanTreeNode[graph.n];//n-1条边
    minspantree_prim.n=0;

    //设U为生成树，G为图
    int* u=new int[graph.n]();//U中的顶点
    int* lowcost=new int[graph.n];//与U中顶点相连权值小的边
    int* closest=new int[graph.n];//G中顶点与U相邻的点
    for(int i=0;i<graph.n;i++){//初始化
        lowcost[i]=graph.matrix[v][i];//从顶点0开始
        closest[i]=v;
        
        // minspantree_prim.edge[i].v1=v;
        // minspantree_prim.edge[i].v2=i;
    }

    u[v]=1;//v顶点加入U
    int k=v;//记录与v最相近的顶点
    for(int i=1;i<graph.n;i++){//找出n-1条边
        int minn=0xfffffff;
        for(int j=0;j<graph.n;j++){//找出最小的边
            if(lowcost[j]<minn&&u[j]==0){//找出小权值的边且节点不在U中
                minn=lowcost[j];
                k=j;
            }
        }

        minspantree_prim.edge[minspantree_prim.n].v1=closest[k];
        minspantree_prim.edge[minspantree_prim.n].v2=k;
        minspantree_prim.edge[minspantree_prim.n++].weight=minn;

        u[k]=1;
        cout<<minn<<" ";
        for(int j=0;j<graph.n;j++){
            if(lowcost[j]>graph.matrix[k][j]){
                lowcost[j]=graph.matrix[k][j];//更新权重
                closest[j]=k;
                //minspantree_prim.edge[k].v2=j;
            }
        }
    }
    // for(int i=0;i<7;i++){
    //     cout<<closest[i]<<" "<<endl;
    // }
}

//冒泡排序
void sortEdge(MinSpanTreeNode kruskalEdge[],int num){
    int i=num-1;
    int flag=1;
    for(;i>0&&flag;i--){
        flag=0;
        for(int j=0;j<i;j++){
            if(kruskalEdge[j].weight>kruskalEdge[j+1].weight){
                flag=1;
                MinSpanTreeNode temp=kruskalEdge[j];
                kruskalEdge[j]=kruskalEdge[j+1];
                kruskalEdge[j+1]=temp;
            }
        }
    }
}

int find(int x,int flagNode[]){
    if(x==flagNode[x])
        return x;
    else{
        return flagNode[x]=find(flagNode[x],flagNode);
    }
}


void kruskal(MinSpanTree &minspantree_kruskal,MinSpanTreeNode kruskalEdge[],MatrixGraph graph){
    minspantree_kruskal.edge=new MinSpanTreeNode[graph.n];
    minspantree_kruskal.e=0;
    minspantree_kruskal.n=graph.n;

    int* flagNode=new int[graph.n];
    for(int i=0;i<graph.n;i++){
        flagNode[i]=i;
    }
    int k=0;
    for(int i=0;i<graph.e&&k<graph.n-1;i++){
        if(minspantree_kruskal.e<minspantree_kruskal.n-1){
            int dv1=find(kruskalEdge[i].v1,flagNode);
            int dv2=find(kruskalEdge[i].v2,flagNode);
            if(dv1!=dv2){
                minspantree_kruskal.edge[k].v1=dv1;
                minspantree_kruskal.edge[k].v2=dv2;
                minspantree_kruskal.edge[k++].weight=kruskalEdge[i].weight;
                flagNode[dv1]=dv2;
                minspantree_kruskal.e++;
            }
        }
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
        graph.e++;
    }
    for(int i=0;i<graph.n;i++){
        for(int j=0;j<graph.n;j++)
            cout<<graph.matrix[i][j]<<" ";
        cout<<endl;
    }

    MinSpanTree minspantree_prim;
    prim(graph,minspantree_prim,4);
    cout<<endl;
    for(int i=0;i<graph.n-1;i++){
        cout<<minspantree_prim.edge[i].v1<<" "<<minspantree_prim.edge[i].v2<<" "<<minspantree_prim.edge[i].weight<<endl;
    }

    MinSpanTreeNode* kruskalEdge=new MinSpanTreeNode[graph.e];
    int num=0;
    for(int i=0;i<graph.n;i++){
        for(int j=0;j<graph.n;j++){
            if(j>i&&graph.matrix[i][j]!=0xfffffff){
                kruskalEdge[num].v1=i;
                kruskalEdge[num].v2=j;
                kruskalEdge[num++].weight=graph.matrix[i][j];
            }
        }
    }
    for(int i=0;i<num;i++){
        cout<<kruskalEdge[i].weight<<endl;
    }
    sortEdge(kruskalEdge,num);
    for(int i=0;i<num;i++){
        cout<<kruskalEdge[i].weight<<endl;
    }

    MinSpanTree minspantree_kruskal;
    kruskal(minspantree_kruskal,kruskalEdge,graph);
    for(int i=0;i<graph.n-1;i++){
        cout<<minspantree_kruskal.edge[i].v1<<" "<<minspantree_kruskal.edge[i].v2<<" "<<minspantree_kruskal.edge[i].weight<<endl;
    }

    system("pause");
}