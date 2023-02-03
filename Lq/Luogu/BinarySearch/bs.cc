/*
 * @Author: Outsider
 * @Date: 2023-01-30 18:34:15
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-30 18:37:06
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\BinarySearch\bs.cc
 */
#include <iostream>
#include <vector>

using namespace std;

vector<int> nums = {2, 3, 3, 3, 3, 3, 6, 1, 3, 4, 6, 7};

int find(int left, int right, int target)
{
    while (left <= right)
    {
        int mid = left + ((right - left) >> 1);
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            right = mid - 1;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
    }
    return -1;
}
int main()
{
    cout << find(0, nums.size(), 3) << endl;
}