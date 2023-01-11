/*
 * @Author: Outsider
 * @Date: 2023-01-04 19:15:16
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-04 21:31:21
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\sort\p1152.cc
 */
#include <iostream>

using namespace std;
int arr[1005];
int n;
int cnt[1005] = {0};
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i < n; i++)
    {
        int r = abs(arr[i] - arr[i - 1]);
        if (r >= n)
        {
            cout << "Not jolly" << endl;
            return 0;
        }
        cnt[r]++;
        if (cnt[r] > 1)
        {
            cout << "Not jolly" << endl;
            return 0;
        }
    }
    cout<<"Jolly"<<endl;
}