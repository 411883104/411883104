//矩形拼接 2022年第十三届省赛Java大学C组，Python大学A组、C组、研究生组
//http://oj.ecustacm.cn/problem.php?id=2065

//User: root [fzl]的代码

#include<bits/stdc++.h>
using namespace std;
int a[3][2];
int main(){
    int T;    cin >> T;
    while(T--)    {
        for(int i = 0; i < 3; i++)
            cin >> a[i][0] >> a[i][1];
        int ans = 8;
        for(int i = 0; i < 3; i++)               //第1个
            for(int j = 0; j < 3; j++)
                if(i != j)                       //第2个
                    for(int k = 0; k < 3; k++)
                        if(k != i && k != j)     //第3个
                            for(int ii = 0; ii <= 1; ii++){ //第1个有横竖两种摆法
                                for(int jj = 0; jj <= 1; jj++){ //第2个横竖摆
                                    for(int kk = 0; kk <= 1; kk++){ //第3个横竖摆
                                        if(a[i][ii] == a[j][jj] + a[k][kk]){
                                            ans = min(ans, 6);
                                            if(a[j][1-jj] == a[k][1-kk])
                                                ans = min(ans, 4);
                                        }
                                        if(a[i][ii] == a[j][jj] || a[j][jj] == a[k][kk])
                                            ans = min(ans, 6);
                                        if(a[i][ii] == a[j][jj] && a[j][jj] == a[k][kk])
                                            ans = min(ans, 4);
                                    }
                                }
                            }
        cout<<ans<<endl;
    }
    return 0;
}
