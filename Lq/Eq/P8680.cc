/*
 * @Author       : Outsider
 * @Date         : 2023-03-27 14:57:55
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-03-27 15:03:33
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Eq\P8680.cc
 */
#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        stringstream ss;
        ss << i;
        ss >> s;
        for (size_t j = 0; j < s.size(); j++)
        {
            if (s[j] == '0' || s[j] == '2' || s[j] == '1' || s[j] == '9')
            {
                ans += i;
                break;
            }
        }
    }
    cout << ans << endl;
}