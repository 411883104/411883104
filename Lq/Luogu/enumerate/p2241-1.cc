/*
 * @Author: Outsider
 * @Date: 2023-01-02 20:51:29
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-02 21:09:46
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\p2241-1.cc
 */
#include <iostream>

using namespace std;

long long n, m;
long long ans = 0,res=0;

int main()
{
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==j){
                ans+=(n-i)*(m-j);
            }else{
                res+=(n-i)*(m-j);
            }
        }
    }
    cout << ans << " " << res << endl;
}