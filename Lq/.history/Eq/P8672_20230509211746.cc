/*
 * @Author       : Outsider
 * @Date         : 2023-05-09 19:54:34
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-05-09 21:17:45
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Eq\P8672.cc
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string str;
    cin >> str;
    vector<string> v = {"BAT", "BTA", "ATB", "ABT", "TAB", "TBA"};

    int res = 0xfffffff;
    for (auto t : v)
    {
        string s = str;
        int a = count(s.begin(), s.end(), t[0]);
        int b = count(s.begin(), s.end(), t[1]);

        int ans = 0;

        int ll = 0, rr = s.size() - 1;
        while (ll < rr && ll < a && rr >= a)
        {
            while (s[ll] == t[0] && ll < a && ll < rr)
            {
                ll++;
            }
            while (s[rr] != t[0] && ll < rr && rr > a)
            {
                rr--;
            }
            if (ll >= a|| ll >= rr)
            {
                break;
            }
            s[rr] = s[ll];
            s[ll] = t[0];
            ans++;
        }
        ll = a, rr = s.size() - 1;
        while (ll < rr && ll < a + b && rr >= a + b)
        {
            while (s[ll] == t[1] && ll < a + b && ll < rr)
            {
                ll++;
            }
            while (s[rr] != t[1] && ll < rr && rr >= a + b)
            {
                rr--;
            }
            if (ll >= a + b || ll >= rr)
            {
                break;
            }
            s[rr] = s[ll];
            s[ll] = t[1];
            ans++;
        }

        res = min(ans, res);
    }
    cout << res << endl;
    return 0;
}