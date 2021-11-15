#include<iostream>
#include<queue>
using namespace std;
const int c=210;
int vis[c][c];
int step[c];
char arr[c][c];
queue<int>q;
void bfs(int n,int k) {
	int now,next;
	q.push(n);
	step[n]=0;
	vis[n]=1;
	while(!q.empty()) {
		now=q.front();
		if(now==k) {
			cout<<step[now]<<endl;
			return;
		} else {
			arr[0]=-1;
			arr[1]=1;
			arr[2]=now;
			for(int i=0; i<3; i++) {
				next=now+arr[i];
				if(next==k) {
					while(!q.empty()) {
						q.pop();
					}
					step[next]=step[now]+1;
					q.push(now);
					q.push(next);
					break;
				} else {
					if(next>=0&&next<=100000&&!vis[next]) {
						step[next]=step[now]+1;
						vis[next]=1;
						q.push(next);
					}
				}
			}
		}
		q.pop();
	}
	return;
}
int main() {
	int t;
	cin>>t;
	while(t--) {
		int r,c;
		cin>>r>>c;
		int x,y;
		for(int i=1; i<=r; i++)
			for(int j=1; j<=c; j++) {
				vis[i][j]=1;
			}
		for(int i=1; i<=r; i++)
			for(int j=1; j<=c; j++) {
				cin>>arr[i][j];
				if(arr[i][j]=='S') {
					x=i;
					y=j;
				}
				if(arr[i][j]=='#') {
					vis[i][j]=0;
				}
			}
		while(!q.empty()) {
			q.pop();
		}
		bfs(x,y);
	}
}
return 0;
}
