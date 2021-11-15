#include<iostream>
#include<algorithm>
using namespace std;
int arr[3][3];
int a[12];
int w[5];
int s[10];
int main()
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cin>>arr[i][j];
		}
	}
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int sum=0;
	for(int i=0,j=0;j<3&&i<3;i++,j++)
	{
		int b=i;
		for(int k=0;k<n;k++)
		{
			if(arr[i][j]==a[k])
			{
				w[i]=b;
				sum++;
			}
		}
	}
	for(int k=0;k<n;k++)
	{
		int ans=1;
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				ans++;
				if(arr[i][j]=a[k])
				{
					s[ans]=ans;
				}
			 } 
		}
	}
	if(sum==3)
	{
		cout<<"Yes"<<endl;
		return 0;
	}
	else
	{
		if(sum==0)
		{
			cout<<"No"<<endl;
			return 0;
		}
		if(sum==1)
		{
			for(int i=0;i<3;i++)
			{
				if(w[i]!=0)
				{
					if(w[i]==0)
					{
						for(int i=0;i<10;i++)
						{
							if(s[i]==2)
							{
								for(int j=0;j<10;j++)
								{
									if(s[j]==3)
									{
										cout<<"Yes"<<endl;
										return 0; 
									}
								}
							}
							if(s[i]==4)
							{
								for(int j=0;j<10;j++)
								{
									if(s[j]==7)
									{
										cout<<"Yes"<<endl; 
										return 0;
									}
								}
							}
						}
					}
					if(w[i]=1)
					{
						for(int i=0;i<10;i++)
						{
							if(s[i]==2)
							{
								for(int j=0;j<10;j++)
								{
									if(s[j]==8)
									{
										cout<<"Yes"<<endl; 
										return 0;
									}
								}
							}
							if(s[i]==4)
							{
								for(int j=0;j<10;j++)
								{
									if(s[j]==6)
									{
										cout<<"Yes"<<endl; 
										return 0;
									}
								}
							}
						}
					}
					if(w[i]==2)
					{
						for(int i=0;i<10;i++)
						{
							if(s[i]==3)
							{
								for(int j=0;j<10;j++)
								{
									if(s[j]==6)
									{
										cout<<"Yes"<<endl; 
										return 0;
									}
								}
							}
							if(s[i]==7)
							{
								for(int j=0;j<10;j++)
								{
									if(s[j]==8)
									{
										cout<<"Yes"<<endl; 
										return 0;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
