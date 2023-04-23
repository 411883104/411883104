//数的拆分    https://www.lanqiao.cn/problems/2090/learning/
//如果上面提交有错，到这里提交：http://oj.ecustacm.cn/problem.php?id=2029

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 4000;
int prime[N+1],visit[N+1];
 int cnt = 0;
int E_sieve()  {

    for(int i = 2; i <= N; i++){  //无优化的埃氏筛
        if(!visit[i]) prime[++cnt] = i;
        for(int j = i*i; j <= N; j += i)   visit[j] = 1;
    }
}
void solve(){
    ll a;   scanf("%lld",&a); //这里不能用cin读，太慢
    for(int i = 1; i <= cnt; i++){
        int c = 0;
        while(a % prime[i] == 0) a/=prime[i], c++;
        if(c==1){ cout << "no\n"; return; }
    }
    ll k = sqrt(a);
    if(k * k == a){ cout << "yes\n"; return;}//检查n是否为平方数
    k = pow(a, 1/3);
    if(k*k*k == a){ cout << "yes\n"; return;}//检查n是否为立方数
    cout << "no\n";
}
int main(){
    E_sieve(); //预计算素数
    int T;   cin >> T;
    while(T--)   solve();
}

/*  这个代码是对的：

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;

bool not_prime[4010];
int prime[4010], tot;
void init(int n)
{
    for(int i = 2; i <= n; i++)if(!not_prime[i])
    {
        prime[++tot] = i;
        for(int j = i + i; j <= n; j += i)
            not_prime[j] = 1;
    }
}
//判断平方数
inline bool square_number(ll x)
{
  ll y = sqrt(x);
  while(y * y <= x)//开平方存在精度误差，需要多判断几步
  {
    if(y * y == x)return true;
    y += 1;
  }
  return false;
}
//判断立方数
inline bool cubic_number(ll x)
{
  ll y = pow(x, 1.0 / 3);
  while(y * y * y <= x)//开立方存在精度误差，需要多判断几步
  {
    if(y * y * y == x)return true;
    y += 1;
  }
  return false;
}

int main()
{
  //预处理4000以内的素数
  init(4000);
  int T;
  cin >> T;
  while(T--)
  {
    ll a;
    cin >> a;
    //先特判平方数、立方数
    if(square_number(a) || cubic_number(a))
    {
      cout<<"yes"<<endl;
      continue;
    }
    bool flag = true;
    for(int i = 1; i <= tot; i++)if(a % prime[i] == 0)
    {
      int mi = 0;
      while(a % prime[i] == 0)a /= prime[i], mi++;
      //幂次必须大于1
      if(mi == 1){flag = false; break;}
    }
    //剩余的部分再次判断平方数和立方数
    if(flag && (square_number(a) || cubic_number(a)))
      cout<<"yes"<<endl;
    else
      cout<<"no"<<endl;
  }
    return 0;
}


*/




