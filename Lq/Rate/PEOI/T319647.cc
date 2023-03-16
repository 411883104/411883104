/*
 * @Author       : Outsider
 * @Date         : 2023-03-11 13:42:23
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-03-11 14:39:42
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Rate\PEOI\T319647.cc
 */
#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    int t;
    string s;
    cin >> t;

    int x1, x2, y1, y2;
    while (t--)
    {
        stringstream ss;
        cin >> s;
        int i = 0;
        for (; i < s.size() && s[i] != ':'; i++)
            ;
        ss << s.substr(0, i);
        ss >> x1;
        ss.clear();
        ss.str("");
        ss << s.substr(i + 1, s.size() - i);
        ss >> x2;

        ss.clear();
        ss.str("");
        cin >> s;
        i = 0;
        for (; i < s.size() && s[i] != ':'; i++)
            ;
        ss << s.substr(0, i);
        ss >> y1;

        ss.clear();
        ss.str("");
        ss << s.substr(i + 1, s.size() - i);
        ss >> y2;

        if ((x1 < 12 && y1 < x1) || (x1 < 12 && y1 == 12) ||
            (x1 == 12 && y1 == 12 && y2 < x2))
        {
            cout << "Yes" << endl;
        }
        else if ((x1 == y1 && x2 == y2) || x1 == 12)
        {
            cout << "No" << endl;
        }
        else if ((x1 < 12 && y1 <= x1 && y2 < x2) || (x1 < 12 && y1 < x1))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}