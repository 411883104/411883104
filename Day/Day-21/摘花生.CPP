//#include<iostream>
//#include<queue>
//using namespace std;
//const int c=110;
//int bean[c][c];
//int vis[c][c];
//int arr1[2]={0,1};
//int arr2[2]={1,0};
//int ary[2];
//struct p
//{
//	int x;
//	int y;
//};
//queue<p>q;
//int bfs(int a,int b)
//{
//	p now,next;
//	int sum=0;
//	int maxx=0;
//	now.x=1;
//	now.y=1;
//	q.push(now);
//	while(!q.empty())
//	{
//		p now=q.front();
//		if(now.x==a&&now.y==b)
//		{
//			maxx+=bean[now.x][now.y];
//			return maxx;
//		}
//		else
//		{
//			for(int i=0;i<2;i++)
//			{
//				next.x=now.x+arr1[i];
//				next.y=now.y+arr2[i];
//				if(next.x==a&&next.y==b&&next.x<=a&&next.y<=b)
//				{
//					maxx+=bean[next.x][next.y];
//					return maxx;
//				}
//				else
//				{
//					q.push(next);
//				}
//			}
//			
//		}
//		q.pop();
//	}
//}
//int main()
//{
//	int t;
//	cin>>t;
//	while(t--)
//	{
//		int r,c;
//		cin>>r>>c;
//		for(int i=1;i<=r;i++)
//		{
//			for(int j=1;j<=c;j++)
//			{
//				cin>>bean[i][j];
//				vis[i][j]=1;
//			}
//		}
//		while(!q.empty())
//		{
//			q.pop();
//		}
//		cout<<bfs(r,c)<<endl;
//	}
//} 

 
//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int c=110;
//int bean[c][c];
//int maxx[c][c];
//int main()
//{
//	int t;
//	cin>>t;
//	while(t--)
//	{
//		int r,c;
//		cin>>r>>c;
//		for(int i=1;i<=r;i++)
//		{
//			for(int j=1;j<=c;j++)
//			{
//				cin>>bean[i][j];
//			}
//		}
//		for(int i=1;i<=r;i++)
//		{
//			for(int j=1;j<=c;j++)
//			{	
//				//i,j状态可以由i-1,j和i,j-1得到
//				//i-1，j表示从左边来，i,j-1表示从上边来 
//				maxx[i][j]=max(maxx[i-1][j],maxx[i][j-1])+bean[i][j];
//			}
//		}
//		cout<<maxx[r][c]<<endl;
//	}
//	return 0;
//}

//空间优化
#include<iostream>
#include<algorithm>
using namespace std;
const int c=110;
int arr[c][c];
int maxx[c];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int r,c;
		cin>>r>>c;
		for(int i=1;i<=r;i++)
		{
			for(int j=1;j<=c;j++)
			{
				cin>>arr[i][j];
				maxx[j]=0;
			}
		}
		for(int i=1;i<=r;i++)
		{
			for(int j=1;j<=c;j++)
			{
				maxx[j]=max(maxx[j],maxx[j-1])+arr[i][j];
			}
		}
		cout<<maxx[c]<<endl;
	}
	return 0;
 } 
