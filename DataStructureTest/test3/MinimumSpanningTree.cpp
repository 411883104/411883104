/*
 * @Author: Outsider
 * @Date: 2021-12-03 15:28:50
 * @LastEditors: Outsider
 * @LastEditTime: 2021-12-12 14:12:17
 * @Description: In User Settings Edit
 * @FilePath: \DataStructureTest\test3\MinimumSpanningTree.cpp
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

struct MinSpanTreeNode{   //最小生成树存储方式
    int v1,v2;            //边的两个顶点
    int weight;           //两顶点间的边的权值
};

struct MinSpanTree{       //最小生成树
    MinSpanTreeNode* edge;//最小生成树的边，用数组存储
    int n;                //节点个数
    int e;                //最小生成树的边数
};

/**
 * @description: Prim构造最小生成树
 * @param {MatrixGraph} graph 图的邻接矩阵
 * @param {MinSpanTree} &minspantree_prim 最小生成树
 * @param {int} v  最开始往最小生成树添加的顶点
 * @return {*}
 */
void prim(MatrixGraph graph,MinSpanTree &minspantree_prim,int v){

    minspantree_prim.edge=new MinSpanTreeNode[graph.n];//n-1条边
    minspantree_prim.n=0;                              //起始顶点数为0

    //设U为生成树，G为图
    int* u=new int[graph.n]();          //U中的顶点
    int* lowcost=new int[graph.n];      //与U中顶点相连权值小的边
    int* closest=new int[graph.n];      //G中顶点与U相邻的点
    for(int i=0;i<graph.n;i++){         //初始化
        lowcost[i]=graph.matrix[v][i];  //从顶点0开始
        closest[i]=v;                   //初始化i最小权值边都是与v相连
    }

    u[v]=1;//v顶点加入U
    int k=v;//记录与v最相近的顶点
    for(int i=1;i<graph.n;i++){//找出n-1条边
        int minn=0xfffffff;
        for(int j=0;j<graph.n;j++){//找出最小的边
            if(lowcost[j]<minn&&u[j]==0){//找出小权值的边且节点不在U中
                minn=lowcost[j];
                k=j;  //循环外部需要使用到j
            }
        }

        //minn为当前最小权值的边
        /*
        minn被选出来后closest[k]为其与k相连的节点
        */
        minspantree_prim.edge[minspantree_prim.n].v1=closest[k];
        minspantree_prim.edge[minspantree_prim.n].v2=k;
        minspantree_prim.edge[minspantree_prim.n++].weight=minn;

        u[k]=1;
        
        for(int j=0;j<graph.n;j++){
            //新节点加入后更新权重
            if((lowcost[j]>graph.matrix[k][j])&&u[j]==0){
                //如果节点与新加入的节点k之间的边的权值更小，则
                lowcost[j]=graph.matrix[k][j];//更新权值
                closest[j]=k;  //将相近的点改为k
            }
        }
    }
}

//冒泡排序
/**
 * @description: 冒泡排序，对边的权值排序
 * @param {MinSpanTreeNode} kruskalEdge 存储最小生成树的边的数组
 * @param {int} num //排序数组的长度
 * @return {*}
 */
void sortEdge(MinSpanTreeNode kruskalEdge[],int num){
    int i=num-1;
    int flag=1;
    for(;i>0&&flag;i--){//没有交换则有序
        flag=0;//标记是否发生交换
        for(int j=0;j<i;j++){
            if(kruskalEdge[j].weight>kruskalEdge[j+1].weight){
                flag=1;
                //交换
                MinSpanTreeNode temp=kruskalEdge[j];
                kruskalEdge[j]=kruskalEdge[j+1];
                kruskalEdge[j+1]=temp;
            }
        }
    }
}

/**
 * @description: 并查集寻找节点根节点的函数
 * @param {int} x 要寻找的节点
 * @param {int} flagNode 并查集数组
 * @return {*} 节点的根节点
 */
