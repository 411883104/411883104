/*
 * @Author       : Outsider
 * @Date         : 2023-05-09 19:54:34
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-05-09 21:52:04
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

        int abc = count(s.begin() + a, s.end(), t[0]);
        int ab = count(s.begin(), s.begin() + a, t[1]);
        int ac = count(s.begin(), s.begin() + a, t[2]);
        int ba = count(s.begin() + a, s.begin() + a + b, t[0]);
        int bc = count(s.begin() + a, s.begin() + a + b, t[2]);

        res = min(ab + ac + bc + ba - min(ab, ba), res);
    }
    cout << res << endl;
    return 0;
}