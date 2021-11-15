#include<iostream>
#include<queue>
using namespace std;
const int c=100010;
int vis[c];
int step[c];
int arr[3];
queue<int>q;
void bfs(int n,int k)
{
	int now,next;
	q.push(n);
	step[n]=0;
	vis[n]=1;
	while(!q.empty())
	{
		now=q.front();
		if(now==k)
		{
			cout<<step[now]<<endl;
			return;
		}
		else
		{
			arr[0]=-1;
			arr[1]=1;
			arr[2]=now;
			for(int i=0;i<3;i++)
			{
				next=now+arr[i];
				if(next==k)
				{
					while(!q.empty())
					{
						q.pop();
					}
					step[next]=step[now]+1;
					q.push(now);
					q.push(next);
					break;
				}
				else
				{
					if(next>=0&&next<=100000&&!vis[next])
					{
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
int main()
{
	int n,k;
	while(cin>>n>>k)
	{
		if(n>=k)
		{
			cout<<n-k<<endl;
		}
		else
		{
			for(int i=0;i<c;i++)
			{
				vis[i]=0;
				step[i]=0;
			}
			while(!q.empty())
			{
				q.pop();
			}
			bfs(n,k);
		}
	}
	return 0; 
} 
