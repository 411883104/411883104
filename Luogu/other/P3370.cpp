/*
 * @Author: Outsider
 * @Date: 2022-03-10 19:07:23
 * @LastEditors: Outsider
 * @LastEditTime: 2022-03-10 19:18:39
 * @Description: In User Settings Edit
 * @FilePath: \C++\Luogu\P3370.cpp
 */


#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;

const int base=13;
ll mod=1<<30;
const int c=100005;

ll ha(string s){
    ll ans=0,len=s.length();

    for(int i=0;i<len;i++){
        ans=(base*ans+ll(s[i]))%mod;
    }
    return ans;
}

ll h[c]={0};

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        h[i]=ha(s);
    }

    sort(h,h+n);
    ll ans=1;
    for(int i=0;i<n-1;i++){
        if(h[i]!=h[i+1]){
            ans++;
        }
    }
    cout<<ans<<endl;

    system("pause");
}