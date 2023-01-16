/*
 * @Author: Outsider
 * @Date: 2023-01-16 10:00:14
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-16 12:57:26
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\Recursion\P1928.cc
 */
#include <iostream>
#include <stack>

using namespace std;
string str;
string ans;
void dfs(int &i, string &s)
{

    for (; i < str.size(); i++)
    {
        if (str[i] == ']')
        {
            return;
        }
        else if (str[i] == '[')
        {
            string ts;
            int cnt = 0;
            if (i + 2 < str.size() && str[i + 2] <= '9' && str[i + 2] >= '0')
            {
                cnt = stoi(str.substr(i + 1, 2));
                i += 3;
            }
            else
            {
                cnt = stoi(str.substr(++i, 1));
                i++;
            }
            dfs(i, ts);
            for (int j = 0; j < cnt; j++)
            {
                s.append(ts);
            }
        }
        // else if (str[i] <= '9' && str[i] >= '0')
        // {
        //     string ts;
        //     int cnt = 0;
        //     if (i + 1 < str.size() && str[i + 1] <= '9' && str[i + 1] >= '0')
        //     {
        //         cnt = stoi(str.substr(i, 2));
        //         i += 2;
        //     }
        //     else
        //     {
        //         cnt = stoi(str.substr(i, 1));
        //         i++;
        //     }
        //     dfs(i, ts);
        //     for (int j = 0; j < cnt; j++)
        //     {
        //         s.append(ts);
        //     }
        // }
        else
            s.push_back(str[i]);
    }
}

int main()
{
    cin >> str;
    int a = 0;
    dfs(a, ans);
    cout << ans << endl;
}