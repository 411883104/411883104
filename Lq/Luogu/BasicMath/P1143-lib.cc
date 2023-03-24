/*
 * @Author       : Outsider
 * @Date         : 2023-03-21 10:27:40
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-03-21 11:11:44
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\BasicMath\P1143-lib.cc
 */
#include <iostream>
using namespace std;
int n;
string s;
int m;
string count(int a, int n)
{
    string s;
    while (a)
    {
        int t = (a % n);
        if (t < 10)
            s.push_back((a % n) + '0');
        else
            s.push_back(t - 10 + 'A');
        a /= n;
    }
    return string(s.rbegin(), s.rend());
}
int main()
{
    cin >> n >> s >> m;
    int tol = stoi(s, 0, n);
    char ss[1024] = {0};
    itoa(tol, ss, m);
    string ans(ss);
    cout << ans << endl;
}