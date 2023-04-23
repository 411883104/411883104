//拼数 https://www.lanqiao.cn/problems/782/learning/

#include<bits/stdc++.h>
using namespace std;
string a[21];  //记录20个数，用字符形式
bool cmp (string a, string b){   //从大到小字典序排序
    return a + b > b + a;        //注意体会这个技巧
}
int main( ){
    int n;    cin >> n;
    for(int i = 0; i < n; i++)   cin >> a[i];
    sort(a, a + n, cmp);                       //从大到小字典序排序
    for(int i=0; i < n; i++)     cout << a[i];
	return 0;
}
