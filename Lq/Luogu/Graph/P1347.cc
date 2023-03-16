/*
 * @Author       : Outsider
 * @Date         : 2023-03-15 20:07:16
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-03-16 19:13:02
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\Graph\P1347.cc
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int c = 30;
vector<int> G[c];
int in[c];
int tol[c];
int check[30];
int q[c];
int ss = 0;

int main()
{
    int n, m;
    cin >> n >> m;
    string s;
    bool finish = false;
    for (int i = 1; i <= m; i++)
    {
        cin >> s;
        G[s[0] - 'A'].push_back(s[2] - 'A');
        in[s[2] - 'A']++;
        if (!check[s[0] - 'A'])
        {
            check[s[0] - 'A'] = true;
            ss++;
        }
        if (!check[s[2] - 'A'])
        {
            check[s[2] - 'A'] = true;
            ss++;
        }

        if (!finish)
        {
            int tt = 0, hh = 1;
            int ans = 0;
            for (int j = 0; j < n; j++)
            {
                tol[j] = in[j];
                if (check[j] && tol[j] == 0)
                {
                    q[++tt] = j;
                    ans++;
                }
            }
            bool more = false;
            if (ans > 1)
            {
                more = true;
            }
            while (hh <= tt)
            {
                auto n = q[hh++];
                ans = 0;
                for (int e : G[n])
                {
                    tol[e]--;
                    if (tol[e] == 0)
                    {
                        q[++tt] = e;
                        ans++;
                        if (ans > 1)
                        {
                            more = true;
                        }
                    }
                }
            }
            if (tt != ss)
            {
                cout << "Inconsistency found after " << i << " relations." << endl;
                finish = true;
            }
            else if (tt == n && !more)
            {
                cout << "Sorted sequence determined after " << i << " relations: ";
                for (int i = 1; i <= tt; i++)
                {
                    cout << char(q[i] + 'A');
                }
                cout <<"."<< endl;
                finish = true;
            }
        }
    }
    if (!finish)
    {
        cout << "Sorted sequence cannot be determined." << endl;
    }
}