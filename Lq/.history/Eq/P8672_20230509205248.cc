/*
 * @Author       : Outsider
 * @Date         : 2023-05-09 19:54:34
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-05-09 20:43:24
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Eq\P8672.cc
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<string> v = {"BAT", "BTA", "ATB", "ABT", "TAB", "TBA"};

    int res = 0xffffffff;
    for (auto t : v)
    {
        int a = count(s.begin(), s.end(), t[0]);
        int b = count(s.begin(), s.end(), t[1]);
        int c = count(s.begin(), s.end(), t[2]);

        int ll = 0, rr = s.size() - 1;
        while (ll < rr && ll < a && rr > a)
        {
            while (s[ll] == t[0] && ll < a && ll < rr)
            {
                ll++;
            }
            while (s[rr] != t[0] && ll < rr && rr > a)
            {
                rr--;
            }
            s[rr] = s[ll];
            s[ll] = t[0];
        }

        int ab = count(s.begin(), s.begin() + a, t[1]);
        int ac = count(s.begin(), s.begin() + a, t[2]);

        int ba = count(s.begin() + a, s.begin() + a + b, t[0]);
        int bc = count(s.begin() + a, s.begin() + a + b, t[2]);

        int ca = count(s.begin() + a + b, s.end(), t[0]);
        int cb = count(s.begin() + a + b, s.end(), t[1]);

        res = min(ab + ac + bc, res);
    }
    cout << res << endl;
    return 0;
}