/*
 * @Author: Outsider
 * @Date: 2023-01-07 15:14:47
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-08 17:16:50
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\sort\p1923.cc
 */
#include <iostream>

using namespace std;

int arr[5000005];

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void pivot(int left, int right)
{
    int mid = left + ((right - left) >> 1);
    if (arr[left] > arr[right])
    {
        swap(arr[left], arr[right]);
    }
    if (arr[mid] > arr[right])
    {
        swap(arr[mid], arr[right]);
    }
    if (arr[left] < arr[mid])
    {
        swap(arr[mid], arr[left]);
    }
}

int fd_k(int left, int right, int k)
{
    int s = left, e = right;
    if (s <= e)
    {
        pivot(s, e);
        int cnt = arr[s];
        while (s < e)
        {
            while (s < e && arr[e] >= cnt)
            {
                e--;
            }
            arr[s] = arr[e];
            while (s < e && arr[s] <= cnt)
            {
                s++;
            }
            arr[e] = arr[s];
        }
        arr[s] = cnt;
        if (s == k)
            return arr[k];
        if (s > k)
        {
            fd_k(left, s - 1, k);
        }
        else
        {
            fd_k(s + 1, right, k);
        }
    }
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    cout << fd_k(0, n - 1, k) << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
}