//单词接龙  https://www.lanqiao.cn/problems/769/learning/
#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n;
int ans = 0;
string word[N];  //存单词
int vis[N];      //记录每一个单词被使用了几次
bool check(string s,string m,int k){  //判断是否能拼接。用substr实现
    int len = s.size();
    if(s.size()<k || m.size()<k) return false;
    if(s.substr(len-k,k) == m.substr(0,k)) //s的后k个和m的前k个相同，能拼接
        return true;
    return false;
}
bool check1(string s,string m,int k){  //判断：简单实现
    int lens = s.length();
    for (int i=0;i<k;i++){
        if(s[lens-k+i]!=m[i])
            return false;
    }
    return true;
}
string add(string s,string m,int k){  //拼接：用substr实现
    int len = m.size();
    s = s + m.substr(k,len-k);   //拼接，把m接到s上。
    return s;
}
string add1(string s,string m,int k){ //拼接：简单实现
    int len = m.size();
    for (int i=k;i<len;i++)  s+=m[i];
    return s;
}
void dfs(string dragon){   //dragon：目前拼接好的龙串
    int len = dragon.size();
    ans = max(ans, len);
    for (int i=1;i<=n;i++){
        if (vis[i]>=2) continue;   //题目说每个单词最多用2次
        int k = word[i].size();
        for (int j=1;j<=k;j++)   //枚举拼接长度
            if (check(dragon,word[i],j)){
                string temp = dragon;
                temp = add(temp,word[i],j);
                vis[i]++;
                dfs(temp);
                vis[i]--;
            }
    }
}
int main(){
    cin >> n;
    for (int i=1;i<=n;i++) cin >> word[i];
    string first; cin >> first;
    dfs(first);       //用dfs搜索所有可能的拼接
    cout << ans << endl;
    return 0;
}
