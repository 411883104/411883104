//小明的字符串  https://www.lanqiao.cn/problems/1203/learning/

#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int Next[N];
void getNext(string p){               //计算Next[1]~Next[plen]
    Next[0]=0; Next[1]=0;
    for(int i=1; i < p.size(); i++){  //把i的增加看成后缀的逐步扩展
        int j = Next[i];              //j的后移：j指向前缀阴影w的后一个字符
        while(j && p[i] != p[j])      //阴影的后一个字符不相同
            j = Next[j];              //更新j
        if(p[i]==p[j])   Next[i+1] = j+1;
        else             Next[i+1] = 0;
    }
}
int kmp(string s, string p) {         //在s中找p
    int ans=0;
    int slen=s.size(), plen=p.size();
    int j=0;
    for(int i=0; i<slen; i++) {     //匹配S和P的每个字符
        while(j && s[i]!=p[j])      //失配了。注意j==0是情况(1)
             j=Next[j];             //j滑动到Next[j]位置
        if(s[i]==p[j]) {            //当前位置的字符匹配，继续
            j++;
            ans=max(ans,j);         //去掉这一句，本代码就是最基本的KMP
        }
        if(j == plen) {             //j到了P的末尾，找到了一个匹配
            //这个匹配，在S中的起点是i+1-plen，末尾是i。如有需要可以打印：
            // printf("at location=%d, %s\n", i+1-plen,&s[i+1-plen]);
           return ans;
        }
    }
    return ans;  //返回p在s中出现的最长前缀
}
int main(){
    string s, t;
    cin >> s >> t;
    getNext(t);                       //预计算Next[]数组
    cout<<kmp(s, t);
    return 0;
}

