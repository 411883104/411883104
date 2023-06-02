/*
 * @Author       : Outsider
 * @Date         : 2023-05-23 21:45:39
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-05-23 21:47:55
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\Math\P1100.cc
 */
#include <iostream>
using namespace std;

int main()
{
    uint32_t x;
    cin >> x;
    cout << ((x & 0xffff) << 16) | (x >> 16) << endl;
}