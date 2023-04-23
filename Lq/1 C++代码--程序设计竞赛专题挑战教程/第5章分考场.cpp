//分考场  2017年第八届决赛   https://www.lanqiao.cn/problems/109/learning/
#include<bits/stdc++.h>
using namespace std;
const int N = 110;
int a[N][N];    //关系表，a[i][j]=1: 第i、j人认识
int p[N][N];    //考场状态, p[j][k]=x: 第j个考场的第k个座位，坐第x人
int num = N;    //最优考场数量
int n,m;
void dfs(int x, int room) {          //试试把第x人安排到第1~第room考场
	if (room >= num)   return;       //剪枝，当前需要的考场数量已经大于最优解
	if (x > n) {                    //已经安排了n个人，结束
        num = min(num, room);        //更新最优解
        return;
    }
	int j, k;
	for (j = 1; j <= room; j++) {      //枚举考场，把x放进第j考场试试
		k = 1;                        //第k个座位
		while (p[j][k] && !a[x][p[j][k]]) //j考场k座位有人坐，且这人不认识x
            k++;                          //座位k++
		if (p[j][k] == 0){                //k座位没人坐
            p[j][k] = x;                  //第j考场的k座位，安排x坐
            dfs(x + 1, room);              //第x人安排好了，继续安排下一人
            p[j][k] = 0;                  //回溯，放开这个座位
		}
	}
	p[room+1][1] = x;             //1~room考场都不能坐，x只能坐第room+1个考场的第1个座位
	dfs(x + 1, room + 1);         //继续安排第x+1人，试试第1~第room+1考场
	p[room+1][1] = 0;             //回溯
}
int main() {
	cin>>n>>m;
	for (int i = 1; i <= m; i++) {
        int u,v;  cin >> u >>v;
		a[u][v] = a[v][u] = 1;     //用矩阵表示两人的关系
	}
	dfs(1, 1);   //第1个人，第1个考场
	cout << num;
	return 0;
}
