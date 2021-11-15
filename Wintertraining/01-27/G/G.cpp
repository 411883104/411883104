#include<iostream>
using namespace std;
const int c=2e6;
int arr1[c];
int arr2[c];
struct list
{
	int a;
	list*next;
};
int main()
{
	int n;
	cin>>n;
//	list*head=NULL;
//	for(int i=0;i<n;i++)
//	{
//		cin>>arr[i];
//	}
//	list*s,*p;
//	for(int i=0;i<n;i++)
//	{
//		
//		s=new list;
//		cin>>s->a;
//		if(head==NULL)
//		{
//			head=s;
//		}
//		else
//		{
//			p->next=s;
//		}
//		p=s;
//	}
//	p->next=head;
//	while(head->a)
//	{
//		cout<<head->a<<endl;
//		head=head->next;	
//	}
	for(int i=0;i<n;i++)
	{
		cin>>arr1[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>arr2[i];
	}
	for(int i=1;i<n;i++)
	{
		int left=0,right=left+i;
		for(int j=left;j<n;j++)
		{
			
		}
	}
