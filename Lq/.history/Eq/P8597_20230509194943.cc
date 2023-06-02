/*
 * @Author       : Outsider
 * @Date         : 2023-05-09 19:42:52
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-05-09 19:49:43
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Eq\P8597.cc
 */
#include <iostream>

using namespace std;

int main()
{
    std::string s, r;
    std::cin >> s >> r;
    int cnt = 0;
    for (size_t i = 0; i < s.size() - 1; i++)
    {
        if (s[i] != r[i])
        {
            s[i] = r[i];
            s[i + 1] == '*' ? s[i + 1] = 'o' : s[i + 1] = '*';
            cnt++;
        }
    }
    std::cout << cnt << std::endl;
    return 0;
}