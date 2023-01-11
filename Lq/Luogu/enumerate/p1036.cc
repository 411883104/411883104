/*
 * @Author: Outsider
 * @Date: 2023-01-01 16:44:29
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-02 09:26:59
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\p1036.cc
 */
#include <iostream>

using namespace std;

// const int c = 100000005;
// int vis[c] = {0};
// int prime[c];
// int cnt = 0;

// void isPrime()
// {
//     for (int i = 2; i < c; i++)
//     {
//         if (vis[i] == 0)
//         {
//             prime[cnt++] = i;
//         }
//         for (int j = 0; j < cnt && prime[j] * i < c; j++)
//         {
//             vis[prime[j] * i] = 1;
//         }
//     }
// }
bool isPrime(int num){
    for(int i=2;i*i<=num;i++){
        if(num%i==0){
            return false;
        }
    }
    return true;
}

int ans = 0;
int num[25];
int fg[25] = {0};
int n, k;
void dfs(int j, int sum,int start)
{
    if (j == k)
    {
        if (isPrime(sum))
        {
            ans++;
        }
        return;
    }
    for (int i = start; i < n; i++)
    {
        // if (fg[i] == 0)
        // {
        //     fg[i] = 1;
            dfs(j + 1, sum + num[i], i+1);
        //     fg[j] = 0;
        // }
    }
}

int main()
{
    // isPrime();
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    dfs(0, 0, 0);
    cout << ans << endl;
}
