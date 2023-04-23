//编程作业 https://www.lanqiao.cn/problems/1433/learning/

#include<bits/stdc++.h>
using namespace std;
const int N=1e6+9;
char v[N];     // 读入字符串
int slen,plen,s[N],p[N],pre[29],Next[N];
bool check(int a,int b,int j) {
	if(a<0||b<0) return a==b;			//大写字母
	return a==b||(b==0&&a>j);			//小写字母
}
void inits(){  //转化母串s
    scanf("%s",v+1);
    slen = strlen(v+1);
	memset(pre,0,sizeof(pre));
	for(int i=1;i<=slen;i++)				//预处理s串
		if(v[i]>='A'&&v[i]<='Z')  s[i]=-v[i];  //大写字母记为负数
        else{
			if(pre[v[i]-'a'+1]>0) s[i]=i-pre[v[i]-'a'+1];
            else s[i]=0;
            pre[v[i]-'a'+1]=i;
        }
}
void initp(){                     //转化模式串P
	scanf("%s",v+1);  plen=strlen(v+1);
	memset(pre,0,sizeof(pre));
	for(int i=1;i<=plen;i++)				//预处理t串
		if(v[i]>='A'&&v[i]<='Z') p[i]=-v[i];
		else{
            if(pre[v[i]-'a'+1]>0)   p[i]= i-pre[v[i]-'a'+1];
            else p[i]=0;
            pre[v[i]-'a'+1]=i;
		}
}
void getNext(){    //Next[]模板
	Next[0]=Next[1]=0;
	for(int i=1;i<plen;i++) {
	    int j = Next[i];
		while(j&&!check(p[i+1],p[j+1],j))
            j=Next[j];
		if(check(p[i+1],p[j+1],j))
		    Next[i+1] = j+1;
		else  Next[i+1] = 0;
	}
}
void kmp() {      //kmp模板
	int ans=0;
	int j=0;
	for(int i=0;i<slen;i++) {
		while(j&&!check(s[i+1],p[j+1],j))
            j=Next[j];
		if(check(s[i+1],p[j+1],j))
            j++;
		if(j==plen)
            ans++,j=Next[j];  //找到一个匹配，继续找下一个
	}
	cout<<ans<<endl;
}
int main() {
	int Q; cin>>Q;
	while(Q--){ inits();  initp();  getNext();  kmp();}
	return 0;
}
