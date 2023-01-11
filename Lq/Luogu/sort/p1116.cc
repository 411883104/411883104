/*
 * @Author: Outsider
 * @Date: 2023-01-04 19:15:16
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-04 20:36:21
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\sort\p1116.cc
 */
#include <iostream>

using namespace std;
int arr[10005];
int n;
int sort()
{
    int ans = 0;
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                ans++;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return ans;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << sort() << endl;
}