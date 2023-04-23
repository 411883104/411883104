//笨小猴   https://www.lanqiao.cn/problems/527/learning/

#include<bits/stdc++.h>
using namespace std;
int letter[26] = {0};        //统计每个字母的个数，是一个hash表
int is_prime(int n){
    if(n<=1) return 0;
    for(int i=2;i<=sqrt(n);i++)
        if(n%i==0)  return 0;
    return 1;
}
int main(){
    int maxn=-1,minn=1000;
    string s; cin >> s;
    int len = s.length();
    for(int i=0;i<len;i++)  letter[s[i]-'a']++;
    for(int i=0;i<26;i++){
        if(letter[i]==0) continue;
        if(letter[i]>maxn)  maxn = letter[i];
        if(letter[i]<minn)  minn = letter[i];
    }
    if(len == maxn) minn=0;
    int ans = is_prime(maxn-minn);
    if(!ans) cout << "No Answer\n"  << 0 << "\n";
    else     cout << "Lucky Word\n" << maxn-minn << "\n";
    return 0;
}
