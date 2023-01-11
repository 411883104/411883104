/*
 * @Author: Outsider
 * @Date: 2023-01-02 12:17:07
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-02 12:26:37
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\p1618.cc
 */
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int num[10];
    for (int i = 1; i <= 9; i++)
    {
        num[i] = i;
    }
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    do
    {
        int x = num[1] * 100 + num[2] * 10 + num[3];
        int y = num[4] * 100 + num[5] * 10 + num[6];
        int z = num[7] * 100 + num[8] * 10 + num[9];
        if (x * b == y * a && y * c == z * b)
        {
            ans++;
            cout << x << " " << y << " " << z << endl;
        }
    } while (next_permutation(num + 1, num + 10));
    if(ans==0){
        cout<<"No!!!"<<endl;
    }
}
