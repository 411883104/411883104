/*
 * @Author       : Outsider
 * @Date         : 2023-05-26 19:53:26
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-05-26 20:27:24
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\other\Test\mt\2.cc
 */
#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

int a[100005];
unordered_map<int, int> m;

int main()
{
    int n, t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (n == 1)
        {
            cout << "YES" << endl;
            continue;
        }
        int tol = 0;
        m.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            tol += a[i];
            m[a[i]]++;
        }
        int cnt = tol / (n >> 1);
        bool f = true;
        for (auto it = m.begin(); it != m.end();)
        {
            auto pre = m.find(cnt - (*it).first);

            if (pre == m.end() || (*it).second != (*pre).second)
            {
                f = false;
                break;
            }
            else if (it != pre)
            {
                m.erase(pre);
                it = m.erase(it);
            }
            else if (it == pre)
            {
                it = m.erase(it);
            }
        }
        if (f)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}