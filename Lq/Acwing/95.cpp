#include<iostream>
#include<vector>
using namespace std;

vector<string>s;
bool count()
{
	for(int i=0; i<s.size(); i++) {
		for(int j=0; i<s[i].size(); j++) {
			if(s[i][j]=='0') {
				return false;
			}
		}
	}
	return true;
}
void set(int x,int y)
{
	if(x>0) {
		s[x-1][y]=='0'?s[x-1][y]='1':s[x-1][y]='0';
	}
	if(x<4) {
		s[x+1][y]=='0'?s[x+1][y]='1':s[x+1][y]='0';
	}
	if(y<4) {
		s[x][y+1]=='0'?s[x][y+1]='1':s[x][y+1]='0';
	}
	if(y>0) {
		s[x][y-1]=='0'?s[x][y-1]='1':s[x][y-1]='0';
	}
}
int minn=0xffff;
void dfs(int step)
{
	if(step>6) {
		return;
	}
	if(count()) {
		minn=min(minn,step);
		return;
	}
	for(int i=0; i<s.size(); i++) {
		for(int j=0; j<s[i].size(); j++) {
			s[i][j]=='1'?s[i][j]='0':s[i][j]='1';
			set(i,j);
			dfs(step+1);
			s[i][j]=='1'?s[i][j]='0':s[i][j]='1';
			set(i,j);
		}
	}

}

int main()
{
	int n;
	cin>>n;
	string str;
	while(n--) {
		for(int i=0; i<5; i++) {
			cin>>str;
			s.push_back(str);
		}

		dfs(0);
		if(minn=0xffff) {
			cout<<-1<<endl;
		} else {
			cout<<minn<<endl;
		}
		s.clear();
	}
}
