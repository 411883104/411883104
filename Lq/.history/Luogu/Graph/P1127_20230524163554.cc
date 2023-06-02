/*
 * @Author       : Outsider
 * @Date         : 2023-05-24 16:28:52
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-05-24 16:33:58
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\Graph\P1127.cc
 */
#include <iostream>
#include <vector>

using namespace std;

vector<string> ss;
const int c = 1005;
vector<int> G[c];

int main()
{
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        ss.push_back(s);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                if (ss[i][ss[i].size() - 1] == ss[j][0])
                {
                    G[i].push_back(j);
                }
                if (ss[j][ss[j].size() - 1] == ss[i][0])
                {
                    G[j].push_back(i);
                }
            }
        }
    }
}