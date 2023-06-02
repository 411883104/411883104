/*
 * @Author       : Outsider
 * @Date         : 2023-05-24 21:47:59
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-05-25 11:15:46
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Eq\P8655-tp.cc
 */
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int c = 1005;
int s[c];
int vis[c];
int n;

vector<int> G[c];

int main()
{
    cin >> n;
    int x, y;
    int src, dst;
    for (int i = 0; i < n; i++)
    {
        G[x].push_back(y);
        G[y].push_back(x);
        s[x]++;
        s[y]++;
    }

    return 0;
}