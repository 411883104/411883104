/*
 * @Author: Outsider
 * @Date: 2023-01-28 22:11:08
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-30 18:29:44
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\BinarySearch\P2249.cc
 */
#include <iostream>
#include <vector>

using namespace std;
const int c = 1e6 + 5;
int arr[c];

int bs(int l, int r, int target)
{
    while (l < r)
    {
        int mid = l + ((r - l) >> 1);
        if (arr[mid] == target)
        {
            r = mid;
        }
        else if (arr[mid] > target)
        {
            r = mid;
        }
        else if (arr[mid] < target)
        {
            l = mid + 1;
        }
    }
    return arr[l] == target ? l : -1;
}

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    int target;
    while (k--)
    {
        cin >> target;
        cout << bs(1, n + 1, target) << " ";
    }
    cout << endl;
}