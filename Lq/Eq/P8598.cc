/*
 * @Author: Outsider
 * @Date: 2023-02-22 18:05:25
 * @LastEditors: Outsider
 * @LastEditTime: 2023-02-23 10:37:41
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Eq\P8598.cc
 */
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore(n, '\n');
    vector<int> v;
    string s;
    while (n--)
    {
        getline(cin, s);
        stringstream ss(s);
        int it;
        while (ss >> it)
        {
            v.push_back(it);
        }
    }
    sort(v.begin(), v.end());
    int ans = -1, res = -1;
    for (size_t i = 1; i < v.size(); i++)
    {
        if (v[i] - v[i - 1] == 2)
        {
            ans = v[i] - 1;
        }
        else if (v[i] == v[i - 1])
        {
            res = v[i];
        }
    }
    cout << ans << " " << res << endl;
    return 0;
}