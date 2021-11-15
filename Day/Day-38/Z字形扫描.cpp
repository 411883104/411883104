#include<iostream>
#include<algorithm>
using namespace std;
const int c=510;
int arr[c][c];
int dx[]= {0,1,1,-1};
int dy[]= {1,-1,0,1};
int main() {
	int n;
	cin>>n;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			scanf("%d",&arr[i][j]);
	int x=1,y=1;
	int d=0;
	for(int i=1; i<=n*n; i++) {
		printf("%d ",arr[x][y]);
		arr[x][y]=0;
		int x1=x+dx[d],y1=y+dy[d];
		if(x1>0&&y1>0&&x1<=n&&y1<=n&&arr[x1][y1]!=0)
			x=x1,y=y1;
		else {
			int vis=0;
			while(!(x1>0&&y1>0&&x1<=n&&y1<=n&&arr[x1][y1]!=0)) {
				if(vis==4)
				 	break;
				vis++;
				d++;
				d=d%4;
				x1=x+dx[d],y1=y+dy[d];
			}
			x=x1,y=y1;
		}
		if(d==0||d==2) {
			d++;
		}
	}
	return 0;
}
