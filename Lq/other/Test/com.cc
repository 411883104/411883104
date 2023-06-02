/*
 * @Author       : Outsider
 * @Date         : 2023-06-01 10:49:45
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-06-01 15:00:40
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\other\Test\com.cc
 */
#include <iostream>
#include <vector>

using namespace std;

vector<int> nums = {6, 9, 12, 15, 16, 18, 22, 100, 85, 62, 21, 17, 12, 5, 4, 3, 1};

int main()
{
    if (nums.size() == 3)
    {
        cout << nums[1] << endl;
    }
    int ll = 0, rr = nums.size();
    while (ll <= rr)
    {
        int mm = ll + ((rr - ll) >> 1);
        if (nums[mm] > nums[mm + 1] && nums[mm] > nums[mm - 1])
        {
            cout << nums[mm] << endl;
            return 0;
        }
        else if (nums[mm] < nums[mm + 1])
        {
            ll = mm + 1;
        }
        else if (nums[mm] < nums[mm - 1])
        {
            rr = mm - 1;
        }
    }
    return 0;
}