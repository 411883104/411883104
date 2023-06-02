/*
 * @Author       : Outsider
 * @Date         : 2023-05-03 21:21:35
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-05-15 20:01:44
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\Graph\P1983.cc
 */
#include <iostream>
#include <vector>
using namespace std;
int n, m;

vector<int> v[1005];
vector<int> G[1005];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x;
        for (int j = 0; j < x; j++)
        {
            cin >> y;
            v[i].push_back(y);
        }
    }
}