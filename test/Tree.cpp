#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

struct tree
{
	int val;
	tree*left,*right;
};

void creat(tree *&p,int x)
{
	if(p==NULL)
	{
		p=new tree;
		p->val=x;
		p->left=NULL;
		p->right=NULL;
		return ;
	}
	if(x<p->val)
	{
		creat(p->left,x);
	}
	else
	{
		creat(p->right,x);
	}
}
void show(tree*p)
{
	if(p!=NULL)
	{
		cout<<p->val<<endl;
		show(p->left);
		show(p->right);
	}
}
int main()
{
	int x;
	tree *first=NULL;
	while(cin>>x&&x)
	{
		creat(first,x);
	}
	show (first);
 } 
