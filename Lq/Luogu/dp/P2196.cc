/*
 * @Author: Outsider
 * @Date: 2023-01-20 13:33:22
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-20 18:13:32
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\dp\P2196.cc
 */
#include <iostream>
#include <vector>

using namespace std;

int arr[100][100];
int num[100];
int j[100];
int n;

int maxx = 0;
vector<int> ans;
vector<int> tem;
void dfs(int c, int s)
{
    for (int i = c + 1; i <= n; i++)
    {
        if (arr[c][i] == 1 && j[i] == 0)
        {
            j[i] = 1;
            tem.push_back(i);
            dfs(i, s + num[i]);
            j[i] = 0;
            tem.pop_back();
        }
    }
    if (s > maxx)
    {
        maxx = s;
        ans = tem;
    }
}

int main()
{

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            cin >> arr[i][j];
            arr[j][i] = arr[i][j];
        }
    }

    int res = 0;
    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        tem.push_back(i);
        j[i] = 1;
        dfs(i, num[i]);
        if (maxx > res)
        {
            res = maxx;
            v = ans;
        }
        j[i] = 0;
        tem.pop_back();
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl
         << res << endl;
}