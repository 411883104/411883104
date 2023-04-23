/*
 * @Author       : Outsider
 * @Date         : 2023-03-26 18:58:27
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-03-26 20:07:07
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\other\quickSort.cc
 */
#include <iostream>
using namespace std;

// 20个数为例
int a[20] = {2, 111, 96, 12, 41, 20, 1, 3, 95, 1, 5, 6, 4, 5, 95, 15, 15, 5, 12, 21};

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

// 基准选取 - 三数取中 [left,right]
void pivot(int left, int right)
{
    int idx = left + ((right - left) >> 1);
    if (a[left] > a[right])
    {
        swap(a[left], a[right]);
    }
    if (a[idx] > a[right])
    {
        swap(a[idx], a[right]);
    }
    if (a[left] < a[idx])
    {
        swap(a[left], a[idx]);
    }
}

// quickSort - Array[left,right]
void qsort(int left, int right)
{
    int start = left, end = right;
    while (start < end)
    {
        pivot(start, end);
        int cnt = a[start];
        while (start < end)
        {
            while (end > start && a[end] >= cnt)
            {
                end--;
            }
            a[start] = a[end];
            while (start < end && a[start] <= cnt)
            {
                start++;
            }
            a[end] = a[start];
        }
        a[start] = cnt;
        qsort(left, start - 1);
        // qsort(start + 1, right);
        // 尾递归
        start++;
        left = start;
        end = right;
    }
}

int main()
{
    qsort(0, 19);
    for (int i = 0; i < 20; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}