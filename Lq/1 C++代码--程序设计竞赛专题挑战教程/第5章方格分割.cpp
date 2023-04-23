//方格分割  2017年第八届省赛C/C++A组 https://www.lanqiao.cn/problems/644/learning

#include<bits/stdc++.h>
using namespace std;
int dx[] = {0, -1, 1,  0, 0};     //上下左右4个方向
int dy[] = {0,  0, 0, -1, 1};
bool vis[10][10];             //标记点是否被访问过
int cnt = 0;
void dfs(int x, int y){
	if(x == 0 || y == 0 || x == 6 || y == 6){cnt++; return;}
	for(int i = 1 ; i <= 4 ; i++){   //上下左右四个方向
		x += dx[i]; y += dy[i];        //走一步
		if(!vis[x][y]){              // 若该点未访问则继续深搜
			vis[x][y] = true;        //  当前的点标注为已访问
			vis[6 - x][6 - y] = true;
			dfs(x, y);         // 继续深搜
			vis[6 - x][6 - y] = false;
			vis[x][y] = false;
		}
		x -= dx[i]; y -= dy[i];
	}
}
int main(){
	vis[3][3] = true;
	dfs(3, 3);
	cout << cnt / 4 << endl;
	return 0;
}
