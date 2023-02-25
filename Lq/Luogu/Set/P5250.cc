/*
 * @Author: Outsider
 * @Date: 2023-02-17 21:43:24
 * @LastEditors: Outsider
 * @LastEditTime: 2023-02-17 22:32:39
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\Set\P5250.cc
 */
#include <iostream>
#include <set>
using namespace std;

set<int> s;
int main()
{
    int n;
    cin >> n;
    int x, y;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        if (x == 1)
        {
            if (!s.insert(y).second)
            {
                cout << "Already Exist" << endl;
            }
        }
        else if (x == 2)
        {
            if (s.empty())
            {
                cout << "Empty" << endl;
            }
            else if (s.erase(y) == 0)
            {
                auto prev = s.lower_bound(y);
                auto next = prev--;
                if (next == s.end())
                {
                    cout << *prev << endl;
                    s.erase(prev);
                }
                else if (next == s.begin())
                {
                    cout << *next << endl;
                    s.erase(next);
                }
                else if (y - *prev <= *next - y)
                {
                    cout << *prev << endl;
                    s.erase(prev);
                }
                else if (y - *prev > *next - y)
                {
                    cout << *next << endl;
                    s.erase(next);
                }
            }
            else
                cout << y << endl;
        }
    }
}