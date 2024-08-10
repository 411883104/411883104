/*
 * @Author       : Outsider
 * @Date         : 2023-06-04 17:26:24
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-06-04 17:41:23
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Eq\P8700.cc
 */
#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        bool vis = false;
        string s1;
        string s2;
        string s3;
        cin >> s1 >> s2 >> s3;
        for (int i = 0; i < 4; i++)
        {
            map<char, int> m;
            m[s3[i]]++;
            m[s2[i]]++;
            m[s2[i + 4]]++;
            m[s1[i]]++;
            m[s1[i + 4]]++;
            m[s1[i + 8]]++;
            if (m['Y'] != 1 || m['R'] != 2 || m['G'] != 3)
            {
                vis = true;
                break;
            }
        }
        if (!vis)
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