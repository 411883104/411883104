//FBI 树https://www.lanqiao.cn/problems/571/learning/

#include <bits/stdc++.h>
using namespace std;
char s[1100],tree[4400];             //tree[]存满二叉树
int ls(int p){ return p<<1;  }       //定位左儿子：p*2
int rs(int p){ return p<<1|1;}       //定位右儿子：p*2 + 1
void build_FBI(int p,int left,int right){
	if(left==right){           //到达叶子结点
        if(s[right]=='1')  tree[p]='I';
        else               tree[p]='B';
        return;
	}
	int mid=(left+right)/2;         //分成两半
	build_FBI(ls(p),left,mid);      //递归左半
	build_FBI(rs(p),mid+1,right);   //递归右半

	if(tree[ls(p)]=='B' && tree[rs(p)]=='B')    //左右儿子都是B，自己也是B
        tree[p]='B';
	else if(tree[ls(p)]=='I'&&tree[rs(p)]=='I') //左右儿子都是I，自己也是I
        tree[p]='I';
	else tree[p]='F';
}
void postorder (int p){   //后序遍历
	if(tree[ls(p)])	 postorder (ls(p));
	if(tree[rs(p)])	 postorder (rs(p));
	printf("%c",tree[p]);
}
int main(){
	int n;	scanf("%d",&n);
	scanf("%s",s+1);
	build_FBI(1,1,strlen(s+1));
	postorder(1);
}
