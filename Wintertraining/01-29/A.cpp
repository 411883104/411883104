#include<iostream>
using namespace std;
const int c=110;
char arr[c][c];
int main()
{
	int h,w;
	cin>>h>>w;
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<=w;j++)
		{
			cin>>arr[i][j];
		}
	}
	for(int i=0;i<=h+1;i++)
	{
		for(int j=0;j<=w+1;j++)
		{
				if(i==0||i==h+1)
				{
					cout<<"#";
				}
				else
				{
					if(j==0||j==w+1)
					{
						cout<<"#";
						continue;
					}
					else
					{
						cout<<arr[i][j];
					}
				}
		}
		cout<<endl;
	}
	return 0;
 } 
