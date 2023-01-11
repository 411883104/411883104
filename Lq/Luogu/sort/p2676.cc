/*
 * @Author: Outsider
 * @Date: 2023-01-04 19:15:16
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-04 20:05:41
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\sort\p2676.cc
 */
#include <iostream>

using namespace std;
int arr[20005];
int n, b;

void sort()
{
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    cin >> n >> b;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort();
    int sum = 0;
    int i = 0;
    for (; i < n && sum < b; i++)
    {
        sum += arr[i];
    }
    cout << i << endl;
}