int find(int x,int flagNode[]){
    if(x==flagNode[x]) //相等则是根节点
        return x;
    else{//不相等则寻找其根节点
        return flagNode[x]=find(flagNode[x],flagNode);//路径压缩，让每一个节点都直接对应其根节点
    }
}

/**
 * @description: kruskal算法构造最小生成树
 * @param {MinSpanTree} &minspantree_kruskal 最小生成树
 * @param {MinSpanTreeNode} kruskalEdge 存储最小生成树边的数组
 * @param {MatrixGraph} graph 图的邻接矩阵
 * @return {*}
 */
void kruskal(MinSpanTree &minspantree_kruskal,MinSpanTreeNode kruskalEdge[],MatrixGraph graph){
    minspantree_kruskal.edge=new MinSpanTreeNode[graph.n];
    minspantree_kruskal.e=0;
    minspantree_kruskal.n=graph.n;

    int* flagNode=new int[graph.n];
    //初始化并查集数组，每个节点的根节点为自己
    for(int i=0;i<graph.n;i++){
        flagNode[i]=i;
    }

    int k=0;//记录最小生成树的边数，为节点数-1
    for(int i=0;i<graph.e&&k<graph.n-1;i++){
        if(minspantree_kruskal.e<minspantree_kruskal.n-1){
            int dv1=find(kruskalEdge[i].v1,flagNode);
            int dv2=find(kruskalEdge[i].v2,flagNode);
            //判断两个节点间是否联通
            if(dv1!=dv2){
                //将节点和边加入最小生成树中
                minspantree_kruskal.edge[k].v1=dv1;
                minspantree_kruskal.edge[k].v2=dv2;
                minspantree_kruskal.edge[k++].weight=kruskalEdge[i].weight;
                flagNode[dv1]=dv2;//dv2加入连通块
                minspantree_kruskal.e++;
            }
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
    // cout<<"AdjcecyMatrix:"<<endl;
    // for(int i=0;i<graph.n;i++){
    //     for(int j=0;j<graph.n;j++)
    //         cout<<graph.matrix[i][j]<<" ";
    //     cout<<endl;
    // }

    MinSpanTree minspantree_prim;
    prim(graph,minspantree_prim,4);//从节点4开始构造最小生成树
    cout<<"prim_minspantree:(node,node,value)"<<endl;
    //按构造顺序输出最小生成树
    for(int i=0;i<graph.n-1;i++){
        cout<<minspantree_prim.edge[i].v1<<" "<<minspantree_prim.edge[i].v2<<" "<<minspantree_prim.edge[i].weight<<endl;
    }

    //kruskalEdge用于存储图两节点间边的权值
    //存储结构与最小生成树存储结构相同（节点，节点，边权值）
    MinSpanTreeNode* kruskalEdge=new MinSpanTreeNode[graph.e];
    int num=0;//记录边数
    for(int i=0;i<graph.n;i++){
        for(int j=0;j<graph.n;j++){
            //从邻接矩阵获取边权值和其的相邻节点
            if(j>i&&graph.matrix[i][j]!=0xfffffff){
                kruskalEdge[num].v1=i;
                kruskalEdge[num].v2=j;
                kruskalEdge[num++].weight=graph.matrix[i][j];
            }
        }
    }
    // for(int i=0;i<num;i++){
    //     cout<<kruskalEdge[i].weight<<endl;
    // }

    sortEdge(kruskalEdge,num);//边权值排序

    // for(int i=0;i<num;i++){
    //     cout<<kruskalEdge[i].weight<<endl;
    // }

    MinSpanTree minspantree_kruskal;
    //kruskal算法构造最小生成树
    kruskal(minspantree_kruskal,kruskalEdge,graph);
    cout<<endl<<"kruskal_minspantree:(node,node,value)"<<endl;
    //按构造顺序输出最小生成树
    for(int i=0;i<graph.n-1;i++){
        cout<<minspantree_kruskal.edge[i].v1<<" "<<minspantree_kruskal.edge[i].v2<<" "<<minspantree_kruskal.edge[i].weight<<endl;
    }

    system("pause");
}