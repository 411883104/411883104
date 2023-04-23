//数位递增的数  https://www.lanqiao.cn/problems/145/learning/

#include<bits/stdc++.h>
using namespace std;
bool check(int t){
	char s[8];	sprintf(s, "%d", t);
	//如果一定要用C++的string，加上一句：string str = s;
	for(int i=1;i<strlen(s);i++)
		if(s[i-1]>s[i])    return false;
	return true;
}
int main(){
	int n; cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++)
		if(check(i))   ans++;
	cout<<ans;
	return 0;
}


