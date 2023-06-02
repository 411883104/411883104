/*
 * @Author       : Outsider
 * @Date         : 2023-05-09 19:54:34
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-05-09 20:26:36
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
        int a1 = count(s.begin() + a, s.end(), t[0]);
        int b1 = count(s.begin() + a + b, s.end(), t[1]) +
                 count(s.begin(), s.begin() + a, t[1]);
        int c1 = count(s.begin(), s.begin() + a + b, t[2]);

        res = min(a1 + b1 - c1, res);
    }
    cout << res << endl;
    return 0;
}